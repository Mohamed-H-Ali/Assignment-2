#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include <score.h>
#include <game.h>

extern Game * game;
Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    setPixmap(QPixmap(":/images/Resources/laser.png").scaled(10,30));
        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
        // *******  Getting the colliding items with the Bullet ********
        QList<QGraphicsItem *> colliding_items =collidingItems();
        for(int i=0, n=colliding_items.size(); i<n; ++i){
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                game->score->increasescore();
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }
        }

        // *******  Moving the bullets upward ********
        setPos(x(),y()-10);
        if(pos().y()+30<0)
        {
            scene()->removeItem(this);
            delete this;
        }
}
