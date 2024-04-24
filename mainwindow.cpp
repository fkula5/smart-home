#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

