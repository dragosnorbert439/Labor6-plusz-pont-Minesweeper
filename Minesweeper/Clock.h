#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QLCDNumber>
#include <QTimer>

class Clock : public QLCDNumber
{
    Q_OBJECT
private:
    int seconds {0};
    bool started {false};

public:
    Clock(QWidget *parent = nullptr);
    void start() { if(!started) started = true; }
    void reStart() { started = false; seconds = 0; display(0); }
    void stop() { started = false; }

private slots:
    void showTime();
};

#endif // CLOCK_H
