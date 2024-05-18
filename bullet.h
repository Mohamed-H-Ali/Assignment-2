#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QAudioOutput>
#include <QMediaPlayer>

class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Bullet();
public slots:
    void move();

private:
    QAudioOutput *enemy;
    QMediaPlayer *chicken;


};

#endif // BULLET_H
