#include "health.h"
#include <QFont>
Health::Health(QGraphicsItem * parent) :QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

}

void Health::decrease_health()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::gethealth()
{
    return health;
}
