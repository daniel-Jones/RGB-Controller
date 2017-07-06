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
