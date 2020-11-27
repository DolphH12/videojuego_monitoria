#include "game.h"

game::game(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new MyRect();
    player->setRect(0,0,100,100);
    player->setPos(width()/2-player->rect().width()/2,height()-player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QTimer *timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();

}
