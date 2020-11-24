#pragma once

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QImage>
#include <QImageReader>
#include <QScrollArea>
#include <QLabel>
#include <QPixmap>
#include <QGuiApplication>
#include <QScrollBar>

#include <vector>

#include "Tile.h"
#include "TileSelectionDialog.h"

class TileWindow : public QWidget
{
    Q_OBJECT

public:
    TileWindow(QWidget* parent);
    ~TileWindow();

    bool LoadFile(const QString&);
    void scaleImage(double);

    void setSelectedTile(Tile* t) { m_selectedTile = t; }
    Tile* getSelectedTile() { return m_selectedTile; }

public:
    void mousePressEvent(QMouseEvent *event);

private:
    void setImage(const QImage&);
    void adjustScrollBar(QScrollBar*, double);
    void loadTile(const QImage&, TileSetSize);

    QGridLayout* m_gridLayout;

    QImage m_image;
    QLabel* m_imageLabel;
    QScrollArea* m_scrollArea;
    double m_scaleFactor;

    std::vector<Tile*> m_tiles;

    QAction* m_zoomInAct;
    QAction* m_zoomOutAct;
    QAction* m_normalSizeAct;
    QAction* m_fitToWindowAct;

    Tile* m_selectedTile = nullptr;
};