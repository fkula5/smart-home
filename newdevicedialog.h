#ifndef NEWDEVICEDIALOG_H
#define NEWDEVICEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class NewDeviceDialog : public QDialog {
    Q_OBJECT

public:
    explicit NewDeviceDialog(QWidget *parent = nullptr, QString deviceType = "");

    QString getDeviceName() const;

private slots:
    void onAcceptClicked();

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *acceptButton;
    QString deviceName;
};

#endif // NEWDEVICEDIALOG_H
