#include "qtbot.h"

QtBot::QtBot(QObject *parent) : QObject(parent)
{

}

void QtBot::setup()
{
	qDebug() << "setup()";
	/* setup socket, connect signal/slot */
	socket = new QTcpSocket(this);
	connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
	/* connect */
	bconnect();
	/* serial connect */
	ser = new QSerialPort(this);
	ser->setPortName("ttyACM0");
	ser->setBaudRate(QSerialPort::Baud9600);
	ser->setDataBits(QSerialPort::Data8);
	ser->setParity(QSerialPort::NoParity);
	ser->setStopBits(QSerialPort::OneStop);
	ser->setFlowControl(QSerialPort::NoFlowControl);
	ser->open(QIODevice::ReadWrite);
	ser->waitForBytesWritten(9000);
	if (ser->isWritable())
	{
		qDebug() << "Writable serial";
	}
}

void QtBot::send(QString com)
{
	data = "";
	qDebug() << "sending" << com;
	data.append(com + "\n");
	if (ser->isOpen())
		ser->write(data);
}

void QtBot::read()
{
	QString line = socket->readLine();
	if (line.contains("PING :"))
	{
		QString sline = "PONG :" + line.split(":")[1];
		socket->write(sline.toLatin1());
	}
	if (line.contains("qtbot MODE qtbot :+"))
	{
		socket->write("JOIN #bukkake \r\n");
		socket->write("JOIN #fun \r\n");
	}
	if (line.contains("!"))
		parse(line);
	if(socket->canReadLine())
		read();
}

void QtBot::bconnect()
{
	socket->connectToHost(server, port);	
	socket->write("NICK qtbot \r\n");
	socket->write("USER qtbot 8 * :qtbot \r\n");
}

void QtBot::parse(QString line)
{
	QString l = line.split(":")[2].remove(QRegExp("[\\n\\t\\r]"));
	qDebug() << "parsing: " << l;
	if (l.split(" ")[0] == ".command")
	{
		if (l.split(" ")[1].size() > 2)
		{
			QString sendl = "PRIVMSG #tests :red set. \r\n";
			QString command = l.split(" ")[1];
			qDebug() << "command is " << command;
			send(command);
			//socket->write(send.toLocal8Bit());
		}	
	}
}
