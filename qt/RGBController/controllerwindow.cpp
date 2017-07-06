#include "controllerwindow.h" 

controllerWindow::controllerWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::controllerWindow)
{
	/* this is our setup function, we set things up here */
	ui->setupUi(this);
	info_log("RGB Controller started");
	/* serial */
	ser = new QSerialPort(this);
	connect(ser, &QSerialPort::readyRead, this, &controllerWindow::read);
	ptimer = new QTimer(this);
	connect(ptimer, SIGNAL(timeout()), this, SLOT(ping()));
	connect(&ircbot, SIGNAL(sendcmd(QString)), this, SLOT(cmdrecv(QString)));
	connect(&srv, SIGNAL(sendcmd(QString)), this, SLOT(cmdrecv(QString))); 
	pingtries = 0;
	irccon = false;
	pingcount = 0;
	server_started = false;
	/* disable buttons and widgets that should not be enabled yet, set slider values to 0 */
	ui->disconnect_button->setEnabled(false);
	ui->connect_button->setEnabled(false);
	ui->red_button->setEnabled(false);
	ui->green_button->setEnabled(false);
	ui->blue_button->setEnabled(false);
	ui->off_button->setEnabled(false);
	ui->reload_preset_button->setEnabled(false);
	ui->set_preset_button->setEnabled(false);
	ui->preset_save_button->setEnabled(false);
	ui->preset_delete_button->setEnabled(false);
	ui->preset_name_textbox->setEnabled(false);
	ui->presets_dropdown->setEnabled(false);
	ui->r_slider->setEnabled(false);
	ui->g_slider->setEnabled(false);
	ui->b_slider->setEnabled(false);
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(0);
	ui->red_fade_button->setEnabled(false);
	ui->green_fade_button->setEnabled(false);
	ui->blue_fade_button->setEnabled(false);
	ui->speed_button->setEnabled(false);
	ui->rfrom->setEnabled(false);
	ui->rto->setEnabled(false);
	ui->gfrom->setEnabled(false);
	ui->gto->setEnabled(false);
	ui->bfrom->setEnabled(false);
	ui->bto->setEnabled(false);
	ui->r_speed_slider->setEnabled(false);
	ui->g_speed_slider->setEnabled(false);
	ui->b_speed_slider->setEnabled(false);
	ui->speed_slider->setEnabled(false);
	ui->r_speed_slider->setValue(0);
	ui->g_speed_slider->setValue(0);
	ui->b_speed_slider->setValue(0);
	ui->speed_slider->setValue(0);
	presetsfile = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/presets.txt";
	tempfile = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/tmp.file";
	/* set some crucial ints */
	preset_index = 0, r = 0, g = 0, b = 0;
	/* populate our serial port dropdown box */
	populate_serial_list();
	/* load our presets file */
	load_presets();
}

controllerWindow::~controllerWindow()
{
	/* this function will end our program and clean up */
	delete ui;
}

void controllerWindow::info_log(QString text)
{
	/* this function is used to append logging information to our text area */
	ui->info_log_textarea->append(text);
}

void controllerWindow::populate_serial_list()
{
	/*
	 * things to be done here:
	 * - clear anything inside our serial dropdown box
	 * - re-populate the serial dropdown box
	 */

	/* remove anything in the list */
	ui->arduino_port_dropdown->clear();
	/* populate the list */
	for (int x = 0; x < QSerialPortInfo::availablePorts().size(); x++)
	{
		if (!QSerialPortInfo::availablePorts().at(x).description().isEmpty())
			ui->arduino_port_dropdown->addItem(QSerialPortInfo::availablePorts().at(x).portName());
	}
	if (!ui->arduino_port_dropdown->itemText(0).isEmpty())
	{
		ui->connect_button->setEnabled(true);
		info_log("Serial port list populated");
	} else
	{
		info_log("No serial port found!");
		ui->arduino_port_dropdown->addItem("None");
	}
}

void controllerWindow::load_presets()
{
	/*
	 * this function will load presets from file and put them into a drop down box
	 * How i plan for it to work:
	 * -> load file
	 * -> parse line by line
	 * -> split line at delimeter
	 * -> add [0] to dropdown (name), add [1] to an array that stores all the values
	 */

	QFile inputFile(presetsfile);
	if (inputFile.open(QIODevice::ReadOnly))
	{
		QTextStream in(&inputFile);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			if (line.contains("="))
			{
				ui->presets_dropdown->addItem(line.split("=")[0]);
				presets.append(line.split("=")[1]);
			}
		}
		inputFile.close();
		info_log("Presets loaded");
	} else
	{
		show_msgbox("Unable to load the presets file.\n");
		info_log("Presets file not found.");
	}
}

void controllerWindow::save_preset(QString name)
{
	/* this function will save our preset to file */
	if (!QDir("Folder").exists())
		QDir().mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
	QFile file(presetsfile);
	if(!file.open(QIODevice::Append)) {
		show_msgbox("Fatal error opening presets for appending text.");

	} else
	{
		QTextStream stream(&file);
		stream << name << "=" << ui->r_slider->value() << "," << ui->g_slider->value() << "," << ui->b_slider->value() << endl;
		file.close();
		info_log("Saved preset: " + name);
		/* things to fix the presets list */
		ui->presets_dropdown->clear();
		presets.clear();
		preset_index = 0;
		load_presets();
	}
}

void controllerWindow::delete_preset(QString name)
{
	/*
	 * here we will delete a preset from the presets file
	 * process:
	 * retrieve preset name
	 * go through preset file line by line and write it to a seperate tmp file
	 * if the [0] of split('=') equals the preset name, don't write it to the tmp file
	 * delete the old preset file
	 * rename the tmp file to presets.txt
	 */
	int ret = show_question_box("Are you sure want to delete this preset?", "This process cannot be reverted.");
	switch (ret) 
	{
		case QMessageBox::Ok:
			{
				info_log("deleting preset: " + name);
				QFile file(tempfile);
				if(!file.open(QIODevice::Append)) {
					show_msgbox("Fatal error opening temp file for writing");

				} else
				{
					QTextStream stream(&file);
					//stream << "test tmp file" << endl;
					for (int x = 0; x < ui->presets_dropdown->count(); x++)
					{
						if(name != ui->presets_dropdown->itemText(x))
						{
							stream << ui->presets_dropdown->itemText(x) << "=" << presets.at(x) << endl;
						}
					}
					file.close();
					/* remove the current presets file then rename the temp file to presets.txt */
					QFile::remove(presetsfile);
					QFile::rename(tempfile, presetsfile);
					/* reload presets into memory and clear the drop down box */
					ui->presets_dropdown->clear();
					presets.clear();
					preset_index = 0;
					load_presets();
					break;
				}
			}
		case QMessageBox::Cancel:
			show_msgbox("Preset was not deleted.");
			break;
		default:
			info_log("Unknown response received.");
			break;
	}


}

void controllerWindow::serial_rgb_change(int r, int g, int b)
{
	/* un used function */
	rgb_change(r, g, b);
}

void controllerWindow::show_msgbox(QString message)
{
	/* show message box to the user */
	QMessageBox msgbox;
	msgbox.setText(message);
	msgbox.exec();
}

int controllerWindow::show_question_box(QString message, QString omessage)
{
	QMessageBox qbox;
	qbox.setText(message);
	qbox.setInformativeText(omessage);
	qbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	qbox.setDefaultButton(QMessageBox::Cancel);
	return qbox.exec();
}

/*
 *
 * button and widget functions below
 *
 */

void controllerWindow::on_connect_button_clicked()
{
	/*
	 * here we need to call our serial port connect function
	 * if our connection is sucessful we need to enable and disable a few buttons and widgets
	 * we must also change our rgb sliders etc
	 */
	pingtries = 0;
	port = ui->arduino_port_dropdown->currentText();
	if (serial_connect(port))
	{ // if true we are connected
		info_log("Connection established");
		ui->arduino_status_label->setText("<font color=green>Connected</font>");
		/* now we need to disabled and enable some buttons and objects */
		ui->disconnect_button->setEnabled(true);
		ui->connect_button->setEnabled(false);
		ui->red_button->setEnabled(true);
		ui->green_button->setEnabled(true);
		ui->blue_button->setEnabled(true);
		ui->off_button->setEnabled(true);
		ui->reload_preset_button->setEnabled(true);
		ui->set_preset_button->setEnabled(true);
		ui->preset_save_button->setEnabled(true);
		ui->preset_delete_button->setEnabled(true);
		ui->preset_name_textbox->setEnabled(true);
		ui->presets_dropdown->setEnabled(true);
		ui->r_slider->setEnabled(true);
		ui->g_slider->setEnabled(true);
		ui->b_slider->setEnabled(true);
		ui->refresh_port_button->setEnabled(false);
		ui->arduino_port_dropdown->setEnabled(false);
		ui->red_fade_button->setEnabled(true);
		ui->green_fade_button->setEnabled(true);
		ui->blue_fade_button->setEnabled(true);
		ui->speed_button->setEnabled(true);
		ui->rfrom->setEnabled(true);
		ui->rto->setEnabled(true);
		ui->gfrom->setEnabled(true);
		ui->gto->setEnabled(true);
		ui->bfrom->setEnabled(true);
		ui->bto->setEnabled(true);
		ui->r_speed_slider->setEnabled(true);
		ui->g_speed_slider->setEnabled(true);
		ui->b_speed_slider->setEnabled(true);
		ui->speed_slider->setEnabled(true);
		ptimer->start(60000);
	} else
	{
		info_log("Unable to connect (port in use?)");
	}

}

void controllerWindow::on_disconnect_button_clicked()
{
	/*
	 * here we will attempt to disconnect from our serial port
	 * we will also enable/disable some buttons and widgets and set slider values to 0
	 */
	if (serial_disconnect())
	{
		info_log("Disconnected from serial port");
		ui->arduino_status_label->setText("<font color=red>Disconnected</font>");
		ui->disconnect_button->setEnabled(false);
		ui->connect_button->setEnabled(true);
		ui->red_button->setEnabled(false);
		ui->green_button->setEnabled(false);
		ui->blue_button->setEnabled(false);
		ui->off_button->setEnabled(false);
		ui->reload_preset_button->setEnabled(false);
		ui->preset_save_button->setEnabled(false);
		ui->preset_delete_button->setEnabled(false);
		ui->preset_name_textbox->setEnabled(false);
		ui->set_preset_button->setEnabled(false);
		ui->presets_dropdown->setEnabled(false);
		ui->refresh_port_button->setEnabled(true);
		ui->arduino_port_dropdown->setEnabled(true);
		ui->r_slider->setEnabled(false);
		ui->g_slider->setEnabled(false);
		ui->b_slider->setEnabled(false);
		ui->r_slider->setValue(0);
		ui->g_slider->setValue(0);
		ui->b_slider->setValue(0);
		ui->red_fade_button->setEnabled(false);
		ui->green_fade_button->setEnabled(false);
		ui->blue_fade_button->setEnabled(false);
		ui->speed_button->setEnabled(false);
		ui->rfrom->setEnabled(false);
		ui->rto->setEnabled(false);
		ui->gfrom->setEnabled(false);
		ui->gto->setEnabled(false);
		ui->bfrom->setEnabled(false);
		ui->bto->setEnabled(false);
		ui->r_speed_slider->setEnabled(false);
		ui->g_speed_slider->setEnabled(false);
		ui->b_speed_slider->setEnabled(false);
		ui->speed_slider->setEnabled(false);
		ui->r_speed_slider->setValue(0);
		ui->g_speed_slider->setValue(0);
		ui->b_speed_slider->setValue(0);
		ui->speed_slider->setValue(0);
	} else
	{
		/* I have no clue how we'd get here */
		info_log("Cannot disconnect");
	}
}

void controllerWindow::on_refresh_port_button_clicked()
{
	populate_serial_list();
}

void controllerWindow::on_reload_preset_button_clicked()
{
	ui->presets_dropdown->clear();
	presets.clear();
	preset_index = 0;
	load_presets();
}

void controllerWindow::on_r_slider_valueChanged(int value)
{
	r = value;
	//serial_rgb_change(r, g, b);
	send("red=" + QString::number(r));
}

void controllerWindow::on_g_slider_valueChanged(int value)
{
	g = value;
	//serial_rgb_change(r, g, b);
	send("green=" + QString::number(g));
}

void controllerWindow::on_b_slider_valueChanged(int value)
{
	b = value;
	//serial_rgb_change(r, g, b);
	send("blue=" + QString::number(b));
}

void controllerWindow::on_red_button_clicked()
{
	ui->r_slider->setValue(255);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(0);
}

void controllerWindow::on_green_button_clicked()
{
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(255);
	ui->b_slider->setValue(0);
}

void controllerWindow::on_blue_button_clicked()
{
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(255);
}

void controllerWindow::on_off_button_clicked()
{
	ui->r_slider->setValue(1);
	ui->g_slider->setValue(1);
	ui->b_slider->setValue(1);
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(0);
	send("off");
}

void controllerWindow::on_set_preset_button_clicked()
{
	if (!presets.empty())
	{
		QString tempstore = presets.at(preset_index);
		QStringList temparray = tempstore.split(",");
		//info_log("Preset selected: " + temparray[0] + " " + temparray[1] + " " + temparray[2]);
		ui->r_slider->setValue(temparray[0].toInt());
		ui->g_slider->setValue(temparray[1].toInt());
		ui->b_slider->setValue(temparray[2].toInt());
	} else
		show_msgbox("There are no loaded presets!");
}

void controllerWindow::on_presets_dropdown_currentIndexChanged(int index)
{
	preset_index = index;
}

void controllerWindow::on_preset_save_button_clicked()
{
	QString tempname = ui->preset_name_textbox->text();
	if (tempname.contains("="))
	{
		show_msgbox("Cannot save a preset with a name that contains an '='.");
	} else if (tempname.isEmpty())
	{
		show_msgbox("Cannot save a preset without a name.");
	} else
	{
		save_preset(tempname);
	}
	ui->preset_name_textbox->clear();
}

void controllerWindow::on_preset_delete_button_clicked()
{
	delete_preset(ui->presets_dropdown->currentText());
}

void controllerWindow::on_red_fade_button_clicked()
{
	send("redfade");
}

void controllerWindow::on_green_fade_button_clicked()
{
	send("greenfade");
}

void controllerWindow::on_blue_fade_button_clicked()
{
	send("bluefade");
}

void controllerWindow::on_speed_button_clicked()
{
	send("speed=" + QString::number(ui->speed_slider->value()));
}

void controllerWindow::on_r_speed_slider_valueChanged(int value)
{
	send("rspeed=" + QString::number(value));
}

void controllerWindow::on_g_speed_slider_valueChanged(int value)
{
	send("gspeed=" + QString::number(value));
}

void controllerWindow::on_b_speed_slider_valueChanged(int value)
{
	send("bspeed=" + QString::number(value));
}

void controllerWindow::on_rfrom_valueChanged(int arg1)
{
	send("rf=" + QString::number(arg1));
	//ui->r_slider->setValue(arg1);
}

void controllerWindow::on_rto_valueChanged(int arg1)
{
	send("rt=" + QString::number(arg1));
}

void controllerWindow::on_gfrom_valueChanged(int arg1)
{
	send("gf=" + QString::number(arg1));
	//ui->g_slider->setValue(arg1);
}

void controllerWindow::on_gto_valueChanged(int arg1)
{
	send("gt=" + QString::number(arg1));
}

void controllerWindow::on_bfrom_valueChanged(int arg1)
{
	send("bf=" + QString::number(arg1));
	//ui->b_slider->setValue(arg1);
}

void controllerWindow::on_bto_valueChanged(int arg1)
{
	send("bt=" + QString::number(arg1));
}

bool controllerWindow::serial_connect(QString port)
{
	/* this function will attempt a ser.connection if we are not already connected */
	if (!ser->isOpen())
	{
		ser->setPortName(port);
		ser->setBaudRate(QSerialPort::Baud9600);
		ser->setDataBits(QSerialPort::Data8);
		ser->setParity(QSerialPort::NoParity);
		ser->setStopBits(QSerialPort::OneStop);
		ser->setFlowControl(QSerialPort::NoFlowControl);
		ser->open(QIODevice::ReadWrite);
		ser->waitForBytesWritten(9000);
		if (ser->isWritable())
		{
			return true;
		}
	}
	return false;
}

bool controllerWindow::serial_disconnect()
{
	/* this function disconnects from the serial port if it is connected already */
	if (ser->isOpen())
	{
		ser->close();
		ptimer->stop();
		return true;
	}
	return false;
}

void controllerWindow::send(QString com)
{
	data = "";
	data.append(com + "\n");
	if (ser->isOpen())
		ser->write(data);
}

void controllerWindow::rgb_change(int r, int g, int b)
{
	// NOT USED FUNCTION

	/* here we send our rgb values to the serial port */
	data = "";
	/* the 0 is a hack, i need to look into it at some point */
	data.append("red=" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + "\n");
	if (ser->isOpen())
		ser->write(data);
}

void controllerWindow::read()
{
	if (serdata[serdata.size() - 1] == '\n')
	{
		parse(QString(serdata));
		serdata = "";
	}
	else
		serdata = serdata + ser->readAll();
}

void controllerWindow::parse(QString message)
{
	qDebug() << message;
	if (message.contains("="))
	{
		QString command = message.split("=")[0].remove(QRegExp("[\\n\\t\\r]"));
		QString text = message.split("=")[1].remove(QRegExp("[\\n\\t\\r]"));
		if (command == "msgbox")
			show_msgbox(text);
		if (command == "ping")
		{
			qDebug() << "pong from arduino";
			tping = true;
		}
	}
}

void controllerWindow::on_serial_send_button_clicked()
{
	send(ui->serial_input->text()); 
}
// timer after ping send, if the timer timeout()'s, disconnect, claim no connection
void controllerWindow::ping()
{
	qDebug() << "sending ping";
	send("ping\n");
	tping = false;
	QTimer::singleShot(1000, this, SLOT(check_ping()));
	pingcount++;
	ui->ping_count_label->setText("Ping: " + QString::number(pingcount));
}

void controllerWindow::check_ping()
{
	if (tping)
	{
		qDebug() << "connection fine";
		tping = false;
		pingtries = 0;
	}
	else
	{
		if (pingtries >= 3)
		{
			qDebug() << "connection lost";
			on_disconnect_button_clicked();
			show_msgbox("Disconnected from Arduino.\nNo ping response after 3 tries.");
		} 
		else
		{
			pingtries++;
			qDebug() << "no ping response try" << pingtries;
		}
	}
}

void controllerWindow::on_irc_connect_button_clicked()
{
	if (irccon == false)
	{
		irccon = true;
		ircbot.setup(ui->irc_server_input->text(), ui->irc_bot_spinbox->value(), ui->irc_channel_input->text(), ui->irc_name_input->text());
		ui->irc_connect_button->setText("Disconnect");
	}
	else
	{
		irccon = false;
		ircbot.discon();
		ui->irc_connect_button->setText("Connect");
	}
}

void controllerWindow::on_server_start_button_clicked()
{
	if (!server_started)
	{
		if (srv.server_start())
		{
			server_started = true;
			ui->server_start_button->setText("Stop server");
			info_log("Server started");
		}
		else
		{
			info_log("Server could not start");
		}
	}

	else if (server_started)
	{
		if (srv.server_stop())
		{
			server_started = false;
			ui->server_start_button->setText("Start server");
			info_log("Server stopped");
		}
		else
		{
			info_log("Server not not be stopped");
		}
	}
}

void controllerWindow::cmdrecv(QString cmd)
{
	qDebug() << "received command:" << cmd;
	send(cmd);
}
