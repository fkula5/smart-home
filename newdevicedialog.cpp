#include "NewDeviceDialog.h"

NewDeviceDialog::NewDeviceDialog(QWidget *parent, QString deviceType) : QDialog(parent), deviceName("") {
    label = new QLabel("Enter the " + deviceType + " name:", this);
    lineEdit = new QLineEdit(this);
    acceptButton = new QPushButton("Accept", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(acceptButton);

    setLayout(layout);
    setWindowTitle("New Device");
    setModal(true);

    connect(acceptButton, &QPushButton::clicked, this, &NewDeviceDialog::onAcceptClicked);
}

QString NewDeviceDialog::getDeviceName() const {
    return deviceName;
}

void NewDeviceDialog::onAcceptClicked() {
    deviceName = lineEdit->text();
    accept();
}
