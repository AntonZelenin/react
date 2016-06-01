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

    static QMap<int, QGraphicsItem*>::iterator it;

    switch(stimul)
    {
    case figures:
        {
            it = figuresMap.find(randStimul);
            blinc(it.value());
        }
        break;
    case words:
        {

        }
        break;
    case colors:
        {
            //emit changeColor(colorsMap.find(rand() % 3 + 1).value());
            //colRect->setCol();
            blinc(colRect->setCol());
        }
        break;
    case combo:
        {

        }
        break;
    }

    if(isExists())
    {
        this->startTimer(this->exposition);
        --signalsAmount;
    }
    else if (signalsAmount)
        this->startTimer(rand() % 1000 + 1000);
}
