#ifndef LAMPWIDGET_H
#define LAMPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class LampWidget : public QWidget {
    Q_OBJECT

public:
    explicit LampWidget(const QString& deviceName, const QString& deviceType, QWidget *parent = nullptr);

signals:
    void commandIssued(const QString &command);

private slots:
    void turnLampOn();
    void turnLampOff();
    void setBrightness(int brightness);

private:
    QLabel *labelName;
    QLabel *labelType;
    QPushButton *buttonOn;
    QPushButton *buttonOff;
    QGroupBox *groupBoxBrightness;
    QVBoxLayout *layoutMain;
};

#endif // LAMPWIDGET_H
