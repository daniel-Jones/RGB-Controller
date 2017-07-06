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
		void sendcmd(QString);


		public slots:
};

#endif // SERVER_H
