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
