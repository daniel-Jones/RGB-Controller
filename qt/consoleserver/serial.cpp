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

#include "serial.h"
#include <QThread>

serial::serial()
{
	qDebug() << "serial loaded but not started";
}

void serial::start(QString port)
{
	qDebug() << "serial started";
	if (port != "none")
	{
		qDebug() << "using port" << port;
		if (!connect(port))
		{
			qDebug() << "fatal error connecting to the serial port";
			qDebug() << "not bothering to continue";
			exit(1);
		}
	}
	else
	{
		qDebug() << "you need to provide a serial port as an argument.";
		qDebug() << "available ports:";
		show_ports();
		qDebug() << "quitting because there is no point continuing";
		exit(1);
	}
}

void serial::show_ports()
{
	for (int x = 0; x < QSerialPortInfo::availablePorts().size(); x++)
	{
		if (!s.availablePorts().at(x).description().isEmpty())
			qDebug() << QString("%1").arg(QSerialPortInfo::availablePorts().at(x).portName());
	}
}

bool serial::connect(QString port)
{
	if (!ser.isOpen())
	{
		ser.setPortName(port);
		ser.setBaudRate(QSerialPort::Baud9600);
		ser.setDataBits(QSerialPort::Data8);
		ser.setParity(QSerialPort::NoParity);
		ser.setStopBits(QSerialPort::OneStop);
		ser.setFlowControl(QSerialPort::NoFlowControl);
		ser.open(QIODevice::ReadWrite);
		ser.waitForBytesWritten(9000);
		if (ser.isWritable()) {
			qDebug() << "serial connected";
			return true;
		}
	}
	return false;
}

void serial::send(QString com)
{
	data = "";
	data.append(com + "\n");
	if (ser.isOpen())
		ser.write(data);
}
