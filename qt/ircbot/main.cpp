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
