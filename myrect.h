#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QDebug>
#include <QObject>

class MyRect:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyRect();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // MYRECT_H
