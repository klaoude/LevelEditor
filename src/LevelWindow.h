#pragma once

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

#include "Tile.h"

class TileWindow;

class LevelWindow : public QGraphicsView
{
    Q_OBJECT

public:
    LevelWindow(TileWindow* tw);
    ~LevelWindow();
    
protected:
    void mousePressEvent(QMouseEvent *event);

private:
    TileWindow* m_tileWindow;

    QGraphicsScene* m_scene;
}; 