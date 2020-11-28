#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include "game.h"

extern game * juego;

Bullet::Bullet()
{
    //dibuja la bala
    setPixmap(QPixmap(":/images/Space Invaders Resources/RedBullet.png"));
    setScale(0.25);

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
            //incrementa el puntaje
            juego->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
        }
    }



    setPos(x(),y()-10);
    if(pos().y() + 50 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
