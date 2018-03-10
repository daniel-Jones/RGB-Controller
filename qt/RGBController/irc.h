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

#ifndef IRC_H
#define IRC_H

#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <QTimer>

class irc : public QObject
{
	Q_OBJECT
	public:
		explicit irc(QObject *parent = 0);
		void setup(QString srv, int p, QString c, QString n);
		void discon();
		void sendmsg(QString msg);
	private:
		QTcpSocket *socket;
		QString server;
		int port;
		QString channel;
		QString name;
		QString buf;
		bool pinged;
		QTimer *pingcheck;

	private slots:
		void read();
		void con();
		void handle(QString str);
		void pingcheckfunc();

	signals:
		void sendcmd(QString cmd);

		public slots:
};

#endif // IRC_H
