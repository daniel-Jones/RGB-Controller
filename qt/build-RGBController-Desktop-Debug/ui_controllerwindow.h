/********************************************************************************
** Form generated from reading UI file 'controllerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERWINDOW_H
#define UI_CONTROLLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controllerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *display_tab;
    QWidget *status_tab;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_5;
    QLabel *arduino_port_label;
    QPushButton *refresh_port_button;
    QLabel *status_label;
    QLabel *arduino_status_label;
    QComboBox *arduino_port_dropdown;
    QPushButton *disconnect_button;
    QPushButton *connect_button;
    QWidget *color_tab;
    QFormLayout *formLayout_2;
    QLabel *rgb_label;
    QSlider *r_slider;
    QPushButton *red_button;
    QSlider *g_slider;
    QPushButton *green_button;
    QSlider *b_slider;
    QPushButton *blue_button;
    QPushButton *off_button;
    QWidget *fade_tab;
    QFormLayout *formLayout_3;
    QGridLayout *gridLayout;
    QPushButton *blue_fade_button;
    QSpinBox *gfrom;
    QLabel *g_to_label;
    QLabel *r_to_label;
    QSpinBox *bto;
    QSpinBox *rto;
    QSpinBox *bfrom;
    QPushButton *green_fade_button;
    QSlider *b_speed_slider;
    QSlider *g_speed_slider;
    QSpinBox *gto;
    QSpinBox *rfrom;
    QPushButton *red_fade_button;
    QLabel *_to_label;
    QLabel *fade_label;
    QSlider *r_speed_slider;
    QSlider *speed_slider;
    QLabel *r_speed_label;
    QLabel *g_speed_label;
    QLabel *b_speed_label;
    QPushButton *speed_button;
    QWidget *presets_tab;
    QFormLayout *formLayout_4;
    QLabel *presets_label;
    QComboBox *presets_dropdown;
    QPushButton *set_preset_button;
    QPushButton *reload_preset_button;
    QLineEdit *preset_name_textbox;
    QPushButton *preset_save_button;
    QPushButton *preset_delete_button;
    QWidget *irc_tab;
    QFormLayout *formLayout_5;
    QLabel *irc_bot_label;
    QLabel *irc_server_label;
    QLineEdit *irc_server_input;
    QSpinBox *irc_bot_spinbox;
    QLabel *irc_channel_label;
    QLineEdit *irc_channel_input;
    QLabel *irc_name_label;
    QLineEdit *irc_name_input;
    QLabel *irc_port_label;
    QPushButton *irc_connect_button;
    QWidget *server_tab;
    QGridLayout *gridLayout_6;
    QFormLayout *server_tab_layout;
    QPushButton *server_start_button;
    QWidget *log_tab;
    QGridLayout *gridLayout_3;
    QLineEdit *serial_input;
    QPushButton *serial_send_button;
    QTextEdit *info_log_textarea;
    QLabel *info_log_label;
    QLabel *ping_count_label;

    void setupUi(QMainWindow *controllerWindow)
    {
        if (controllerWindow->objectName().isEmpty())
            controllerWindow->setObjectName(QStringLiteral("controllerWindow"));
        controllerWindow->setWindowModality(Qt::WindowModal);
        controllerWindow->resize(433, 254);
        centralWidget = new QWidget(controllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        display_tab = new QTabWidget(centralWidget);
        display_tab->setObjectName(QStringLiteral("display_tab"));
        status_tab = new QWidget();
        status_tab->setObjectName(QStringLiteral("status_tab"));
        formLayout = new QFormLayout(status_tab);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        arduino_port_label = new QLabel(status_tab);
        arduino_port_label->setObjectName(QStringLiteral("arduino_port_label"));
        arduino_port_label->setMinimumSize(QSize(120, 0));

        gridLayout_5->addWidget(arduino_port_label, 1, 0, 1, 1);

        refresh_port_button = new QPushButton(status_tab);
        refresh_port_button->setObjectName(QStringLiteral("refresh_port_button"));

        gridLayout_5->addWidget(refresh_port_button, 2, 1, 1, 1);

        status_label = new QLabel(status_tab);
        status_label->setObjectName(QStringLiteral("status_label"));

        gridLayout_5->addWidget(status_label, 0, 0, 1, 1);

        arduino_status_label = new QLabel(status_tab);
        arduino_status_label->setObjectName(QStringLiteral("arduino_status_label"));

        gridLayout_5->addWidget(arduino_status_label, 0, 1, 1, 1);

        arduino_port_dropdown = new QComboBox(status_tab);
        arduino_port_dropdown->setObjectName(QStringLiteral("arduino_port_dropdown"));

        gridLayout_5->addWidget(arduino_port_dropdown, 1, 1, 1, 1);

        disconnect_button = new QPushButton(status_tab);
        disconnect_button->setObjectName(QStringLiteral("disconnect_button"));

        gridLayout_5->addWidget(disconnect_button, 3, 1, 1, 1);

        connect_button = new QPushButton(status_tab);
        connect_button->setObjectName(QStringLiteral("connect_button"));

        gridLayout_5->addWidget(connect_button, 3, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_5);

        display_tab->addTab(status_tab, QString());
        color_tab = new QWidget();
        color_tab->setObjectName(QStringLiteral("color_tab"));
        formLayout_2 = new QFormLayout(color_tab);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        rgb_label = new QLabel(color_tab);
        rgb_label->setObjectName(QStringLiteral("rgb_label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rgb_label);

        r_slider = new QSlider(color_tab);
        r_slider->setObjectName(QStringLiteral("r_slider"));
        r_slider->setMinimumSize(QSize(120, 0));
        r_slider->setMaximumSize(QSize(120, 16777215));
        r_slider->setMaximum(255);
        r_slider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, r_slider);

        red_button = new QPushButton(color_tab);
        red_button->setObjectName(QStringLiteral("red_button"));
        red_button->setMaximumSize(QSize(90, 16777215));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, red_button);

        g_slider = new QSlider(color_tab);
        g_slider->setObjectName(QStringLiteral("g_slider"));
        g_slider->setMinimumSize(QSize(120, 0));
        g_slider->setMaximumSize(QSize(120, 16777215));
        g_slider->setMaximum(255);
        g_slider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, g_slider);

        green_button = new QPushButton(color_tab);
        green_button->setObjectName(QStringLiteral("green_button"));
        green_button->setMaximumSize(QSize(90, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, green_button);

        b_slider = new QSlider(color_tab);
        b_slider->setObjectName(QStringLiteral("b_slider"));
        b_slider->setMinimumSize(QSize(120, 0));
        b_slider->setMaximumSize(QSize(120, 16777215));
        b_slider->setMaximum(255);
        b_slider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, b_slider);

        blue_button = new QPushButton(color_tab);
        blue_button->setObjectName(QStringLiteral("blue_button"));
        blue_button->setMaximumSize(QSize(90, 16777215));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, blue_button);

        off_button = new QPushButton(color_tab);
        off_button->setObjectName(QStringLiteral("off_button"));
        off_button->setMaximumSize(QSize(90, 16777215));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, off_button);

        display_tab->addTab(color_tab, QString());
        rgb_label->raise();
        r_slider->raise();
        g_slider->raise();
        b_slider->raise();
        red_button->raise();
        green_button->raise();
        blue_button->raise();
        off_button->raise();
        fade_tab = new QWidget();
        fade_tab->setObjectName(QStringLiteral("fade_tab"));
        formLayout_3 = new QFormLayout(fade_tab);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        blue_fade_button = new QPushButton(fade_tab);
        blue_fade_button->setObjectName(QStringLiteral("blue_fade_button"));

        gridLayout->addWidget(blue_fade_button, 4, 3, 1, 1);

        gfrom = new QSpinBox(fade_tab);
        gfrom->setObjectName(QStringLiteral("gfrom"));
        gfrom->setMaximumSize(QSize(50, 16777215));
        gfrom->setMaximum(255);

        gridLayout->addWidget(gfrom, 3, 0, 1, 1);

        g_to_label = new QLabel(fade_tab);
        g_to_label->setObjectName(QStringLiteral("g_to_label"));

        gridLayout->addWidget(g_to_label, 3, 1, 1, 1);

        r_to_label = new QLabel(fade_tab);
        r_to_label->setObjectName(QStringLiteral("r_to_label"));

        gridLayout->addWidget(r_to_label, 1, 1, 1, 1);

        bto = new QSpinBox(fade_tab);
        bto->setObjectName(QStringLiteral("bto"));
        bto->setMaximumSize(QSize(50, 16777215));
        bto->setMaximum(255);

        gridLayout->addWidget(bto, 4, 2, 1, 1);

        rto = new QSpinBox(fade_tab);
        rto->setObjectName(QStringLiteral("rto"));
        rto->setMaximumSize(QSize(50, 16777215));
        rto->setMaximum(255);

        gridLayout->addWidget(rto, 1, 2, 1, 1);

        bfrom = new QSpinBox(fade_tab);
        bfrom->setObjectName(QStringLiteral("bfrom"));
        bfrom->setMaximumSize(QSize(50, 16777215));
        bfrom->setMaximum(255);

        gridLayout->addWidget(bfrom, 4, 0, 1, 1);

        green_fade_button = new QPushButton(fade_tab);
        green_fade_button->setObjectName(QStringLiteral("green_fade_button"));

        gridLayout->addWidget(green_fade_button, 3, 3, 1, 1);

        b_speed_slider = new QSlider(fade_tab);
        b_speed_slider->setObjectName(QStringLiteral("b_speed_slider"));
        b_speed_slider->setMinimum(1);
        b_speed_slider->setMaximum(500);
        b_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(b_speed_slider, 7, 0, 1, 1);

        g_speed_slider = new QSlider(fade_tab);
        g_speed_slider->setObjectName(QStringLiteral("g_speed_slider"));
        g_speed_slider->setMinimum(1);
        g_speed_slider->setMaximum(500);
        g_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(g_speed_slider, 6, 0, 1, 1);

        gto = new QSpinBox(fade_tab);
        gto->setObjectName(QStringLiteral("gto"));
        gto->setMaximumSize(QSize(50, 16777215));
        gto->setMaximum(255);

        gridLayout->addWidget(gto, 3, 2, 1, 1);

        rfrom = new QSpinBox(fade_tab);
        rfrom->setObjectName(QStringLiteral("rfrom"));
        rfrom->setMaximumSize(QSize(50, 16777215));
        rfrom->setMaximum(255);

        gridLayout->addWidget(rfrom, 1, 0, 1, 1);

        red_fade_button = new QPushButton(fade_tab);
        red_fade_button->setObjectName(QStringLiteral("red_fade_button"));

        gridLayout->addWidget(red_fade_button, 1, 3, 1, 1);

        _to_label = new QLabel(fade_tab);
        _to_label->setObjectName(QStringLiteral("_to_label"));

        gridLayout->addWidget(_to_label, 4, 1, 1, 1);

        fade_label = new QLabel(fade_tab);
        fade_label->setObjectName(QStringLiteral("fade_label"));

        gridLayout->addWidget(fade_label, 0, 0, 1, 1);

        r_speed_slider = new QSlider(fade_tab);
        r_speed_slider->setObjectName(QStringLiteral("r_speed_slider"));
        r_speed_slider->setMinimum(1);
        r_speed_slider->setMaximum(100);
        r_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(r_speed_slider, 5, 0, 1, 1);

        speed_slider = new QSlider(fade_tab);
        speed_slider->setObjectName(QStringLiteral("speed_slider"));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(500);
        speed_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(speed_slider, 8, 0, 1, 1);

        r_speed_label = new QLabel(fade_tab);
        r_speed_label->setObjectName(QStringLiteral("r_speed_label"));

        gridLayout->addWidget(r_speed_label, 5, 2, 1, 1);

        g_speed_label = new QLabel(fade_tab);
        g_speed_label->setObjectName(QStringLiteral("g_speed_label"));

        gridLayout->addWidget(g_speed_label, 6, 2, 1, 1);

        b_speed_label = new QLabel(fade_tab);
        b_speed_label->setObjectName(QStringLiteral("b_speed_label"));

        gridLayout->addWidget(b_speed_label, 7, 2, 1, 1);

        speed_button = new QPushButton(fade_tab);
        speed_button->setObjectName(QStringLiteral("speed_button"));

        gridLayout->addWidget(speed_button, 8, 2, 1, 1);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, gridLayout);

        display_tab->addTab(fade_tab, QString());
        presets_tab = new QWidget();
        presets_tab->setObjectName(QStringLiteral("presets_tab"));
        formLayout_4 = new QFormLayout(presets_tab);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        presets_label = new QLabel(presets_tab);
        presets_label->setObjectName(QStringLiteral("presets_label"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, presets_label);

        presets_dropdown = new QComboBox(presets_tab);
        presets_dropdown->setObjectName(QStringLiteral("presets_dropdown"));
        presets_dropdown->setMinimumSize(QSize(120, 0));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, presets_dropdown);

        set_preset_button = new QPushButton(presets_tab);
        set_preset_button->setObjectName(QStringLiteral("set_preset_button"));
        set_preset_button->setMaximumSize(QSize(90, 16777215));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, set_preset_button);

        reload_preset_button = new QPushButton(presets_tab);
        reload_preset_button->setObjectName(QStringLiteral("reload_preset_button"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, reload_preset_button);

        preset_name_textbox = new QLineEdit(presets_tab);
        preset_name_textbox->setObjectName(QStringLiteral("preset_name_textbox"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, preset_name_textbox);

        preset_save_button = new QPushButton(presets_tab);
        preset_save_button->setObjectName(QStringLiteral("preset_save_button"));
        preset_save_button->setMaximumSize(QSize(90, 16777215));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, preset_save_button);

        preset_delete_button = new QPushButton(presets_tab);
        preset_delete_button->setObjectName(QStringLiteral("preset_delete_button"));
        preset_delete_button->setMaximumSize(QSize(90, 16777215));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, preset_delete_button);

        display_tab->addTab(presets_tab, QString());
        irc_tab = new QWidget();
        irc_tab->setObjectName(QStringLiteral("irc_tab"));
        formLayout_5 = new QFormLayout(irc_tab);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        irc_bot_label = new QLabel(irc_tab);
        irc_bot_label->setObjectName(QStringLiteral("irc_bot_label"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, irc_bot_label);

        irc_server_label = new QLabel(irc_tab);
        irc_server_label->setObjectName(QStringLiteral("irc_server_label"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, irc_server_label);

        irc_server_input = new QLineEdit(irc_tab);
        irc_server_input->setObjectName(QStringLiteral("irc_server_input"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, irc_server_input);

        irc_bot_spinbox = new QSpinBox(irc_tab);
        irc_bot_spinbox->setObjectName(QStringLiteral("irc_bot_spinbox"));
        irc_bot_spinbox->setMaximumSize(QSize(50, 16777215));
        irc_bot_spinbox->setMaximum(99999);
        irc_bot_spinbox->setValue(6667);

        formLayout_5->setWidget(5, QFormLayout::FieldRole, irc_bot_spinbox);

        irc_channel_label = new QLabel(irc_tab);
        irc_channel_label->setObjectName(QStringLiteral("irc_channel_label"));

        formLayout_5->setWidget(6, QFormLayout::LabelRole, irc_channel_label);

        irc_channel_input = new QLineEdit(irc_tab);
        irc_channel_input->setObjectName(QStringLiteral("irc_channel_input"));

        formLayout_5->setWidget(7, QFormLayout::LabelRole, irc_channel_input);

        irc_name_label = new QLabel(irc_tab);
        irc_name_label->setObjectName(QStringLiteral("irc_name_label"));

        formLayout_5->setWidget(8, QFormLayout::LabelRole, irc_name_label);

        irc_name_input = new QLineEdit(irc_tab);
        irc_name_input->setObjectName(QStringLiteral("irc_name_input"));

        formLayout_5->setWidget(9, QFormLayout::LabelRole, irc_name_input);

        irc_port_label = new QLabel(irc_tab);
        irc_port_label->setObjectName(QStringLiteral("irc_port_label"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, irc_port_label);

        irc_connect_button = new QPushButton(irc_tab);
        irc_connect_button->setObjectName(QStringLiteral("irc_connect_button"));

        formLayout_5->setWidget(10, QFormLayout::LabelRole, irc_connect_button);

        display_tab->addTab(irc_tab, QString());
        server_tab = new QWidget();
        server_tab->setObjectName(QStringLiteral("server_tab"));
        gridLayout_6 = new QGridLayout(server_tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        server_tab_layout = new QFormLayout();
        server_tab_layout->setSpacing(6);
        server_tab_layout->setObjectName(QStringLiteral("server_tab_layout"));
        server_start_button = new QPushButton(server_tab);
        server_start_button->setObjectName(QStringLiteral("server_start_button"));

        server_tab_layout->setWidget(0, QFormLayout::LabelRole, server_start_button);


        gridLayout_6->addLayout(server_tab_layout, 0, 0, 1, 1);

        display_tab->addTab(server_tab, QString());
        log_tab = new QWidget();
        log_tab->setObjectName(QStringLiteral("log_tab"));
        gridLayout_3 = new QGridLayout(log_tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        serial_input = new QLineEdit(log_tab);
        serial_input->setObjectName(QStringLiteral("serial_input"));

        gridLayout_3->addWidget(serial_input, 5, 0, 1, 1);

        serial_send_button = new QPushButton(log_tab);
        serial_send_button->setObjectName(QStringLiteral("serial_send_button"));

        gridLayout_3->addWidget(serial_send_button, 5, 1, 1, 1);

        info_log_textarea = new QTextEdit(log_tab);
        info_log_textarea->setObjectName(QStringLiteral("info_log_textarea"));

        gridLayout_3->addWidget(info_log_textarea, 4, 0, 1, 2);

        info_log_label = new QLabel(log_tab);
        info_log_label->setObjectName(QStringLiteral("info_log_label"));

        gridLayout_3->addWidget(info_log_label, 0, 0, 1, 1);

        ping_count_label = new QLabel(log_tab);
        ping_count_label->setObjectName(QStringLiteral("ping_count_label"));

        gridLayout_3->addWidget(ping_count_label, 0, 1, 1, 1);

        display_tab->addTab(log_tab, QString());

        gridLayout_2->addWidget(display_tab, 7, 1, 1, 1);

        controllerWindow->setCentralWidget(centralWidget);

        retranslateUi(controllerWindow);

        display_tab->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(controllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controllerWindow)
    {
        controllerWindow->setWindowTitle(QApplication::translate("controllerWindow", "RGB Controller", Q_NULLPTR));
        arduino_port_label->setText(QApplication::translate("controllerWindow", "Arduino port", Q_NULLPTR));
        refresh_port_button->setText(QApplication::translate("controllerWindow", "Refresh", Q_NULLPTR));
        status_label->setText(QApplication::translate("controllerWindow", "Status", Q_NULLPTR));
        arduino_status_label->setText(QApplication::translate("controllerWindow", "<font color = red>Disconnected</font>", Q_NULLPTR));
        disconnect_button->setText(QApplication::translate("controllerWindow", "Disconnect", Q_NULLPTR));
        connect_button->setText(QApplication::translate("controllerWindow", "Connect", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(status_tab), QApplication::translate("controllerWindow", "Status", Q_NULLPTR));
        rgb_label->setText(QApplication::translate("controllerWindow", "RGB colors", Q_NULLPTR));
        red_button->setText(QApplication::translate("controllerWindow", "Red", Q_NULLPTR));
        green_button->setText(QApplication::translate("controllerWindow", "Green", Q_NULLPTR));
        blue_button->setText(QApplication::translate("controllerWindow", "Blue", Q_NULLPTR));
        off_button->setText(QApplication::translate("controllerWindow", "Off", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(color_tab), QApplication::translate("controllerWindow", "Color", Q_NULLPTR));
        blue_fade_button->setText(QApplication::translate("controllerWindow", "Blue toggle", Q_NULLPTR));
        g_to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        r_to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        green_fade_button->setText(QApplication::translate("controllerWindow", "Green toggle", Q_NULLPTR));
        red_fade_button->setText(QApplication::translate("controllerWindow", "Red toggle", Q_NULLPTR));
        _to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        fade_label->setText(QApplication::translate("controllerWindow", "Fade", Q_NULLPTR));
        r_speed_label->setText(QApplication::translate("controllerWindow", "Red speed", Q_NULLPTR));
        g_speed_label->setText(QApplication::translate("controllerWindow", "Green speed", Q_NULLPTR));
        b_speed_label->setText(QApplication::translate("controllerWindow", "Blue speed", Q_NULLPTR));
        speed_button->setText(QApplication::translate("controllerWindow", "Speed", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(fade_tab), QApplication::translate("controllerWindow", "Fade", Q_NULLPTR));
        presets_label->setText(QApplication::translate("controllerWindow", "Presets", Q_NULLPTR));
        set_preset_button->setText(QApplication::translate("controllerWindow", "Set", Q_NULLPTR));
        reload_preset_button->setText(QApplication::translate("controllerWindow", "Reload", Q_NULLPTR));
        preset_save_button->setText(QApplication::translate("controllerWindow", "Save", Q_NULLPTR));
        preset_delete_button->setText(QApplication::translate("controllerWindow", "Delete", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(presets_tab), QApplication::translate("controllerWindow", "Presets", Q_NULLPTR));
        irc_bot_label->setText(QApplication::translate("controllerWindow", "IRC bot", Q_NULLPTR));
        irc_server_label->setText(QApplication::translate("controllerWindow", "Server", Q_NULLPTR));
        irc_server_input->setText(QApplication::translate("controllerWindow", "irc.danieljon.es", Q_NULLPTR));
        irc_channel_label->setText(QApplication::translate("controllerWindow", "Channel", Q_NULLPTR));
        irc_channel_input->setText(QApplication::translate("controllerWindow", "#csgo", Q_NULLPTR));
        irc_name_label->setText(QApplication::translate("controllerWindow", "Name", Q_NULLPTR));
        irc_name_input->setText(QApplication::translate("controllerWindow", "LightBot", Q_NULLPTR));
        irc_port_label->setText(QApplication::translate("controllerWindow", "Port", Q_NULLPTR));
        irc_connect_button->setText(QApplication::translate("controllerWindow", "Connect", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(irc_tab), QApplication::translate("controllerWindow", "IRC", Q_NULLPTR));
        server_start_button->setText(QApplication::translate("controllerWindow", "Start server", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(server_tab), QApplication::translate("controllerWindow", "Server", Q_NULLPTR));
        serial_send_button->setText(QApplication::translate("controllerWindow", "Send", Q_NULLPTR));
        info_log_label->setText(QApplication::translate("controllerWindow", "Information log", Q_NULLPTR));
        ping_count_label->setText(QApplication::translate("controllerWindow", "Ping", Q_NULLPTR));
        display_tab->setTabText(display_tab->indexOf(log_tab), QApplication::translate("controllerWindow", "Log", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class controllerWindow: public Ui_controllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
