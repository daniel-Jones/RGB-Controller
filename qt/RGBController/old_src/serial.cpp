#include "serial.h"
#include "controllerwindow.h"
serial::serial(QObject *parent) : QObject(parent)
{
	ser = new QSerialPort(this);
	connect(ser, &QSerialPort::readyRead, this, &serial::read);
	
}

bool serial::serial_connect(QString port)
{
	/* this function will attempt a ser.connection if we are not already connected */
	if (!ser->isOpen())
	{
		ser->setPortName(port);
		ser->setBaudRate(QSerialPort::Baud9600);
		ser->setDataBits(QSerialPort::Data8);
		ser->setParity(QSerialPort::NoParity);
		ser->setStopBits(QSerialPort::OneStop);
		ser->setFlowControl(QSerialPort::NoFlowControl);
		ser->open(QIODevice::ReadWrite);
		ser->waitForBytesWritten(9000);
		if (ser->isWritable()) {
			return true;
		}
	}
	return false;
}

bool serial::serial_disconnect()
{
	/* this function disconnects from the serial port if it is connected already */
	if (ser->isOpen())
	{
		ser->close();
		return true;
	}
	return false;
}

void serial::send(QString com)
{
    data = "";
    //qDebug() << com;
    data.append(com + "\n");
    if (ser->isOpen())
        ser->write(data);
}

void serial::rgb_change(int r, int g, int b)
{
    // NOT USED FUNCTION

	/* here we send our rgb values to the serial port */
	data = "";
	/* the 0 is a hack, i need to look into it at some point */
    data.append("red=" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + "\n");
	if (ser->isOpen())
		ser->write(data);
}

void serial::read()
{
	if (serdata[serdata.size() - 1] != '\n')
		serdata = serdata + ser->readAll();
	if (serdata[serdata.size() - 1] == '\n')
	{
		qDebug() << "got data" << serdata;
		parse(QString(serdata));
		serdata = "";
	}
}

void serial::parse(QString message)
{
	if (message.contains("="))
	{
		QString command = message.split("=")[0];
		QString text = message.split("=")[1];
		qDebug() << "command:" << command << "message:" << text;
		
//		win->info_log(text);
		//((controllerWindow*)(parent()))->info_log("tesT");
			
	}
}
