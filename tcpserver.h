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
    void clientDisconnect(QString device);
    void dataReceived(QString message);
private slots:
    void on_client_connecting();
    void clientDisconnected();
    void clientData();
private:
    QTcpServer *_server;
    QList<QTcpSocket *> _socketList;
    bool _isStarted;
    QString device;
};

#endif // TCPSERVER_H
