#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

Enemy::Enemy()
{
    int random_number = rand()%700;
    setPos(random_number,0);

    //dibuja el enemigo
    setRect(0,0,100,100);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() + rect().height() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
