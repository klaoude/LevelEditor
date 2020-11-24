#include "TileWindow.h"

TileWindow::TileWindow(QWidget* parent) : QWidget()
{
    m_gridLayout = new QGridLayout();
    setLayout(m_gridLayout);

    setWindowTitle(tr("TileSet Viewer"));
}

TileWindow::~TileWindow()
{

}

bool TileWindow::LoadFile(const QString& path)
{
    QImageReader reader(path);
    reader.setAutoTransform(true);
    m_image = reader.read();
    if(m_image.isNull())
    {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(path), reader.errorString()));
        return false;
    }
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(), "Image loaded !");

    /*TileSelectionDialog tsDialog;
    if(tsDialog.exec() == QDialog::Accepted)
    {
        TileSetSize tss = tsDialog.getSize();
        loadTile(m_image, tss);
    }    */
    TileSetSize tss = {10, 10, 16, 16};
    loadTile(m_image, tss);

    return true;
}

void TileWindow::scaleImage(double factor)
{
    m_imageLabel->resize(factor * m_imageLabel->pixmap()->size());

    adjustScrollBar(m_scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(m_scrollArea->verticalScrollBar(), factor);
}

void TileWindow::mousePressEvent(QMouseEvent* event)
{
    for(auto tile : m_tiles)
        tile->clearStyle();
}

void TileWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}

void TileWindow::loadTile(const QImage& image, TileSetSize tss)
{
    for(unsigned int i = 0; i < tss.numY; i++)
    {
        for(unsigned int j = 0; j < tss.numX; j++)
        {
            m_tiles.push_back(new Tile(image, tss, j, i));
            m_gridLayout->addWidget(m_tiles[i * tss.numX + j], j, i);
        }
    }

    const float SCALE = 3.f;

    setFixedSize(tss.numX * tss.sizeX * SCALE, tss.numY * tss.sizeY * SCALE);
    setVisible(true);
}

#include "../moc/TileWindow.moc"