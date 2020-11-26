#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"

Bullet::Bullet()
{
    //dibuja la bala
    setRect(0,0,10,50);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i < colliding_items.size(); ++i){
        if(typeid (*(colliding_items[i]))== typeid (Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
        }
    }



    setPos(x(),y()-10);
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bala eliminada";
    }
}
