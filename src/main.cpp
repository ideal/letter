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
