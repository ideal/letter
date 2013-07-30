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
    painter.drawPixmap(front.rect(), front);
}
