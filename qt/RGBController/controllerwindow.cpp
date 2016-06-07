#include "controllerwindow.h"

controllerWindow::controllerWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::controllerWindow)
{
	/* this is our setup function, we set things up here */
	ui->setupUi(this);
	info_log("RGB Controller started");
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
    ui->preset_name_textbox->setEnabled(false);
	ui->presets_dropdown->setEnabled(false);
	ui->r_slider->setEnabled(false);
	ui->g_slider->setEnabled(false);
	ui->b_slider->setEnabled(false);
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(0);
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
	QFile inputFile("presets.txt");
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
		show_msgbox("Unable to find the presets fle.\nThis file needs to be named 'presets.txt' and be located in the same directory as the binary.");
		info_log("Presets file not found.");
    }
}

void controllerWindow::save_preset(QString name)
{
    /* this function will save our preset to file */
    QFile file("presets.txt");
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

void controllerWindow::serial_rgb_change(int r, int g, int b)
{
	portf.rgb_change(r, g, b);
}

void controllerWindow::show_msgbox(QString message)
{
	QMessageBox msgbox;
	msgbox.setText(message);
	msgbox.exec();
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
	port = ui->arduino_port_dropdown->currentText();
	if (portf.serial_connect(port))
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
        ui->preset_name_textbox->setEnabled(true);
		ui->presets_dropdown->setEnabled(true);
		ui->r_slider->setEnabled(true);
		ui->g_slider->setEnabled(true);
		ui->b_slider->setEnabled(true);
		ui->refresh_port_button->setEnabled(false);
		ui->arduino_port_dropdown->setEnabled(false);
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
	if (portf.serial_disconnect())
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
	serial_rgb_change(r, g, b);
}

void controllerWindow::on_g_slider_valueChanged(int value)
{
	g = value;
	serial_rgb_change(r, g, b);
}

void controllerWindow::on_b_slider_valueChanged(int value)
{
	b = value;
	serial_rgb_change(r, g, b);
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
	ui->r_slider->setValue(0);
	ui->g_slider->setValue(0);
	ui->b_slider->setValue(0);
}

void controllerWindow::on_set_preset_button_clicked()
{
	if (!presets.empty())
	{
		QString tempstore = presets.at(preset_index);
		QStringList temparray = tempstore.split(",");
		info_log("Preset selected: " + temparray[0] + " " + temparray[1] + " " + temparray[2]);
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
}
