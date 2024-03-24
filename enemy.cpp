#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include <player.h>
#include <gameover.h>
Enemy::Enemy() {
        // *******  Setting the size of the enemy ********
    setPixmap(QPixmap(":/resources/chicken.jfif").scaled(50,50));

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 701;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()+50>800)
    {
        scene()->removeItem(this);
            delete this;
    }
        QList<QGraphicsItem *> collidingitems =collidingItems();
        for(int i=0, n=collidingitems.size(); i<n; ++i){
            if(typeid(*(collidingitems[i]))==typeid(Player)){
                scene()->removeItem(collidingitems[i]);
                scene()->removeItem(this);
                delete collidingitems[i];
                delete this;
                gameover *page = new gameover;
                page->show();
                return;
            }
        }
}
