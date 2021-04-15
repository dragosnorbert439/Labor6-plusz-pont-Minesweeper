#include "Tile.h"

Tile::Tile(QWidget *parent) : QPushButton(parent)
{
    setFixedHeight(25);
    setFixedWidth(25);
    setStyleSheet("background-color: blue");
    state = 0;
    setIconSize(QSize(20,20));
}

Tile::~Tile()
{
}

void Tile::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        if (this->isFlagged()) return;
        else if (this->isRevealed()) emit leftPressedRevealed();
        else
        {
            setDown(true);
            emit leftPressed();
        }
    }
    if (e->button() == Qt::RightButton)
    {
        emit rightPressed();
    }
}

void Tile::mouseReleaseEvent(QMouseEvent *e)
{
    QPoint pos = e->pos();
    if (e->button() == Qt::LeftButton)
    {
        if (this->isFlagged()) return;
        else if (this->isRevealed())
        {
            emit leftReleasedRevealed();
        }
        else
        {
            setDown(false);
            if (rect().contains(pos))
            {
                emit leftReleased();
            }
        }
    }
    if (e->button() == Qt::RightButton)
    {
        if (this->isRevealed()) return;
        else
        {
            if (rect().contains(pos))
            {
                emit rightReleased();
            }
        }
    }
}

void Tile::reveal(int value)
{
    state = 2;

    if (value == 0)
    {
        setStyleSheet("background-color: lightgrey;");
    }
    if (value == 1)
    {
       setStyleSheet("background-color: lightgrey; font-size: 15px; color: blue; font-weight: bold;");
    }
    if (value == 2)
    {
       setStyleSheet("background-color: lightgrey; font-size: 15px; color: green; font-weight: bold;");
    }
    if (value == 3)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: red; font-weight: bold;");
    }
    if (value == 4)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: darkblue; font-weight: bold;");
    }
    if (value == 5)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: maroon; font-weight: bold;");
    }
    if (value == 6)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: cyan; font-weight: bold;");
    }
    if (value == 7)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: black; font-weight: bold;");
    }
    if (value == 8)
    {
        setStyleSheet("background-color: lightgrey; font-size: 15px; color: grey; font-weight: bold;");
    }
}







