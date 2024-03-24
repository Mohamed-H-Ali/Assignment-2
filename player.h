#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
public:
    int score;
    QGraphicsTextItem *scorevalue;

public slots:
    void keyPressEvent(QKeyEvent * event);
    void createEnemy();
};

#endif // PLAYER_H
