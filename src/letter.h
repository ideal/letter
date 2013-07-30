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

signals:
    void letterDone();

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
};

#endif
