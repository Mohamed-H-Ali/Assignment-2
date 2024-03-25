#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
Game::Game(QWidget *parent) {
    // ******* Create the Scene ********
    QGraphicsScene *scene= new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Player ********
    Player *player=new Player();
    player->setPixmap(QPixmap(":/images/Resources/ship.png").scaled(40,40));
    scene->addItem(player);

    //Create the score
    score = new Score();
    scene->addItem(score);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(scene->width()/2,scene->height()-100);

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

}
