#pragma once

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QIntValidator>

typedef struct TileSetSize
{
    unsigned int sizeX, sizeY, numX, numY;
} TileSetSize;

class TileSelectionDialog : public QDialog
{
public:
    TileSelectionDialog();
    ~TileSelectionDialog();

    TileSetSize getSize();

private:
    QLineEdit* m_numTilesXtext;
    QLineEdit* m_numTilesYtext;
    QLineEdit* m_sizeTilesXtext;
    QLineEdit* m_sizeTilesYtext;
};