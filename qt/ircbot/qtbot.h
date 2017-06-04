#ifndef QTBOT_H
#define QTBOT_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QSerialPort>
#include <QSerialPortInfo>

class QtBot : public QObject
{
	Q_OBJECT
	public:
		explicit QtBot(QObject *parent = 0);
		QString server = "irc.danieljon.es";
		int port = 6667;
		QString name = "RGBBot";
		QSerialPort *ser;
		QByteArray data;
		QByteArray serdata;

	private:
		QTcpSocket *socket;
		private slots:
			void read();
		void bconnect();
		void parse(QString line);
		void send(QString com);

signals:
		void done();

		public slots:
			void setup();
};

#endif // QTBOT_H
