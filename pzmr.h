#ifndef PZMR_H
#define PZMR_H
#include "testbase.h"

class PZMR : public TestBase
{

public:
    PZMR();
    ushort getExpo() { return exposition; }
    ushort getSignalsAmount() { return signalsAmount; } const

    //why I can't make it const??
    bool isRightShift() { return isRightSh; }

protected:
    bool isRightSh;
    ushort signalsAmount;
    ushort exposition;

    virtual void timerEvent(QTimerEvent *ev);
};

#endif // PZMR_H
