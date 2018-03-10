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

#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class server : public QObject
{
	Q_OBJECT
	public:
		explicit server(QObject *parent = 0);
		bool server_start();
		bool server_stop();
	private:
		QTcpServer *srv;
		void handle(QString msg);
		private slots:
			void new_connection();
signals:
		void sendcmd(QString cmd);


		public slots:
};

#endif // SERVER_H
