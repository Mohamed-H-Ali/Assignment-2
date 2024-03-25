#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
class Health:public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decrease_health();
    int gethealth();
private:
    int health;
};

#endif // SCORE_H
