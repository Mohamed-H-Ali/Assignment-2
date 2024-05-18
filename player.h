#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QAudioOutput>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem
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

private:
    QAudioOutput *bullet;
    QMediaPlayer *bullett;

};

#endif // PLAYER_H
