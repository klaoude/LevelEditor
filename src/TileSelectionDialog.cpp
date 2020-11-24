#include "TileSelectionDialog.h"

TileSelectionDialog::TileSelectionDialog() : QDialog()
{
    setLayout(new QHBoxLayout());

    QLabel* numXlabel = new QLabel("Number of Tiles in X axis: ");
    QLabel* numYlabel = new QLabel("Number of Tiles in Y axis: ");
    QLabel* sizeXlabel = new QLabel("Size of Tiles in X axis: ");
    QLabel* sizeYlabel = new QLabel("Size of Tiles in Y axis: ");

    m_numTilesXtext = new QLineEdit();
    m_numTilesXtext->setValidator(new QIntValidator(0, 999999, this));
    m_numTilesYtext = new QLineEdit();
    m_numTilesYtext->setValidator(new QIntValidator(0, 999999, this));
    m_sizeTilesXtext = new QLineEdit();
    m_sizeTilesXtext->setValidator(new QIntValidator(0, 999999, this));
    m_sizeTilesYtext = new QLineEdit();
    m_sizeTilesYtext->setValidator(new QIntValidator(0, 999999, this));

    QPushButton* ok = new QPushButton("Ok");

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(numXlabel, 0, 0);
    gridLayout->addWidget(numYlabel, 1, 0);
    gridLayout->addWidget(sizeXlabel, 2, 0);
    gridLayout->addWidget(sizeYlabel, 3, 0);
    gridLayout->addWidget(m_numTilesXtext, 0, 1);
    gridLayout->addWidget(m_numTilesYtext, 1, 1);
    gridLayout->addWidget(m_sizeTilesXtext, 2, 1);
    gridLayout->addWidget(m_sizeTilesYtext, 3, 1);
    gridLayout->addWidget(ok, 4, 0, 1, 2);

    QWidget* widget = new QWidget();
    widget->setLayout(gridLayout);

    layout()->addWidget(widget);

    connect(ok, &QPushButton::clicked, this, [=](){ accept(); });
}

TileSelectionDialog::~TileSelectionDialog()
{

}

TileSetSize TileSelectionDialog::getSize()
{
    TileSetSize ret;
    ret.sizeX = m_sizeTilesXtext->text().toInt();
    ret.sizeY = m_sizeTilesYtext->text().toInt();
    ret.numX = m_numTilesXtext->text().toInt();
    ret.numY = m_numTilesYtext->text().toInt();
    return ret;
}