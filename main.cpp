#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ******* Create the Scene ********
    QGraphicsScene *scene= new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);

    // *******  Create the View ********
    QGraphicsView * view= new QGraphicsView;
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********
    Player *rect=new Player();
    rect->setPixmap(QPixmap(":/resources/ship.png"));
    scene->addItem(rect);
    // *******  Setting the foucs to the Player ********
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    rect->setPos(view->width()/2,view->height()-100);

   // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->show();

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);


    // Bonus
    QGraphicsTextItem * textscore=new QGraphicsTextItem;
    textscore->setFont(QFont("times", 16));
    textscore->setDefaultTextColor(Qt::black);
    textscore->setPlainText("Your Score: ");
    textscore->setPos(600,10);
    scene->addItem(textscore);
    return a.exec();
}
