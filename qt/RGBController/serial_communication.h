#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

/* includes */
#include <QSerialPort>
#include <QSerialPortInfo>


class serial_communication
{
public:
    /* function declares */
    serial_communication();
    bool serial_connect(QString port);
    bool serial_disconnect();
    void rgb_change(int r, int g, int b);
    /* variables */
    QString port_name;
    QSerialPort serial;
    QByteArray data;
};

#endif // SERIAL_COMMUNICATION_H
