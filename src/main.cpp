/*
 *
 * Copyleft (C) 2013 by Shang Yuanchun <idealities@gmail.com>
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QApplication>
#include <QDesktopWidget>
#include <QPropertyAnimation>

#include "letter.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Letter *letter = new Letter;

    int screenWidth = QApplication::desktop()->screenGeometry().width();
    int screenHeight= QApplication::desktop()->screenGeometry().height();

    int widgetWidth = letter->frameGeometry().width();
    int widgetHeight= letter->frameGeometry().height();

    QPropertyAnimation initAnimation(letter, "geometry");
    initAnimation.setDuration(INIT_MSEC);

    // Find center position of current desktop
    initAnimation.setStartValue(
                    QRect((screenWidth-widgetWidth) / 2, -widgetHeight, widgetWidth, widgetHeight));
    initAnimation.setEndValue(
                QRect((screenWidth-widgetWidth) / 2, (screenHeight-widgetHeight) / 2,
                  widgetWidth, widgetHeight));
    initAnimation.setEasingCurve(QEasingCurve::OutBounce);

    initAnimation.start();
    letter->show();

    return app.exec();
}
