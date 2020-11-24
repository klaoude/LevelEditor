#include "LevelWindow.h"
#include "TileWindow.h"

LevelWindow::LevelWindow(TileWindow* tw) : QGraphicsView()
{
    m_tileWindow = tw;
    setWindowTitle("Level Editor");

    m_scene = new QGraphicsScene(this);
    setScene(m_scene);

    QBrush brush = QBrush(Qt::CrossPattern);
    brush.setColor(Qt::gray);
    brush.setTransform(brush.transform().scale(3, 3));
    setBackgroundBrush(brush);
}

LevelWindow::~LevelWindow()
{

}

void LevelWindow::mousePressEvent(QMouseEvent* event)
{
    printf("LevelWindow::mousePressEvent()\n");
    if(m_tileWindow == nullptr)
        return;

    Tile* tile = m_tileWindow->getSelectedTile();

    if(tile == nullptr)
        return;

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(tile->getImage()));
    QPoint point = event->pos();
    //m_scene->
    item->setPos(point.x(), point.y());
    item->setScale(4.f);

    m_scene->addItem(item);
}

#include "../moc/LevelWindow.moc"