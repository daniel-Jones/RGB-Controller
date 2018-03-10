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

#ifndef CONTROLLERWINDOW_H
#define CONTROLLERWINDOW_H

/* includes */

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
#include <QTimer>
#include "ui_controllerwindow.h"
#include "irc.h"
#include "server.h"

namespace Ui {
	class controllerWindow;
}

class controllerWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit controllerWindow(QWidget *parent = 0);
		~controllerWindow();
		/* public functions */
		void info_log(QString text);
		void populate_serial_list();
		void load_presets();
		void save_preset(QString name);
		void delete_preset(QString name);
		void serial_rgb_change(int r, int g, int b);
		void show_msgbox(QString message);
		bool serial_connect(QString port);
		bool serial_disconnect();
		void rgb_change(int r, int g, int b);
		void send(QString com);
		void parse(QString message);
		void read();
		int show_question_box(QString message, QString omessage);
		/*public variables */
		/* these three ints will hold the current value (0 - 255) of each slider */
		int r, g, b;
		/* this list will contain all the presets loaded from file */
		QStringList presets;
		/* this string will hold our selected serial port */
		QString port;
		/* this int will contain the current preset index selected */
		int preset_index;
		QString presetsfile;
		QString tempfile;
		QString port_name;
		QSerialPort *ser;
		QByteArray data;
		QByteArray serdata;
		QTimer *ptimer;
		bool tping;
		int pingtries;
		public slots:
			void cmdrecv(QString cmd);
		private slots:
			/* these slots are used to trigger button clicks and drop down items selections etc */
			void on_connect_button_clicked();

		void on_disconnect_button_clicked();

		void on_refresh_port_button_clicked();

		void on_reload_preset_button_clicked();

		void on_r_slider_valueChanged(int value);

		void on_g_slider_valueChanged(int value);

		void on_b_slider_valueChanged(int value);

		void on_red_button_clicked();

		void on_green_button_clicked();

		void on_blue_button_clicked();

		void on_off_button_clicked();

		void on_set_preset_button_clicked();

		void on_presets_dropdown_currentIndexChanged(int index);

		void on_preset_save_button_clicked();

		void on_preset_delete_button_clicked();

		void on_red_fade_button_clicked();

		void on_green_fade_button_clicked();

		void on_blue_fade_button_clicked();

		void on_speed_button_clicked();

		void on_r_speed_slider_valueChanged(int value);

		void on_g_speed_slider_valueChanged(int value);

		void on_b_speed_slider_valueChanged(int value);

		void on_rfrom_valueChanged(int arg1);

		void on_rto_valueChanged(int arg1);

		void on_gfrom_valueChanged(int arg1);

		void on_gto_valueChanged(int arg1);

		void on_bfrom_valueChanged(int arg1);

		void on_bto_valueChanged(int arg1);

		void on_serial_send_button_clicked();
		void ping();
		void check_ping();

		void on_irc_connect_button_clicked();

		void on_server_start_button_clicked();


	private:
		Ui::controllerWindow *ui;
		bool irccon;
		irc ircbot;
		server srv;
		int pingcount;
		bool server_started;
};

#endif // CONTROLLERWINDOW_H
