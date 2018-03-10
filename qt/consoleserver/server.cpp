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

#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
	srv = new QTcpServer();
	connect(srv, SIGNAL(newConnection()), this, SLOT(new_connection()));
	qDebug() << "server loaded but not started";
}

bool server::server_start()
{
	qDebug() << "server started";
	if (srv->listen(QHostAddress::Any, 3001))
	{
		qDebug() << "listening on 3001"; 
		return true;
	}
	else
	{
		return false;
	}
}

bool server::server_stop()
{
	srv->close();
	if (srv->isListening())
		return false;
	return true;
}

void server::new_connection()
{
	QTcpSocket *socket;
	socket = srv->nextPendingConnection();
	socket->waitForReadyRead(3000);
	handle(QString(socket->readAll()).remove(QRegExp("[\\n\\t\\r]")));
	socket->close();
	delete socket;
}

void server::handle(QString msg)
{
	qDebug() << "received" << msg;
	if (msg.contains(";"))
	{
		QStringList tmp = msg.split(";");
		for (int x = 0; x < tmp.size(); x++)
		{
			emit sendcmd(tmp.at(x));
		}
	}
	else
	{
		emit sendcmd(msg);
	}
}
