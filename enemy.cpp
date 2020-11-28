#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <game.h>

extern game * juego;

Enemy::Enemy()
{
    int random_number = rand()%700;
    setPos(random_number,0);

    //dibuja el enemigo
    setPixmap(QPixmap(":/images/Space Invaders Resources/BlueAlien.png"));
    setScale(0.10);
    setTransformOriginPoint(50,50);
    setRotation(180);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 600){
        juego->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
