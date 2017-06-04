#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <qtbot.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	QtBot qtbot;
	QObject::connect(&qtbot, SIGNAL(done()), &a, SLOT(quit()), Qt::QueuedConnection);
	QTimer::singleShot(0, &qtbot, SLOT(setup()));
    return a.exec();
}
