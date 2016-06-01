#ifndef PZMR_H
#define PZMR_H
#include "testbase.h"

class PZMR : public TestBase
{

public:
    PZMR();
    ushort getExpo() const { return exposition; }
    ushort getSignalsAmount() const { return signalsAmount; }

    bool isRightShift() const { return isRightSh; }

protected:
    bool isRightSh;
    ushort signalsAmount;
    ushort exposition;

    virtual void timerEvent(QTimerEvent *ev);
};

#endif // PZMR_H
