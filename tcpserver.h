#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TCPServer : public QObject
{
    Q_OBJECT
private:
    QTcpServer *_server;
    QList<QTcpSocket *> _socketList;
    bool _isStarted;
    QString device;
    struct ClientInfo {
        QTcpSocket *socket;
        QString deviceType;
        QString deviceName;
    };
    QList<ClientInfo> _clients;
public:
    explicit TCPServer(int port, QObject *parent = nullptr);
    bool isStarted() const;
    void sendToDevice(QString message, QString deviceType);
signals:
    void newClientConnected();
    void clientDisconnect(QString device);
    void dataReceived(QString message, ClientInfo &client);
private slots:
    void on_client_connecting();
    void clientDisconnected();
    void clientData();
};

#endif // TCPSERVER_H
