#include "tcpserver.h"

TCPServer::TCPServer(int port, QObject *parent) : QObject{parent}
{
    _server = new QTcpServer(this);
    connect(_server, &QTcpServer::newConnection, this, &TCPServer::on_client_connecting);
    _isStarted = _server->listen(QHostAddress::Any, port);
    if(!_isStarted){
        qDebug() << "Server could not start";
    }else{
        qDebug() << "Server started...";
    }
}

void TCPServer::on_client_connecting(){
    qDebug() << "a client connected to server";
    auto socket = _server->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &TCPServer::clientData);
    connect(socket, &QTcpSocket::disconnected, this, &TCPServer::clientDisconnected);
    _socketList.append(socket);
    socket->write("Welcome to this server");
    emit newClientConnected();
}

void TCPServer::clientData(){
    auto socket = qobject_cast<QTcpSocket *>(sender());
    auto data = socket->readAll();
    emit dataReceived(QString(data));
}

void TCPServer::clientDisconnected(){
    emit clientDisconnect(device);
}

bool TCPServer::isStarted() const
{
    return _isStarted;
}
