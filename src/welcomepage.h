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
