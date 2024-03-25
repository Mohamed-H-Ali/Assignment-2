#ifndef HEAL_H
#define HEAL_H
#include <QGraphicsTextItem>
class heal: public QGraphicsTextItem
{
public:
    heal(QGraphicsItem * parent=0);
    void decrease_health();
    int gethealth();
private:
    int health;
};


#endif // HEAL_H
