#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include "score.h"
#include "health.h"
#include <QTimer>

class game: public QGraphicsView
{
public:
    game(QWidget * parent = 0);

    QGraphicsScene * scene;
    MyRect * player;
    Score * score;
    Health * health;

};

#endif // GAME_H
