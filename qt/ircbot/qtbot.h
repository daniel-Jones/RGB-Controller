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

#ifndef QTBOT_H
#define QTBOT_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QSerialPort>
#include <QSerialPortInfo>

class QtBot : public QObject
{
	Q_OBJECT
	public:
		explicit QtBot(QObject *parent = 0);
		QString server = "irc.danieljon.es";
		int port = 6667;
		QString name = "RGBBot";
		QSerialPort *ser;
		QByteArray data;
		QByteArray serdata;

	private:
		QTcpSocket *socket;
		private slots:
			void read();
		void bconnect();
		void parse(QString line);
		void send(QString com);

signals:
		void done();

		public slots:
			void setup();
};

#endif // QTBOT_H
