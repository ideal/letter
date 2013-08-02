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

#ifndef FIREWORK_H
#define FIREWORK_H

#include <QWidget>

class Firework: public QWidget
{
    Q_OBJECT

public:
    Firework(QWidget *parent = NULL);

    void setAntialiased(bool antialased);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void addFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool    antialiased;
    quint16 frameNumber;
};

#endif
