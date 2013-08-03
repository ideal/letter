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

#include <QPainter>

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
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, this->antialiased);
    painter.translate(width() / 2, height());

    for (int d = 0; d < 256; d+= 8) {
        uint delta = qAbs((this->frameNumber) % 128 - d / 2);
        int  alpha = 255 - (delta * delta) / 4 - d;

        if (alpha <= 0)
            continue;

        painter.setPen(QPen(QColor(), 4));
        painter.drawEllipse(QRect(-d / 2, -d / 2, d, d));
    }
}
