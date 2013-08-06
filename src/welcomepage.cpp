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

#include "welcomepage.h"

#include <QPropertyAnimation>
#include <QPainter>


WelcomePage::WelcomePage(QWidget *parent)
            :QWidget(parent)
{
    m_opacity = 0.0;
    front = QPixmap(":/data/front.png");

    // need to call repaint() when opacity changed
    connect(this, SIGNAL(opacityChanged(qreal)), this, SLOT(repaint()));
}

void WelcomePage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setOpacity(m_opacity);
    painter.drawPixmap(QRect(0, 0, 800, 600), front.scaled(800, 600));
}
