#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include <QTimer>

/*
-Memoria dinamica, punteros.
-widgets
-QGraphicsScene
-QGraphicsItem
-QGraphicsView
-QKeyEvent
-QDebug
-QTimer
-signals and slots (connect)
-QObject --- MACRO
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //crear una escena.
    QGraphicsScene * scene = new QGraphicsScene();

    //crear Item para poner en la scena.
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    //Enfocar el item
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //añadir item a la scena
    scene->addItem(player);

    //añadir el view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2-player->rect().width()/2,view->height()-player->rect().height());

    QTimer *timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    return a.exec();
}














