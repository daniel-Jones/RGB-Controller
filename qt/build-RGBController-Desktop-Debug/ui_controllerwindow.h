/********************************************************************************
** Form generated from reading UI file 'controllerwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERWINDOW_H
#define UI_CONTROLLERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controllerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *arduino_status_label;
    QLabel *arduino_port_label;
    QComboBox *arduino_port_dropdown;
    QPushButton *refresh_port_button;
    QSlider *r_slider;
    QPushButton *connect_button;
    QPushButton *disconnect_button;
    QLabel *rgb_label;
    QComboBox *presets_dropdown;
    QPushButton *red_button;
    QSlider *g_slider;
    QPushButton *green_button;
    QSlider *b_slider;
    QPushButton *blue_button;
    QPushButton *off_button;
    QPushButton *set_preset_button;
    QPushButton *reload_preset_button;
    QLineEdit *preset_name_textbox;
    QPushButton *preset_save_button;
    QLabel *presets_label;
    QLabel *status_label;
    QPushButton *preset_delete_button;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_3;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *info_log_label;
    QTextEdit *info_log_textarea;
    QSlider *speed_slider;
    QPushButton *speed_button;

    void setupUi(QMainWindow *controllerWindow)
    {
        if (controllerWindow->objectName().isEmpty())
            controllerWindow->setObjectName(QString::fromUtf8("controllerWindow"));
        controllerWindow->setWindowModality(Qt::WindowModal);
        controllerWindow->resize(227, 499);
        centralWidget = new QWidget(controllerWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        arduino_status_label = new QLabel(centralWidget);
        arduino_status_label->setObjectName(QString::fromUtf8("arduino_status_label"));

        gridLayout_2->addWidget(arduino_status_label, 0, 1, 1, 1);

        arduino_port_label = new QLabel(centralWidget);
        arduino_port_label->setObjectName(QString::fromUtf8("arduino_port_label"));
        arduino_port_label->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(arduino_port_label, 1, 0, 1, 1);

        arduino_port_dropdown = new QComboBox(centralWidget);
        arduino_port_dropdown->setObjectName(QString::fromUtf8("arduino_port_dropdown"));

        gridLayout_2->addWidget(arduino_port_dropdown, 1, 1, 1, 1);

        refresh_port_button = new QPushButton(centralWidget);
        refresh_port_button->setObjectName(QString::fromUtf8("refresh_port_button"));

        gridLayout_2->addWidget(refresh_port_button, 2, 1, 1, 1);

        r_slider = new QSlider(centralWidget);
        r_slider->setObjectName(QString::fromUtf8("r_slider"));
        r_slider->setMinimumSize(QSize(120, 0));
        r_slider->setMaximumSize(QSize(120, 16777215));
        r_slider->setMaximum(255);
        r_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(r_slider, 5, 0, 1, 1);

        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));

        gridLayout_2->addWidget(connect_button, 3, 0, 1, 1);

        disconnect_button = new QPushButton(centralWidget);
        disconnect_button->setObjectName(QString::fromUtf8("disconnect_button"));

        gridLayout_2->addWidget(disconnect_button, 3, 1, 1, 1);

        rgb_label = new QLabel(centralWidget);
        rgb_label->setObjectName(QString::fromUtf8("rgb_label"));

        gridLayout_2->addWidget(rgb_label, 4, 0, 1, 1);

        presets_dropdown = new QComboBox(centralWidget);
        presets_dropdown->setObjectName(QString::fromUtf8("presets_dropdown"));
        presets_dropdown->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(presets_dropdown, 10, 0, 1, 1);

        red_button = new QPushButton(centralWidget);
        red_button->setObjectName(QString::fromUtf8("red_button"));

        gridLayout_2->addWidget(red_button, 5, 1, 1, 1);

        g_slider = new QSlider(centralWidget);
        g_slider->setObjectName(QString::fromUtf8("g_slider"));
        g_slider->setMinimumSize(QSize(120, 0));
        g_slider->setMaximumSize(QSize(120, 16777215));
        g_slider->setMaximum(255);
        g_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(g_slider, 6, 0, 1, 1);

        green_button = new QPushButton(centralWidget);
        green_button->setObjectName(QString::fromUtf8("green_button"));

        gridLayout_2->addWidget(green_button, 6, 1, 1, 1);

        b_slider = new QSlider(centralWidget);
        b_slider->setObjectName(QString::fromUtf8("b_slider"));
        b_slider->setMinimumSize(QSize(120, 0));
        b_slider->setMaximumSize(QSize(120, 16777215));
        b_slider->setMaximum(255);
        b_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b_slider, 7, 0, 1, 1);

        blue_button = new QPushButton(centralWidget);
        blue_button->setObjectName(QString::fromUtf8("blue_button"));

        gridLayout_2->addWidget(blue_button, 7, 1, 1, 1);

        off_button = new QPushButton(centralWidget);
        off_button->setObjectName(QString::fromUtf8("off_button"));

        gridLayout_2->addWidget(off_button, 8, 1, 1, 1);

        set_preset_button = new QPushButton(centralWidget);
        set_preset_button->setObjectName(QString::fromUtf8("set_preset_button"));

        gridLayout_2->addWidget(set_preset_button, 10, 1, 1, 1);

        reload_preset_button = new QPushButton(centralWidget);
        reload_preset_button->setObjectName(QString::fromUtf8("reload_preset_button"));

        gridLayout_2->addWidget(reload_preset_button, 11, 0, 1, 1);

        preset_name_textbox = new QLineEdit(centralWidget);
        preset_name_textbox->setObjectName(QString::fromUtf8("preset_name_textbox"));

        gridLayout_2->addWidget(preset_name_textbox, 12, 0, 1, 1);

        preset_save_button = new QPushButton(centralWidget);
        preset_save_button->setObjectName(QString::fromUtf8("preset_save_button"));

        gridLayout_2->addWidget(preset_save_button, 12, 1, 1, 1);

        presets_label = new QLabel(centralWidget);
        presets_label->setObjectName(QString::fromUtf8("presets_label"));

        gridLayout_2->addWidget(presets_label, 9, 0, 1, 1);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QString::fromUtf8("status_label"));

        gridLayout_2->addWidget(status_label, 0, 0, 1, 1);

        preset_delete_button = new QPushButton(centralWidget);
        preset_delete_button->setObjectName(QString::fromUtf8("preset_delete_button"));

        gridLayout_2->addWidget(preset_delete_button, 13, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 3, 1, 1);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(255);

        gridLayout->addWidget(spinBox, 4, 0, 1, 1);

        spinBox_4 = new QSpinBox(centralWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMaximum(255);

        gridLayout->addWidget(spinBox_4, 1, 2, 1, 1);

        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(255);

        gridLayout->addWidget(spinBox_3, 3, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(255);

        gridLayout->addWidget(spinBox_2, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        spinBox_6 = new QSpinBox(centralWidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMaximum(255);

        gridLayout->addWidget(spinBox_6, 4, 2, 1, 1);

        spinBox_5 = new QSpinBox(centralWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMaximum(255);

        gridLayout->addWidget(spinBox_5, 3, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 3, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 14, 0, 1, 2);

        info_log_label = new QLabel(centralWidget);
        info_log_label->setObjectName(QString::fromUtf8("info_log_label"));

        gridLayout_2->addWidget(info_log_label, 16, 0, 1, 1);

        info_log_textarea = new QTextEdit(centralWidget);
        info_log_textarea->setObjectName(QString::fromUtf8("info_log_textarea"));

        gridLayout_2->addWidget(info_log_textarea, 17, 0, 1, 2);

        speed_slider = new QSlider(centralWidget);
        speed_slider->setObjectName(QString::fromUtf8("speed_slider"));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(500);
        speed_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(speed_slider, 15, 0, 1, 1);

        speed_button = new QPushButton(centralWidget);
        speed_button->setObjectName(QString::fromUtf8("speed_button"));

        gridLayout_2->addWidget(speed_button, 15, 1, 1, 1);

        controllerWindow->setCentralWidget(centralWidget);

        retranslateUi(controllerWindow);

        QMetaObject::connectSlotsByName(controllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controllerWindow)
    {
        controllerWindow->setWindowTitle(QApplication::translate("controllerWindow", "RGB Controller", 0, QApplication::UnicodeUTF8));
        arduino_status_label->setText(QApplication::translate("controllerWindow", "<font color = red>Disconnected</font>", 0, QApplication::UnicodeUTF8));
        arduino_port_label->setText(QApplication::translate("controllerWindow", "Arduino port", 0, QApplication::UnicodeUTF8));
        refresh_port_button->setText(QApplication::translate("controllerWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        connect_button->setText(QApplication::translate("controllerWindow", "Connect", 0, QApplication::UnicodeUTF8));
        disconnect_button->setText(QApplication::translate("controllerWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        rgb_label->setText(QApplication::translate("controllerWindow", "RGB colors", 0, QApplication::UnicodeUTF8));
        red_button->setText(QApplication::translate("controllerWindow", "Red", 0, QApplication::UnicodeUTF8));
        green_button->setText(QApplication::translate("controllerWindow", "Green", 0, QApplication::UnicodeUTF8));
        blue_button->setText(QApplication::translate("controllerWindow", "Blue", 0, QApplication::UnicodeUTF8));
        off_button->setText(QApplication::translate("controllerWindow", "Off", 0, QApplication::UnicodeUTF8));
        set_preset_button->setText(QApplication::translate("controllerWindow", "Set", 0, QApplication::UnicodeUTF8));
        reload_preset_button->setText(QApplication::translate("controllerWindow", "Reload", 0, QApplication::UnicodeUTF8));
        preset_save_button->setText(QApplication::translate("controllerWindow", "Save", 0, QApplication::UnicodeUTF8));
        presets_label->setText(QApplication::translate("controllerWindow", "Presets", 0, QApplication::UnicodeUTF8));
        status_label->setText(QApplication::translate("controllerWindow", "Status", 0, QApplication::UnicodeUTF8));
        preset_delete_button->setText(QApplication::translate("controllerWindow", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("controllerWindow", "Set", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("controllerWindow", "to", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("controllerWindow", "to", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("controllerWindow", "Set", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("controllerWindow", "Set", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("controllerWindow", "to", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("controllerWindow", "Fade", 0, QApplication::UnicodeUTF8));
        info_log_label->setText(QApplication::translate("controllerWindow", "Information log", 0, QApplication::UnicodeUTF8));
        speed_button->setText(QApplication::translate("controllerWindow", "Speed", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class controllerWindow: public Ui_controllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
