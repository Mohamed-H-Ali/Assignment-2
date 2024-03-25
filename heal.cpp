#include "heal.h"
#include <QFont>
heal::heal(QGraphicsItem * parent) :QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

}


void heal::decrease_health()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int heal::gethealth()
{
    return health;
}

