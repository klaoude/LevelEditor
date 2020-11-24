#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    setFixedSize(800, 600);

    createDockWindows();

    createMenu();

    m_levelWindow = new LevelWindow(m_tileWindow);

    setCentralWidget(m_levelWindow);
}

MainWindow::~MainWindow()
{

}

void MainWindow::OpenTileSet()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Open TileSet", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    //QString fichier = "/home/klaoude/Documents/Code/testEngine/bin/Textures/TileSet.png";
    m_tileWindow->LoadFile(fichier);
}

void MainWindow::Debug()
{
    TileSelectionDialog tsDialog;
    if(tsDialog.exec() == QDialog::Accepted)
    {
        TileSetSize tss = tsDialog.getSize();
        printf("%d, %d, %d, %d\n", tss.sizeX, tss.sizeY, tss.numX, tss.numY);
    }
}

void MainWindow::createDockWindows()
{
    QDockWidget* dock = new QDockWidget(tr("TileSet"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    m_tileWindow = new TileWindow(this);
    dock->setWidget(m_tileWindow);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::createMenu()
{
    QMenu* menuFile = menuBar()->addMenu("&File");
    QAction* actionOpenTileSet = new QAction("&Open TileSet", this);
    QAction* actionQuit = new QAction("&Quit", this);
    menuFile->addAction(actionOpenTileSet);
    menuFile->addAction(actionQuit);
    connect(actionOpenTileSet, SIGNAL(triggered()), this, SLOT(OpenTileSet()));
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu* menuEdit = menuBar()->addMenu("&Edit");
    QAction* actionDebug = new QAction("&Debug", this);
    menuEdit->addAction(actionDebug);
    connect(actionDebug, SIGNAL(triggered()), this, SLOT(Debug()));

    QMenu* menuView = menuBar()->addMenu("&View");
}

#include "../moc/MainWindow.moc"