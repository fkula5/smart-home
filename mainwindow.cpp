#include "mainwindow.h"
#include "tcpserver.h"
#include "ui_mainwindow.h"

#include <NewDeviceDialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStartServer_clicked()
{
    if(_server == nullptr){
        auto port = ui->spnServerPort->value();
        _server = new TCPServer(port);
        connect(_server, &TCPServer::newClientConnected, this, &MainWindow::newClientConnected);
        connect(_server, &TCPServer::dataReceived, this, &MainWindow::clientDataReceived);
        connect(_server, &TCPServer::clientDisconnect, this, &MainWindow::clientDisconnected);
    }
    auto state = (_server->isStarted()) ? "1" : "0";
    ui->lblConnectionStatus->setProperty("state", state);
    style()->polish(ui->lblConnectionStatus);
}

void MainWindow::newClientConnected()
{
    ui->lstConsole->addItem("New Client connected");
}

void MainWindow::clientDisconnected()
{
    ui->lstConsole->addItem("Client disconnected");
}

void MainWindow::clientDataReceived(QString message)
{
    ui->lstConsole->addItem(message);
    NewDeviceDialog dialog(this, message);
    if (dialog.exec() == QDialog::Accepted) {
        QString deviceName = dialog.getDeviceName();
        qDebug() << ("New device accepted: %s", qPrintable(deviceName));
    }
}


void MainWindow::on_btnTrnOn_clicked()
{
    QString message = "Light on";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnTrnOff_clicked()
{
    QString message = "Light off";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnTrnUp_clicked()
{
    QString message = "Up";
    _server->sendToDevice(message, "Roleta");
}


void MainWindow::on_btnTrnDown_clicked()
{
    QString message = "Down";
    _server->sendToDevice(message, "Roleta");
}

