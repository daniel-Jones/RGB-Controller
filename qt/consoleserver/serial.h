#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


class serial : public QObject
{
    Q_OBJECT
public:
    serial();
    void start(QString port);
    public slots:
	    void send(QString com);
private:
    bool connect(QString port);
    void show_ports();
    QSerialPort ser;
    QSerialPortInfo s;
    QByteArray serdata;
    QByteArray data;
};

#endif // SERIAL_H
