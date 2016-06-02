#ifndef PZMR_H
#define PZMR_H
#include "testbase.h"

class PZMR : public TestBase
{

public:
    PZMR();
    void setExpo(short val) { exposition = val; }
    ushort getExpo() const { return exposition; }

    bool isRightShift() const { return isRightSh; }

protected:
    bool isRightSh;
    ushort exposition;

    virtual void timerEvent(QTimerEvent *ev);
};

#endif // PZMR_H
