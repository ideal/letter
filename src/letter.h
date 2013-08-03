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

#ifndef LETTER_H
#define LETTER_H

#include <QWidget>

#define INIT_MSEC 2000

class WelcomePage;
class QTextEdit;

class Letter: public QWidget
{
    Q_OBJECT

public:
    Letter(QWidget *parent = NULL);

public slots:
    void showWelcomePage();
    void removeWelcomePage();
    void showLetter();
    void appendLetter();
    void fireworks();

signals:
    void letterDone();
    void keyMatched(QByteArray keySeq);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QTimer      *welcomeTimer;
    WelcomePage *welcome;
    QTimer      *letterTimer;
    QTextEdit   *letterEdit;
    QString      letterContent;
    int          letterLen;
    int          letterPos;
    QByteArray   keySequence;
    QTimer      *fireworkTimer;
};

#endif
