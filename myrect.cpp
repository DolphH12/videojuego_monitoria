#include "myrect.h"
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"

MyRect::MyRect(QGraphicsItem *parent)
{
    bsound = new QMediaPlayer();
    bsound->setMedia(QUrl("qrc:/sounds/bala.mp3"));

    setPixmap(QPixmap(":/images/Space Invaders Resources/RedCannon.png"));
    setScale(0.15);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Space){
        //create bala
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        if(bsound->state() == QMediaPlayer::PlayingState){
            bsound->setPosition(0);
        }
        else if(bsound->state() == QMediaPlayer::StoppedState){
            bsound->play();
        }

    }

}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}






