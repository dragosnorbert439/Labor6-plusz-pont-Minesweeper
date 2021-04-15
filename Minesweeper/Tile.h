#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QEvent>

class Tile : public QPushButton
{
    Q_OBJECT

private:
    short state; // 0 = idle, 1 = flagged, 2 = revealed

public:
    Tile(QWidget *parent = 0);
    ~Tile();
    bool isFlagged() const { return state == 1; }
    bool isRevealed() const { return state == 2; }
    void flag() { if (state == 0) state = 1; }
    void deFlag() { if(state == 1) state = 0; }
    void reveal(int);
    short getState() const { return state; }

private slots:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:
    void leftPressed();
    void leftReleased();
    void rightPressed();
    void rightReleased();
    void leftPressedRevealed();
    void leftReleasedRevealed();
};

#endif // TILE_H
