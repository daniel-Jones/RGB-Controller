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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controllerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *reload_preset_button;
    QPushButton *off_button;
    QPushButton *preset_delete_button;
    QLabel *presets_label;
    QPushButton *disconnect_button;
    QLabel *arduino_status_label;
    QComboBox *arduino_port_dropdown;
    QSlider *b_slider;
    QSlider *b_speed_slider;
    QTextEdit *info_log_textarea;
    QLineEdit *preset_name_textbox;
    QComboBox *presets_dropdown;
    QLabel *info_log_label;
    QPushButton *green_button;
    QPushButton *refresh_port_button;
    QSlider *g_speed_slider;
    QLabel *rgb_label;
    QLabel *status_label;
    QPushButton *preset_save_button;
    QSlider *g_slider;
    QSlider *r_speed_slider;
    QLabel *g_speed_label;
    QPushButton *red_button;
    QPushButton *blue_button;
    QPushButton *connect_button;
    QLabel *r_speed_label;
    QSlider *r_slider;
    QPushButton *set_preset_button;
    QGridLayout *gridLayout;
    QPushButton *blue_fade_button;
    QSpinBox *bfrom;
    QSpinBox *rto;
    QSpinBox *gfrom;
    QLabel *r_to_label;
    QSpinBox *rfrom;
    QLabel *g_to_label;
    QSpinBox *bto;
    QSpinBox *gto;
    QPushButton *green_fade_button;
    QPushButton *red_fade_button;
    QLabel *_to_label;
    QLabel *fade_label;
    QLabel *arduino_port_label;
    QLabel *b_speed_label;
    QPushButton *speed_button;
    QSlider *speed_slider;

    void setupUi(QMainWindow *controllerWindow)
    {
        if (controllerWindow->objectName().isEmpty())
            controllerWindow->setObjectName(QStringLiteral("controllerWindow"));
        controllerWindow->setWindowModality(Qt::WindowModal);
        controllerWindow->resize(232, 629);
        centralWidget = new QWidget(controllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        reload_preset_button = new QPushButton(centralWidget);
        reload_preset_button->setObjectName(QStringLiteral("reload_preset_button"));

        gridLayout_2->addWidget(reload_preset_button, 11, 0, 1, 1);

        off_button = new QPushButton(centralWidget);
        off_button->setObjectName(QStringLiteral("off_button"));

        gridLayout_2->addWidget(off_button, 8, 1, 1, 1);

        preset_delete_button = new QPushButton(centralWidget);
        preset_delete_button->setObjectName(QStringLiteral("preset_delete_button"));

        gridLayout_2->addWidget(preset_delete_button, 13, 1, 1, 1);

        presets_label = new QLabel(centralWidget);
        presets_label->setObjectName(QStringLiteral("presets_label"));

        gridLayout_2->addWidget(presets_label, 9, 0, 1, 1);

        disconnect_button = new QPushButton(centralWidget);
        disconnect_button->setObjectName(QStringLiteral("disconnect_button"));

        gridLayout_2->addWidget(disconnect_button, 3, 1, 1, 1);

        arduino_status_label = new QLabel(centralWidget);
        arduino_status_label->setObjectName(QStringLiteral("arduino_status_label"));

        gridLayout_2->addWidget(arduino_status_label, 0, 1, 1, 1);

        arduino_port_dropdown = new QComboBox(centralWidget);
        arduino_port_dropdown->setObjectName(QStringLiteral("arduino_port_dropdown"));

        gridLayout_2->addWidget(arduino_port_dropdown, 1, 1, 1, 1);

        b_slider = new QSlider(centralWidget);
        b_slider->setObjectName(QStringLiteral("b_slider"));
        b_slider->setMinimumSize(QSize(120, 0));
        b_slider->setMaximumSize(QSize(120, 16777215));
        b_slider->setMaximum(255);
        b_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b_slider, 7, 0, 1, 1);

        b_speed_slider = new QSlider(centralWidget);
        b_speed_slider->setObjectName(QStringLiteral("b_speed_slider"));
        b_speed_slider->setMinimum(1);
        b_speed_slider->setMaximum(500);
        b_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(b_speed_slider, 17, 0, 1, 1);

        info_log_textarea = new QTextEdit(centralWidget);
        info_log_textarea->setObjectName(QStringLiteral("info_log_textarea"));

        gridLayout_2->addWidget(info_log_textarea, 20, 0, 1, 2);

        preset_name_textbox = new QLineEdit(centralWidget);
        preset_name_textbox->setObjectName(QStringLiteral("preset_name_textbox"));

        gridLayout_2->addWidget(preset_name_textbox, 12, 0, 1, 1);

        presets_dropdown = new QComboBox(centralWidget);
        presets_dropdown->setObjectName(QStringLiteral("presets_dropdown"));
        presets_dropdown->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(presets_dropdown, 10, 0, 1, 1);

        info_log_label = new QLabel(centralWidget);
        info_log_label->setObjectName(QStringLiteral("info_log_label"));

        gridLayout_2->addWidget(info_log_label, 19, 0, 1, 1);

        green_button = new QPushButton(centralWidget);
        green_button->setObjectName(QStringLiteral("green_button"));

        gridLayout_2->addWidget(green_button, 6, 1, 1, 1);

        refresh_port_button = new QPushButton(centralWidget);
        refresh_port_button->setObjectName(QStringLiteral("refresh_port_button"));

        gridLayout_2->addWidget(refresh_port_button, 2, 1, 1, 1);

        g_speed_slider = new QSlider(centralWidget);
        g_speed_slider->setObjectName(QStringLiteral("g_speed_slider"));
        g_speed_slider->setMinimum(1);
        g_speed_slider->setMaximum(500);
        g_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(g_speed_slider, 16, 0, 1, 1);

        rgb_label = new QLabel(centralWidget);
        rgb_label->setObjectName(QStringLiteral("rgb_label"));

        gridLayout_2->addWidget(rgb_label, 4, 0, 1, 1);

        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));

        gridLayout_2->addWidget(status_label, 0, 0, 1, 1);

        preset_save_button = new QPushButton(centralWidget);
        preset_save_button->setObjectName(QStringLiteral("preset_save_button"));

        gridLayout_2->addWidget(preset_save_button, 12, 1, 1, 1);

        g_slider = new QSlider(centralWidget);
        g_slider->setObjectName(QStringLiteral("g_slider"));
        g_slider->setMinimumSize(QSize(120, 0));
        g_slider->setMaximumSize(QSize(120, 16777215));
        g_slider->setMaximum(255);
        g_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(g_slider, 6, 0, 1, 1);

        r_speed_slider = new QSlider(centralWidget);
        r_speed_slider->setObjectName(QStringLiteral("r_speed_slider"));
        r_speed_slider->setMinimum(1);
        r_speed_slider->setMaximum(500);
        r_speed_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(r_speed_slider, 15, 0, 1, 1);

        g_speed_label = new QLabel(centralWidget);
        g_speed_label->setObjectName(QStringLiteral("g_speed_label"));

        gridLayout_2->addWidget(g_speed_label, 16, 1, 1, 1);

        red_button = new QPushButton(centralWidget);
        red_button->setObjectName(QStringLiteral("red_button"));

        gridLayout_2->addWidget(red_button, 5, 1, 1, 1);

        blue_button = new QPushButton(centralWidget);
        blue_button->setObjectName(QStringLiteral("blue_button"));

        gridLayout_2->addWidget(blue_button, 7, 1, 1, 1);

        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QStringLiteral("connect_button"));

        gridLayout_2->addWidget(connect_button, 3, 0, 1, 1);

        r_speed_label = new QLabel(centralWidget);
        r_speed_label->setObjectName(QStringLiteral("r_speed_label"));

        gridLayout_2->addWidget(r_speed_label, 15, 1, 1, 1);

        r_slider = new QSlider(centralWidget);
        r_slider->setObjectName(QStringLiteral("r_slider"));
        r_slider->setMinimumSize(QSize(120, 0));
        r_slider->setMaximumSize(QSize(120, 16777215));
        r_slider->setMaximum(255);
        r_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(r_slider, 5, 0, 1, 1);

        set_preset_button = new QPushButton(centralWidget);
        set_preset_button->setObjectName(QStringLiteral("set_preset_button"));

        gridLayout_2->addWidget(set_preset_button, 10, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        blue_fade_button = new QPushButton(centralWidget);
        blue_fade_button->setObjectName(QStringLiteral("blue_fade_button"));

        gridLayout->addWidget(blue_fade_button, 4, 3, 1, 1);

        bfrom = new QSpinBox(centralWidget);
        bfrom->setObjectName(QStringLiteral("bfrom"));
        bfrom->setMaximum(255);

        gridLayout->addWidget(bfrom, 4, 0, 1, 1);

        rto = new QSpinBox(centralWidget);
        rto->setObjectName(QStringLiteral("rto"));
        rto->setMaximum(255);

        gridLayout->addWidget(rto, 1, 2, 1, 1);

        gfrom = new QSpinBox(centralWidget);
        gfrom->setObjectName(QStringLiteral("gfrom"));
        gfrom->setMaximum(255);

        gridLayout->addWidget(gfrom, 3, 0, 1, 1);

        r_to_label = new QLabel(centralWidget);
        r_to_label->setObjectName(QStringLiteral("r_to_label"));

        gridLayout->addWidget(r_to_label, 1, 1, 1, 1);

        rfrom = new QSpinBox(centralWidget);
        rfrom->setObjectName(QStringLiteral("rfrom"));
        rfrom->setMaximum(255);

        gridLayout->addWidget(rfrom, 1, 0, 1, 1);

        g_to_label = new QLabel(centralWidget);
        g_to_label->setObjectName(QStringLiteral("g_to_label"));

        gridLayout->addWidget(g_to_label, 3, 1, 1, 1);

        bto = new QSpinBox(centralWidget);
        bto->setObjectName(QStringLiteral("bto"));
        bto->setMaximum(255);

        gridLayout->addWidget(bto, 4, 2, 1, 1);

        gto = new QSpinBox(centralWidget);
        gto->setObjectName(QStringLiteral("gto"));
        gto->setMaximum(255);

        gridLayout->addWidget(gto, 3, 2, 1, 1);

        green_fade_button = new QPushButton(centralWidget);
        green_fade_button->setObjectName(QStringLiteral("green_fade_button"));

        gridLayout->addWidget(green_fade_button, 3, 3, 1, 1);

        red_fade_button = new QPushButton(centralWidget);
        red_fade_button->setObjectName(QStringLiteral("red_fade_button"));

        gridLayout->addWidget(red_fade_button, 1, 3, 1, 1);

        _to_label = new QLabel(centralWidget);
        _to_label->setObjectName(QStringLiteral("_to_label"));

        gridLayout->addWidget(_to_label, 4, 1, 1, 1);

        fade_label = new QLabel(centralWidget);
        fade_label->setObjectName(QStringLiteral("fade_label"));

        gridLayout->addWidget(fade_label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 14, 0, 1, 2);

        arduino_port_label = new QLabel(centralWidget);
        arduino_port_label->setObjectName(QStringLiteral("arduino_port_label"));
        arduino_port_label->setMinimumSize(QSize(120, 0));

        gridLayout_2->addWidget(arduino_port_label, 1, 0, 1, 1);

        b_speed_label = new QLabel(centralWidget);
        b_speed_label->setObjectName(QStringLiteral("b_speed_label"));

        gridLayout_2->addWidget(b_speed_label, 17, 1, 1, 1);

        speed_button = new QPushButton(centralWidget);
        speed_button->setObjectName(QStringLiteral("speed_button"));

        gridLayout_2->addWidget(speed_button, 18, 1, 1, 1);

        speed_slider = new QSlider(centralWidget);
        speed_slider->setObjectName(QStringLiteral("speed_slider"));
        speed_slider->setMinimum(10);
        speed_slider->setMaximum(500);
        speed_slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(speed_slider, 18, 0, 1, 1);

        controllerWindow->setCentralWidget(centralWidget);

        retranslateUi(controllerWindow);

        QMetaObject::connectSlotsByName(controllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controllerWindow)
    {
        controllerWindow->setWindowTitle(QApplication::translate("controllerWindow", "RGB Controller", Q_NULLPTR));
        reload_preset_button->setText(QApplication::translate("controllerWindow", "Reload", Q_NULLPTR));
        off_button->setText(QApplication::translate("controllerWindow", "Off", Q_NULLPTR));
        preset_delete_button->setText(QApplication::translate("controllerWindow", "Delete", Q_NULLPTR));
        presets_label->setText(QApplication::translate("controllerWindow", "Presets", Q_NULLPTR));
        disconnect_button->setText(QApplication::translate("controllerWindow", "Disconnect", Q_NULLPTR));
        arduino_status_label->setText(QApplication::translate("controllerWindow", "<font color = red>Disconnected</font>", Q_NULLPTR));
        info_log_label->setText(QApplication::translate("controllerWindow", "Information log", Q_NULLPTR));
        green_button->setText(QApplication::translate("controllerWindow", "Green", Q_NULLPTR));
        refresh_port_button->setText(QApplication::translate("controllerWindow", "Refresh", Q_NULLPTR));
        rgb_label->setText(QApplication::translate("controllerWindow", "RGB colors", Q_NULLPTR));
        status_label->setText(QApplication::translate("controllerWindow", "Status", Q_NULLPTR));
        preset_save_button->setText(QApplication::translate("controllerWindow", "Save", Q_NULLPTR));
        g_speed_label->setText(QApplication::translate("controllerWindow", "Green speed", Q_NULLPTR));
        red_button->setText(QApplication::translate("controllerWindow", "Red", Q_NULLPTR));
        blue_button->setText(QApplication::translate("controllerWindow", "Blue", Q_NULLPTR));
        connect_button->setText(QApplication::translate("controllerWindow", "Connect", Q_NULLPTR));
        r_speed_label->setText(QApplication::translate("controllerWindow", "Red speed", Q_NULLPTR));
        set_preset_button->setText(QApplication::translate("controllerWindow", "Set", Q_NULLPTR));
        blue_fade_button->setText(QApplication::translate("controllerWindow", "Blue toggle", Q_NULLPTR));
        r_to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        g_to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        green_fade_button->setText(QApplication::translate("controllerWindow", "Green toggle", Q_NULLPTR));
        red_fade_button->setText(QApplication::translate("controllerWindow", "Red toggle", Q_NULLPTR));
        _to_label->setText(QApplication::translate("controllerWindow", "to", Q_NULLPTR));
        fade_label->setText(QApplication::translate("controllerWindow", "Fade", Q_NULLPTR));
        arduino_port_label->setText(QApplication::translate("controllerWindow", "Arduino port", Q_NULLPTR));
        b_speed_label->setText(QApplication::translate("controllerWindow", "Blue speed", Q_NULLPTR));
        speed_button->setText(QApplication::translate("controllerWindow", "Speed", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class controllerWindow: public Ui_controllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
