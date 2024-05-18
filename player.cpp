#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "game.h"
#include "QMessageBox"
extern Game * game;
Player::Player() {
    QAudioOutput *bullet = new QAudioOutput;
    bullet->setVolume(100);
    bullett = new QMediaPlayer;
    bullett->setAudioOutput(bullet);
    bullett->setSource(QUrl("qrc:/sound/Resources/shotgun-firing-4-6746.mp3"));

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+15,y());
        bullett->play();
        scene()->addItem(bullet);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{
    if(game->chicken->gethealth() < 0){
        game->hide();
        QMessageBox::about(game,"Gameover.","Your score is: "+ QString::number(game->score->getscore()));
        exit(1);
    }
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
