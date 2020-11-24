#pragma once

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMdiArea>
#include <QDockWidget>

#include "TileWindow.h"
#include "LevelWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

public slots:
    void OpenTileSet();
    void Debug();

private:
    void createDockWindows();
    void createMenu();

    TileWindow* m_tileWindow;
    LevelWindow* m_levelWindow;
};