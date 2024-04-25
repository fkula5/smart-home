#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStyle>
#include "qgridlayout.h"
#include "tcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStartServer_clicked();

    void newClientConnected();

    void clientDisconnected(QString device);

    void clientDataReceived(QString message);

    void on_btnTrnOn_clicked();

    void on_btnTrnOff_clicked();

    void on_btnTrnUp_clicked();

    void on_btnTrnDown_clicked();

    void on_btnGreen_clicked();

    void on_btnYellow_clicked();

    void on_btnRed_clicked();

    void on_btnBlue_clicked();

    void on_btnWhite_clicked();

    void on_btnBright25_clicked();

    void on_btnBright50_clicked();

    void on_btnBright75_clicked();

    void on_btnBright100_clicked();

private:
    Ui::MainWindow *ui;
    TCPServer *_server;
    QGridLayout *gridLayout;
};
#endif // MAINWINDOW_H
