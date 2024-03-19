#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(int port, QObject *parent = nullptr);
    bool isStarted() const;
signals:
    void newClientConnected();

private slots:
    void on_client_connecting();

private:
    QTcpServer *_server;
    QList<QTcpSocket *> _socketList;
    bool _isStarted;
};

#endif // TCPSERVER_H
