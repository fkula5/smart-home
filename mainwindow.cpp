#include "LampWidget.h"
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
    ui->Lamp->hide();
    ui->Shade->hide();
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

void MainWindow::clientDisconnected(QString device)
{
    ui->lstConsole->addItem(device);
    if(device == "Lampa"){
        ui->Lamp->hide();
    }
    if(device == "Roleta"){
        ui->Shade->hide();
    }
}

void MainWindow::clientDataReceived(QString message)
{
    ui->lstConsole->addItem(message);
    NewDeviceDialog dialog(this, message);
    if (dialog.exec() == QDialog::Accepted) {
        QString deviceName = dialog.getDeviceName();
        if(message == "Lampa"){
            ui->Lamp->show();
            ui->Lamp->setTitle(deviceName);
        }
        if(message == "Roleta"){
            ui->Shade->show();
            ui->Shade->setTitle(deviceName);
        }
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


void MainWindow::on_btnGreen_clicked()
{
    QString message = "Green";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnYellow_clicked()
{
    QString message = "Yellow";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnRed_clicked()
{
    QString message = "Red";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnBlue_clicked()
{
    QString message = "Blue";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnWhite_clicked()
{
    QString message = "White";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnBright25_clicked()
{
    QString message = "25";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnBright50_clicked()
{
    QString message = "50";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnBright75_clicked()
{
    QString message = "75";
    _server->sendToDevice(message, "Lampa");
}


void MainWindow::on_btnBright100_clicked()
{
    QString message = "100";
    _server->sendToDevice(message, "Lampa");
}

