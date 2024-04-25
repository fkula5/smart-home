#include "LampWidget.h"

LampWidget::LampWidget(const QString& deviceName, const QString& deviceType, QWidget *parent)
    : QWidget(parent) {
    // Initialize labels
    labelName = new QLabel("Device Name: " + deviceName, this);
    labelType = new QLabel("Device Type: " + deviceType, this);

    // Initialize on/off buttons
    buttonOn = new QPushButton("On", this);
    buttonOff = new QPushButton("Off", this);
    connect(buttonOn, &QPushButton::clicked, this, &LampWidget::turnLampOn);
    connect(buttonOff, &QPushButton::clicked, this, &LampWidget::turnLampOff);

    // Brightness controls
    groupBoxBrightness = new QGroupBox("Brightness Settings", this);
    QHBoxLayout *hboxBrightness = new QHBoxLayout(groupBoxBrightness);
    QStringList brightnessLevels = {"0", "25", "50", "75", "100"};
    foreach (const QString &level, brightnessLevels) {
        QPushButton *button = new QPushButton(level + "%", groupBoxBrightness);
        hboxBrightness->addWidget(button);
        connect(button, &QPushButton::clicked, [this, level]() {
            setBrightness(level.toInt());
        });
    }

    // Main layout
    layoutMain = new QVBoxLayout(this);
    layoutMain->addWidget(labelName);
    layoutMain->addWidget(labelType);
    layoutMain->addWidget(buttonOn);
    layoutMain->addWidget(buttonOff);
    layoutMain->addWidget(groupBoxBrightness);
    setLayout(layoutMain);
}

void LampWidget::turnLampOn() {
    emit commandIssued("Lamp on");
}

void LampWidget::turnLampOff() {
    emit commandIssued("Lamp off");
}

void LampWidget::setBrightness(int brightness) {
    emit commandIssued(QString::number(brightness));
}
