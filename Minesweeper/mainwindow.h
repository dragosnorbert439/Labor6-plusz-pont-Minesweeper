#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QMenu>
#include <QRandomGenerator>
#include <QVector>
#include <QMouseEvent>
#include <QMessageBox>
#include <QQueue>
#include <QPair>
#include <QPixmap>
#include "Tile.h"
#include "Clock.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRows(int);
    void setCols(int);
    void setMines(int);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getMines() const { return mines; }
    void initializeGame();
    void checkWin();
    void setupMenu();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *scoreLayout;
    QGridLayout *gameLayout;
    QLCDNumber *bombNumber;
    QPushButton *startButton;
    QMenu *gameMenu;
    QHBoxLayout *menuLayout;
    int **values;
    Clock *timer;
    QVector<QVector<Tile*>> tiles;

    int tilesLeft {71};
    int rows {9};
    int cols {9};
    int mines {10};
    QIcon gameover, gamewin, idle, flag, mine1, mine2;
    int mineCounter {10};
};
#endif // MAINWINDOW_H
