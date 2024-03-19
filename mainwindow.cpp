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
        connect(_server, &TCPServer::newClientConnected, this, &MainWindow::on_newClient_connected);
    }
}

