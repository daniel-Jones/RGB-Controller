#include "serial_communication.h"
#include "controllerwindow.h"

serial_communication::serial_communication()
{
	qDebug() << "serial test";
}

bool serial_communication::serial_connect(QString port)
{
	/* this function will attempt a serial connection if we are not already connected */
	if (!serial.isOpen())
	{
		serial.setPortName(port);
		serial.setBaudRate(QSerialPort::Baud9600);
		serial.setDataBits(QSerialPort::Data8);
		serial.setParity(QSerialPort::NoParity);
		serial.setStopBits(QSerialPort::OneStop);
		serial.setFlowControl(QSerialPort::NoFlowControl);
		serial.open(QIODevice::ReadWrite);
		serial.waitForBytesWritten(9000);
		if (serial.isWritable()) {
			return true;
		}
	}
	return false;
}

bool serial_communication::serial_disconnect()
{
	/* this function disconnects from the serial port if it is connected already */
	if (serial.isOpen())
	{
		serial.close();
		return true;
	}
	return false;
}

void serial_communication::send(QString com)
{
    data = "";
    //qDebug() << com;
    data.append(com + "\n");
    if (serial.isOpen())
        serial.write(data);
}

void serial_communication::rgb_change(int r, int g, int b)
{
    // NOT USED FUNCTION

	/* here we send our rgb values to the serial port */
	data = "";
	/* the 0 is a hack, i need to look into it at some point */
    data.append("red=" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + "\n");
	if (serial.isOpen())
		serial.write(data);
}

void serial_communication::read()
{
	qDebug() << "serial read";
}
