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

#include "irc.h"

irc::irc(QObject *parent) : QObject(parent)
{
	qDebug() << "irc loaded but not started"; 
}

void irc::setup(QString srv, int p, QString c, QString n)
{
	qDebug() << "irc started";
	server = srv;
	port = p;
	channel = c;
	name = n;
	/* setup socket, connect signal/slot */
	socket = new QTcpSocket(this);
	connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
	pingcheck = new QTimer(this);
	connect(pingcheck, SIGNAL(timeout()), this, SLOT(pingcheckfunc()));
	/* connect */
	con();
}

void irc::read()
{
	QString line = socket->readLine();
	if (line.contains("PING :"))
	{
		pinged = true;
		QString sline = "PONG :" + line.split(":")[1];
		socket->write(sline.toLatin1());
	}
	QString tmp = name + " MODE " + name + " :+";
	if (line.contains(tmp))
	{
		buf = "JOIN " + channel + "\r\n";
		socket->write(buf.toUtf8());
	}
	if (line.contains("!")) /* most likely a message to handle */
		handle(line);
	if(socket->canReadLine())
		read();
}

void irc::con()
{
	pinged = false;
	socket->connectToHost(server, port);
	buf = "NICK " + name + "\r\n";
	socket->write(buf.toUtf8());
	buf = "USER " + name + " 8 * :" + name + "\r\n";
	socket->write(buf.toUtf8());
	pingcheck->start(300000);
}

void irc::discon()
{
	socket->write("QUIT :elegant quit \r\n");
	socket->close();
	pingcheck->stop();
}

void irc::handle(QString str)
{
	/* :Scruffy!Scruff@i.am.huskehhh.com PRIVMSG #csgo :You a vim faggot? */
	if (str.contains("PRIVMSG"))
	{

		QString usr = str.split("!")[0].replace(":", "");
		QString msg = str.split("PRIVMSG")[1].split(":")[1];
		if (usr == "daniel_j")
		{
			if (msg.contains("!send"))
			{
				
				msg.remove(QRegExp("[\\n\\t\\r]"));
				msg.replace("!send ", "");
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
		}
	}
}

void irc::sendmsg(QString msg)
{
	buf = "PRIVMSG " + channel + " :" + msg + " \r\n";
	socket->write(buf.toUtf8());
}

void irc::pingcheckfunc()
{
	if (pinged)
	{
		pinged = false;
	}
	else
	{
		qDebug() << "reconnection needed";
		name = name + "_";
		discon();
		con();
	}
}
