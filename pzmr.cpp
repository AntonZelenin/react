#include "pzmr.h"
#include <ctime>
#include "ui_testbase.h"

PZMR::PZMR()
{
    signalsAmount = 30;
    exposition = 700;
    isRightSh = true;
}

void PZMR::timerEvent(QTimerEvent *ev)
{
    killTimer(ev->timerId());
    exists = !exists;

    srand(time(NULL));

    //because we have 3 kimds of stimuls
    ushort randStimul = rand() % 3 + 1;

    QMap<int, QGraphicsItem*>::iterator it = figuresMap.find(randStimul);
    blinc(it.value());

    if(isExists())
        this->startTimer(this->exposition);
    else
        this->startTimer(rand() % 1000 + 1000);
}
