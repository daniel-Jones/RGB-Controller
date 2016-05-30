/********************************************************************************
** Form generated from reading UI file 'controllerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controllerWindow
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QLabel *status_label;
    QLabel *arduino_status_label;
    QLabel *arduino_port_label;
    QComboBox *arduino_port_dropdown;
    QPushButton *refresh_port_button;
    QPushButton *connect_button;
    QPushButton *disconnect_button;
    QLabel *rgb_label;
    QPushButton *red_button;
    QSlider *r_slider;
    QSlider *g_slider;
    QSlider *b_slider;
    QPushButton *green_button;
    QPushButton *blue_button;
    QLabel *presets_label;
    QPushButton *off_button;
    QLabel *info_log_label;
    QPushButton *reload_preset_button;
    QPushButton *set_preset_button;
    QComboBox *presets_dropdown;
    QTextEdit *info_log_textarea;

    void setupUi(QMainWindow *controllerWindow)
    {
        if (controllerWindow->objectName().isEmpty())
            controllerWindow->setObjectName(QStringLiteral("controllerWindow"));
        controllerWindow->resize(229, 394);
        centralWidget = new QWidget(controllerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, status_label);

        arduino_status_label = new QLabel(centralWidget);
        arduino_status_label->setObjectName(QStringLiteral("arduino_status_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, arduino_status_label);

        arduino_port_label = new QLabel(centralWidget);
        arduino_port_label->setObjectName(QStringLiteral("arduino_port_label"));
        arduino_port_label->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, arduino_port_label);

        arduino_port_dropdown = new QComboBox(centralWidget);
        arduino_port_dropdown->setObjectName(QStringLiteral("arduino_port_dropdown"));

        formLayout->setWidget(1, QFormLayout::FieldRole, arduino_port_dropdown);

        refresh_port_button = new QPushButton(centralWidget);
        refresh_port_button->setObjectName(QStringLiteral("refresh_port_button"));

        formLayout->setWidget(2, QFormLayout::FieldRole, refresh_port_button);

        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QStringLiteral("connect_button"));

        formLayout->setWidget(3, QFormLayout::LabelRole, connect_button);

        disconnect_button = new QPushButton(centralWidget);
        disconnect_button->setObjectName(QStringLiteral("disconnect_button"));

        formLayout->setWidget(3, QFormLayout::FieldRole, disconnect_button);

        rgb_label = new QLabel(centralWidget);
        rgb_label->setObjectName(QStringLiteral("rgb_label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, rgb_label);

        red_button = new QPushButton(centralWidget);
        red_button->setObjectName(QStringLiteral("red_button"));

        formLayout->setWidget(5, QFormLayout::FieldRole, red_button);

        r_slider = new QSlider(centralWidget);
        r_slider->setObjectName(QStringLiteral("r_slider"));
        r_slider->setMinimumSize(QSize(120, 0));
        r_slider->setMaximumSize(QSize(120, 16777215));
        r_slider->setMaximum(255);
        r_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(5, QFormLayout::LabelRole, r_slider);

        g_slider = new QSlider(centralWidget);
        g_slider->setObjectName(QStringLiteral("g_slider"));
        g_slider->setMinimumSize(QSize(120, 0));
        g_slider->setMaximumSize(QSize(120, 16777215));
        g_slider->setMaximum(255);
        g_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(6, QFormLayout::LabelRole, g_slider);

        b_slider = new QSlider(centralWidget);
        b_slider->setObjectName(QStringLiteral("b_slider"));
        b_slider->setMinimumSize(QSize(120, 0));
        b_slider->setMaximumSize(QSize(120, 16777215));
        b_slider->setMaximum(255);
        b_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(7, QFormLayout::LabelRole, b_slider);

        green_button = new QPushButton(centralWidget);
        green_button->setObjectName(QStringLiteral("green_button"));

        formLayout->setWidget(6, QFormLayout::FieldRole, green_button);

        blue_button = new QPushButton(centralWidget);
        blue_button->setObjectName(QStringLiteral("blue_button"));

        formLayout->setWidget(7, QFormLayout::FieldRole, blue_button);

        presets_label = new QLabel(centralWidget);
        presets_label->setObjectName(QStringLiteral("presets_label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, presets_label);

        off_button = new QPushButton(centralWidget);
        off_button->setObjectName(QStringLiteral("off_button"));

        formLayout->setWidget(8, QFormLayout::FieldRole, off_button);

        info_log_label = new QLabel(centralWidget);
        info_log_label->setObjectName(QStringLiteral("info_log_label"));

        formLayout->setWidget(12, QFormLayout::LabelRole, info_log_label);

        reload_preset_button = new QPushButton(centralWidget);
        reload_preset_button->setObjectName(QStringLiteral("reload_preset_button"));

        formLayout->setWidget(11, QFormLayout::FieldRole, reload_preset_button);

        set_preset_button = new QPushButton(centralWidget);
        set_preset_button->setObjectName(QStringLiteral("set_preset_button"));

        formLayout->setWidget(10, QFormLayout::FieldRole, set_preset_button);

        presets_dropdown = new QComboBox(centralWidget);
        presets_dropdown->setObjectName(QStringLiteral("presets_dropdown"));

        formLayout->setWidget(10, QFormLayout::LabelRole, presets_dropdown);

        info_log_textarea = new QTextEdit(centralWidget);
        info_log_textarea->setObjectName(QStringLiteral("info_log_textarea"));

        formLayout->setWidget(13, QFormLayout::SpanningRole, info_log_textarea);

        controllerWindow->setCentralWidget(centralWidget);

        retranslateUi(controllerWindow);

        QMetaObject::connectSlotsByName(controllerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *controllerWindow)
    {
        controllerWindow->setWindowTitle(QApplication::translate("controllerWindow", "RGB Controller", 0));
        status_label->setText(QApplication::translate("controllerWindow", "Status", 0));
        arduino_status_label->setText(QApplication::translate("controllerWindow", "<font color = red>Disconnected</font>", 0));
        arduino_port_label->setText(QApplication::translate("controllerWindow", "Arduino port", 0));
        refresh_port_button->setText(QApplication::translate("controllerWindow", "Refresh", 0));
        connect_button->setText(QApplication::translate("controllerWindow", "Connect", 0));
        disconnect_button->setText(QApplication::translate("controllerWindow", "Disconnect", 0));
        rgb_label->setText(QApplication::translate("controllerWindow", "RGB colors", 0));
        red_button->setText(QApplication::translate("controllerWindow", "Red", 0));
        green_button->setText(QApplication::translate("controllerWindow", "Green", 0));
        blue_button->setText(QApplication::translate("controllerWindow", "Blue", 0));
        presets_label->setText(QApplication::translate("controllerWindow", "Presets", 0));
        off_button->setText(QApplication::translate("controllerWindow", "Off", 0));
        info_log_label->setText(QApplication::translate("controllerWindow", "Information log", 0));
        reload_preset_button->setText(QApplication::translate("controllerWindow", "Reload", 0));
        set_preset_button->setText(QApplication::translate("controllerWindow", "Set", 0));
    } // retranslateUi

};

namespace Ui {
    class controllerWindow: public Ui_controllerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWINDOW_H
