#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:
    Bullet();
    int score;
public slots:
    void move();
};

#endif // BULLET_H
