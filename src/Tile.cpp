#include "Tile.h"

#include "TileWindow.h"

Tile::Tile(const QImage& image, TileSetSize tss, unsigned int x, unsigned int y) : QWidget()
{
    m_imageLabel = new QLabel(this);
    m_imageLabel->setBackgroundRole(QPalette::Base);
    m_imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_imageLabel->setScaledContents(true);
    m_imageLabel->show();
    m_imageLabel->setFixedWidth(tss.sizeX * 2.5f);
    m_imageLabel->setFixedHeight(tss.sizeY * 2.5f);

    setFixedWidth(tss.sizeX * 2.5f);
    setFixedHeight(tss.sizeY * 2.5f);

    setVisible(true);

    QRect rect(
        (x + 1) * tss.sizeX, 
        (y + 1) * tss.sizeY,
        tss.sizeX, tss.sizeY);
    m_image = image.copy(rect);

    m_imageLabel->setPixmap(QPixmap::fromImage(m_image));
}

Tile::~Tile()
{

}

void Tile::clearStyle()
{
    setStyleSheet("");
}

void Tile::mousePressEvent(QMouseEvent* event) 
{
    ((TileWindow*)parentWidget())->mousePressEvent(event);
    ((TileWindow*)parentWidget())->setSelectedTile(this);
    setStyleSheet("border: 2px solid Red");
}

#include "Tile.moc"