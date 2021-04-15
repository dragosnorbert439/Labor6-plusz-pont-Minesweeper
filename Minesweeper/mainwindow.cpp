#include "mainwindow.h"
#include "ui_mainwindow.h"

#define devMode false

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    scoreLayout = new QHBoxLayout;
    gameLayout = new QGridLayout;
    bombNumber = new QLCDNumber;
    startButton = new QPushButton;
    menuLayout = new QHBoxLayout;
    gameMenu = new QMenu;
    timer = new Clock;

    // icons
    QPixmap idleP("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/idle.png");
    QPixmap gameoverP("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/gameover.png");
    QPixmap gamewinP("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/gamewin.png");
    QPixmap flagP("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/flag.png");
    QPixmap mine1P("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/mineActiveProc.png");
    QPixmap mine2P("C:/Users/hidde/Documents/GitHub/Minesweeper/img source/minePassiveProc.png");
    idle.addPixmap(idleP); gameover.addPixmap(gameoverP); gamewin.addPixmap(gamewinP); flag.addPixmap(flagP); mine1.addPixmap(mine1P); mine2.addPixmap(mine2P);
    setWindowIcon(mine2);

    // Layout(s)
    gameLayout->setVerticalSpacing(1);
    gameLayout->setHorizontalSpacing(1);
    gameLayout->setSpacing(1);

    // QMenu: gameMenu -> not working properly
    //setupMenu();

    // QLCDNumber
    bombNumber->setSegmentStyle(QLCDNumber::Flat); bombNumber->setDigitCount(3); bombNumber->setStyleSheet("background-color: black; color: red;");
    bombNumber->setFixedSize(QSize(60, 30));

    // Timer
    timer->setSegmentStyle(QLCDNumber::Flat);
    timer->setDigitCount(3);
    timer->setStyleSheet("background-color: black; color: red;");

    // QPushbutton - RESTART
    startButton->setFixedSize(QSize(30,30));
    startButton->setIcon(idle);
    startButton->setIconSize(QSize(25,25));

    QObject::connect(startButton, &QPushButton::clicked, [=]()
    {
        timer->reStart();

        startButton->setIcon(idle);

        tiles.clear();
        for (int i = 0; i < rows; ++i) delete [] values[i];
        delete [] values;

        initializeGame();
    });

    // Initial game start
    initializeGame();

    // Layout(s)
    menuLayout->addWidget(gameMenu);
    mainLayout->addLayout(menuLayout);
    scoreLayout->addWidget(bombNumber);
    scoreLayout->addWidget(startButton);
    scoreLayout->addWidget(timer);
    mainLayout->addLayout(scoreLayout);
    mainLayout->addLayout(gameLayout);

    setStyleSheet("background-color: lightgrey;");
    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}


void MainWindow::initializeGame()
{
    // score
    scoreLayout->setSpacing((cols * 26 - 151)/2);
    bombNumber->display(mines);
    mineCounter = mines;

    // Game and tiles
    tilesLeft = rows * cols - mines;
    // mine field
    values = new int*[rows];
    for (int i = 0; i < rows; ++i) values[i] = new int[cols];
    for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) values[i][j] = 0;

    // random mines
    QVector<short> randMines; // Mine: -1; Empty: 0; Number: >0;
    for (int i = 0; i < rows * cols; ++i) randMines.push_back(i);
    int randMine, mineI, mineJ;
    for (int i = 0; i < mines; ++i)
    {
        randMine = QRandomGenerator().global()->bounded(0, randMines.length() - 1);
        mineI = (randMines[randMine] - (randMines[randMine] % cols))/rows;
        mineJ = randMines[randMine] % cols;

        values[mineI][mineJ] = -1;

        for (int p = -1; p < 2; ++p)
        {
            for (int q = -1; q < 2; ++q)
            {
                if (p + mineI > -1 && q + mineJ > -1 && p + mineI < rows && q + mineJ < cols)
                {
                    if (values[p + mineI][q + mineJ] != -1) values[p + mineI][q + mineJ] += 1;
                }
            }
        }

        randMines.erase(randMines.begin() + randMine);
    }

    // tiles
    for (int i = 0; i < rows; ++i)
    {
        QVector<Tile*> tileRow;
        for (int j = 0; j < cols; ++j)
        {
            Tile *tile = new Tile();
            // LEFT CLICK RELEASE * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            QObject::connect(tile, &Tile::leftReleased, [=]()
            {
                timer->start();
                if (!tile->isFlagged())
                {
                    if (values[i][j] > 0) // Number tile: 1 ... 8
                    {
                        tile->setText(QString::number(values[i][j]));
                        tile->reveal(values[i][j]);
                        --tilesLeft; checkWin();
                    }
                    else if (values[i][j] == 0) // Empty tile: 0
                    {
                        QQueue<QPair<int, int>> que; que.push_back({i,j});
                        QPair<int, int> current;
                        while(!que.isEmpty())
                        {
                            current = que.first();
                            for (int p = -1; p < 2; ++p)
                            {
                                for (int q = -1; q < 2; ++q)
                                {
                                    // game border filter
                                    if (p + current.first > -1 && q + current.second > -1 && p + current.first < rows && q + current.second < cols)
                                    {
                                        // repeats filter
                                        if (!tiles[p + current.first][q + current.second]->isRevealed())
                                        {
                                            tiles[p + current.first][q + current.second]->reveal(values[p + current.first][q + current.second]); --tilesLeft;
                                            if (values[p + current.first][q + current.second] > 0)
                                            {
                                                tiles[p + current.first][q + current.second]->setText(QString::number(values[p + current.first][q + current.second]));
                                            }
                                            else if (values[p + current.first][q + current.second] == 0)
                                            {
                                                que.push_back({p + current.first, q + current.second});
                                            }
                                        }
                                    }
                                }
                            }
                            que.pop_front();
                        }
                        checkWin();
                    }
                    else // Mine: -1
                    {
                        timer->stop();
                        for (int k = 0; k < rows; ++k)
                        {
                            for (int v = 0; v < cols; ++v)
                            {
                                if (values[k][v] == -1)
                                {
                                    tiles[k][v]->setIcon(mine2);
                                }
                                tiles[k][v]->reveal(-1);
                            }
                        }
                        tiles[i][j]->setIcon(mine1);
                        startButton->setIcon(gameover);
                    }
                }
            });
            // RIGHT CLICK RELEASE => FLAGGING * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            QObject::connect(tile, &Tile::rightReleased, [=]()
            {
                if (!tile->isRevealed())
                {
                    if(tile->isFlagged())
                    {
                        tile->deFlag(); tile->setIcon(QIcon()); bombNumber->display(++mineCounter);
                    }
                    else
                    {
                        tile->flag(); tile->setIcon(flag); bombNumber->display(--mineCounter);
                    }
                }
            });
            // LEFT CLICK on a NUMBER (revealed) tile * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            QObject::connect(tile, &Tile::leftPressedRevealed, [=]()
            {
                for (int p = -1; p < 2; ++p)
                {
                    for (int q = -1; q < 2; ++q)
                    {
                        if (p + i > -1 && q + j > -1 && p + i < rows && q + j < cols && tiles[p+i][q+j]->getState() == 0 && !tiles[p+i][q+j]->isFlagged() && !tiles[p+i][q+j]->isRevealed())
                        {
                            if(tiles[i][j]->getState() == 0)tiles[i][j]->setDown(true);
                        }
                    }
                }
            });

            // LEFT CLICK RELEASE on a NUMBER (revealed) tile * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            QObject::connect(tile, &Tile::leftReleasedRevealed, [=]()
            {
                int numFlagged = 0;
                for (int p = -1; p < 2; ++p)
                {
                    for (int q = -1; q < 2; ++q)
                    {
                        if (p + i > -1 && q + j > -1 && p + i < rows && q + j < cols)
                        {
                            if (tiles[p+i][q+j]->isFlagged()) ++numFlagged;
                        }
                    }
                }
                if (numFlagged != values[i][j]) return;

                if (tiles[i][j]->isRevealed())
                {
                    for (int p = -1; p < 2; ++p)
                    {
                        for (int q = -1; q < 2; ++q)
                        {
                            // FILTERS: game border, tiles only if idle
                            if (p + i > -1 && q + j > -1 && p + i < rows && q + j < cols && tiles[p+i][q+j]->getState() == 0 && !tiles[p+i][q+j]->isFlagged() && !tiles[p+i][q+j]->isRevealed())
                            {
                                tiles[i][j]->setDown(false);
                                if (values[p+i][q+j] > 0) // Number tile: 1 ... 8
                                {
                                    tiles[p+i][q+j]->setText(QString::number(values[p+i][q+j]));
                                    tiles[p+i][q+j]->reveal(values[p+i][q+j]);
                                    --tilesLeft; checkWin();
                                }
                                else if (values[p+i][q+j] == 0) // Empty tile: 0
                                {
                                    QQueue<QPair<int, int>> que; que.push_back({i,j});
                                    QPair<int, int> current;
                                    while(!que.isEmpty())
                                    {
                                        current = que.first();
                                        for (int k = -1; k < 2; ++k)
                                        {
                                            for (int v = -1; v < 2; ++v)
                                            {
                                                // game border filter
                                                if (k + current.first > -1 && v + current.second > -1 && k + current.first < rows && v + current.second < cols)
                                                {
                                                    // repeats filter
                                                    if (!tiles[k + current.first][v + current.second]->isRevealed() && !tiles[k + current.first][v + current.second]->isFlagged())
                                                    {
                                                        tiles[k + current.first][v + current.second]->reveal(values[k + current.first][v + current.second]); --tilesLeft;
                                                        if (values[k + current.first][v + current.second] > 0)
                                                        {
                                                            tiles[k + current.first][v + current.second]->setText(QString::number(values[k + current.first][v + current.second]));
                                                        }
                                                        else if (values[k + current.first][v + current.second] == 0)
                                                        {
                                                            que.push_back({k + current.first, v + current.second});
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        que.pop_front();
                                    }

                                    checkWin();
                                }
                                else // Mine: -1
                                {
                                    timer->stop();
                                    for (int k = 0; k < rows; ++k)
                                    {
                                        for (int v = 0; v < cols; ++v)
                                        {
                                            if (values[k][v] == -1)
                                            {
                                                tiles[k][v]->setIcon(mine2);
                                            }
                                            tiles[k][v]->reveal(-1);
                                        }
                                    }
                                    tiles[i][j]->setIcon(mine1);
                                    startButton->setIcon(gameover);
                                }
                            }
                        }
                    }
                }
            });

            if (devMode) tile->setText(QString::number(values[i][j]));
            tileRow.push_back(tile);
        }
        tiles.push_back(tileRow);
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            gameLayout->addWidget(tiles[i][j], i, j);
        }
    }
}


void MainWindow::checkWin()
{
    if (tilesLeft == 0)
    {
        timer->stop();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j) // only bombs, no need to change stylesheet
            {
                if (values[i][j] == -1)
                {
                    tiles[i][j]->flag();
                    tiles[i][j]->reveal(9);
                    tiles[i][j]->setIcon(flag);
                }
            }
        }
        bombNumber->display(0);
        startButton->setIcon(gamewin);
    }
}


void MainWindow::setupMenu()
{
    QMenu *difficulity = new QMenu(); difficulity->setTitle("Game");
    auto *beginner = new QAction("Beginner", this); difficulity->addAction(beginner);
    auto *intermediate = new QAction("Intermediate", this); difficulity->addAction(intermediate);
    auto *expert = new QAction("Expert", this); difficulity->addAction(expert);
    QObject::connect(beginner, &QAction::triggered, [=]()
    {

    });
    QObject::connect(intermediate, &QAction::triggered, [=]()
    {

    });
    QObject::connect(expert, &QAction::triggered, [=]()
    {

    });
    gameMenu->addMenu(difficulity);
}















