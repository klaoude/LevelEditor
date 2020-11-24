#pragma once

#include <QImage>
#include <QWidget>
#include <QLabel>

#include "TileSelectionDialog.h"

class TileWindow;

class Tile : public QWidget
{
    Q_OBJECT

public:
    Tile(const QImage&, TileSetSize, unsigned int x, unsigned int y);
    ~Tile();

    void clearStyle();

    QImage getImage() { return m_image; }

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QLabel* m_imageLabel;
    QImage m_image;
};