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

#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include <QPixmap>

#define CHANGE_MSEC 8000

class WelcomePage: public QWidget
{
    Q_OBJECT

    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)

public:
    WelcomePage(QWidget *parent = NULL);

    qreal opacity() const { return m_opacity; }
    void setOpacity(qreal opacity)
    {
        m_opacity = opacity;
        emit opacityChanged(opacity);
    }

signals:
    void welcomePageLoaded();
    void opacityChanged(qreal opacity);

protected:
    void paintEvent(QPaintEvent *event);

private:
    qreal m_opacity;
    QPixmap front;
};

#endif
