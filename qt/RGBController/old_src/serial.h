#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class serial : public QObject
{
	Q_OBJECT
	public:
		explicit serial(QObject *parent = 0);


		/* function declares */
		bool serial_connect(QString port);
		bool serial_disconnect();
		void rgb_change(int r, int g, int b);
		void send(QString com);
		void parse(QString message);
		/* variables */
		QString port_name;
		//QSerialPort ser;
		QSerialPort *ser;
		QByteArray data;
		QByteArray serdata;
	private slots:
		void read();
};

#endif // SERIAL_H
