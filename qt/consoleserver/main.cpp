#include <QCoreApplication>
#include <QObject>
#include "serial.h"
#include "server.h"
#include "irc.h"

void worker(QString arg1);

serial ser;
server srv;
irc ircbot;

int main(int argc, char *argv[]) 
{
	QCoreApplication a(argc, argv);
	if (argc > 1)
		worker(argv[1]);
	else 
		worker("none");
	return a.exec();
}

void worker(QString arg1)
{
	srv.server_start();
	ser.start(arg1); 
	ircbot.setup("irc.danieljon.es", 6667, "#csgo", "LightBot");
	QObject::connect(&srv, SIGNAL(sendcmd(QString)), &ser, SLOT(send(QString)));
	QObject::connect(&ircbot, SIGNAL(sendcmd(QString)), &ser, SLOT(send(QString)));
}
