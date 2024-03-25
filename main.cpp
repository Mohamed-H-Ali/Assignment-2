#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "score.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    if(game->chicken->gethealth() < 0){
        game->hide();
    }
    return a.exec();
}
