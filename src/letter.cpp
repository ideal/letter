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

#include "letter.h"

#include <QHBoxLayout>
#include <QTimer>
#include <QPropertyAnimation>
#include <QTextEdit>
#include <QTextCodec>
#include <QKeyEvent>

#include "welcomepage.h"
#include "firework.h"

static const char *content = "目击众神死亡的草原上野花一片\n"
                             "远在远方的风比远方更远\n"
                             "我的琴声呜咽 泪水全无\n"
                             "我把这远方的远归还草原\n"
                             "一个叫木头 一个叫马尾\n"
                             "我的琴声呜咽 泪水全无\n"
                             "\n"
                             "\n"
                             "远方只有在死亡中凝聚野花一片\n"
                             "明月如镜 高悬草原 映照千年岁月\n"
                             "我的琴声呜咽 泪水全无\n"
                             "只身打马过草原\n"
                             "From 海子 <九月>\n";

static const QByteArray name("\x68\x65\x68\x6f\x6e\x67\x6c\x69\x6e\x67");

Letter::Letter(QWidget *parent)
         :QWidget(parent)
{
    setMinimumSize(800, 600);
    setWindowTitle(tr("A letter from somewhere..."));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    setLayout(layout);

    welcome    = NULL;
    letterEdit = NULL;
    letterPos  = 0;

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    letterContent = codec->toUnicode(content);
    letterLen     = letterContent.length();

    welcomeTimer = new QTimer(this);
    welcomeTimer->singleShot(INIT_MSEC, this, SLOT(showWelcomePage()));

    fireworkTimer = NULL;
}

void Letter::showWelcomePage()
{
    welcome = new WelcomePage(this);
    connect(welcome, SIGNAL(welcomePageLoaded()), this, SLOT(removeWelcomePage()));

    QPropertyAnimation *welAnimation = new QPropertyAnimation(welcome, "opacity");
    welAnimation->setDuration(CHANGE_MSEC);
    welAnimation->setStartValue(0.0);
    welAnimation->setEndValue(0.0);
    welAnimation->setKeyValueAt(0.8, 1);
    connect(welAnimation, SIGNAL(finished()), welcome, SIGNAL(welcomePageLoaded()));
    connect(welAnimation, SIGNAL(finished()), this, SLOT(showLetter()));

    this->layout()->addWidget(welcome);

    welAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Letter::removeWelcomePage()
{
    this->layout()->removeWidget(welcome);
    delete welcome;
    delete welcomeTimer;
}

void Letter::showLetter()
{
    letterEdit = new QTextEdit(this);
    letterEdit->setReadOnly(true);
    letterEdit->setAlignment(Qt::AlignHCenter);
    letterEdit->setFontPointSize(12);
    QPalette bgPalette;
    QPixmap  bgPixmap(":/data/letter.png");
    bgPalette.setBrush(QPalette::Base, QBrush(bgPixmap));
    letterEdit->setPalette(bgPalette);
    letterTimer = new QTimer(this);
    connect(letterTimer, SIGNAL(timeout()), this, SLOT(appendLetter()));
    this->layout()->addWidget(letterEdit);
    letterTimer->start(200);

    keySequence.clear();
    connect(this, SIGNAL(keyMatched(QByteArray)), this, SLOT(fireworks()));
}

void Letter::appendLetter()
{
    if (!letterEdit)
        return;
    letterEdit->textCursor().insertText(letterContent.at(letterPos));
    letterPos++;
    if (letterPos == letterLen) {
        letterTimer->stop();
        delete letterTimer;
        emit letterDone();
    }
}

void Letter::fireworks()
{
    if (!fireworkTimer) {
        fireworkTimer = new QTimer(this);
        fireworkTimer->start(100);
    }
    Firework *firework = new Firework();
    connect(fireworkTimer, SIGNAL(timeout()), firework, SLOT(addFrame()));
    firework->show();
}

void Letter::keyPressEvent(QKeyEvent *event)
{
    keySequence.append(event->text());
    if (keySequence.size() == name.size()) {
        if (keySequence == name) {
            emit keyMatched(keySequence);
        }
        keySequence.clear();
    }
    QWidget::keyPressEvent(event);
}
