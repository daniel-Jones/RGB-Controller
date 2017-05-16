#ifndef IRC_H
#define IRC_H

#include <QtNetwork/QTcpSocket>
#include <QDebug>

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
	private slots:
		void read();
		void con();
		void handle(QString str);

	signals:
		void sendcmd(QString cmd);

		public slots:
};

#endif // IRC_H
