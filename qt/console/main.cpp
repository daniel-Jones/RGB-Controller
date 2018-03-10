/*
 * Copyright Daniel Jones 2016-2018
 *
 * This file is part of RGBController.
 *
 * RGBController is free software: you can redistribute it and/or modifiy
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RGBController is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGBController.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QCoreApplication>
#include <QDebug>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>
#include <QThread>

void show_ports();
bool serial_connect(QString port);
bool serial_disconnect();
void send(QString com);
void check();
QString port_name;
QSerialPort serial;
QByteArray data;
QSerialPortInfo s;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	if (argc < 2)
	{
		qDebug() << QString("Usage: %1 [port] [commands]").arg(argv[0]);
		qDebug() << "Available serial ports.";
		show_ports();
		return 0;
	}
	else 
	{
		if (serial_connect(QString(argv[1])))
		{
			for (int x = 0; x < argc - 2; x++)
			{
				send(QString(argv[x + 2]));
			}
			QTimer::singleShot(100, check);
		}
		else
		{
			qDebug() << "Port in use.";
		}
	}
	return 0;
}

void check()
{
	if (s.isBusy())
		qDebug() << "An error occured.";
	QCoreApplication::quit();
}

void show_ports()
{
	for (int x = 0; x < QSerialPortInfo::availablePorts().size(); x++)
	{
		if (!s.availablePorts().at(x).description().isEmpty())
			qDebug() << QString("Port: %1").arg(QSerialPortInfo::availablePorts().at(x).portName());
	}
}

bool serial_connect(QString port)
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

	QThread::sleep(1);
		if (serial.isWritable()) {
			return true;
		}
	}
	return false;
}

bool serial_disconnect()
{
	/* this function disconnects from the serial port if it is connected already */
	if (serial.isOpen())
	{
		serial.close();
		return true;
	}
	return false;
}

void send(QString com)
{
    data = "";
    data.append(com + "\n");
    qDebug() << "sending:" << data;
    if (serial.isOpen())
    {
        serial.write(data);
    }
    else
	qDebug() << "Cannot send, device not open.";
}

