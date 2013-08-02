/*
 *
 * Copyleft (C) 2013 by Shang Yuanchun <idealities@gmail.com>
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version.
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

#include "firework.h"

Firework::Firework(QWidget *parent)
         :QWidget(parent)
{
    antialiased = true;
    frameNumber = 0;
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Firework::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

QSize Firework::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize Firework::sizeHint() const
{
    return QSize(200, 200);
}

void Firework::addFrame()
{
    this->frameNumber ++;
    update();
}

void Firework::paintEvent(QPaintEvent *event)
{
}
