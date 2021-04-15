#include "Clock.h"

Clock::Clock(QWidget *parent) : QLCDNumber(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::showTime);
    timer->start(1000);

    showTime();
    setFixedSize(QSize(60, 30));
}

void Clock::showTime()
{
    if (!started) return;
    ++seconds;
    display(seconds);
}
