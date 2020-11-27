#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include <QTimer>
#include "game.h"

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

game * juego;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    juego = new game();
    juego->show();


    return a.exec();
}














