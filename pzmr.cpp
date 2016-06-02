#include "pzmr.h"
#include <ctime>
#include "ui_testbase.h"

PZMR::PZMR()
{
    isRightSh = true;

    srand(time(NULL));
}

void PZMR::timerEvent(QTimerEvent *ev)
{
    killTimer(ev->timerId());
    exists = !exists;

    //because we have 3 kimds of stimuls
    ushort randStimul = rand() % 3 + 1;

    static QMap<int, QGraphicsItem*>::iterator itF;
    static QMap<int, QString>::iterator itW;

    switch(stimul)
    {
    case figures:
        {
            itF = figuresMap.find(randStimul);
            blinc(itF.value());
        }
        break;
    case words:
        {
            itW = wordsMap.find(randStimul);
            wordsStimul->setPos(120, 70);
            wordsStimul->setPlainText(itW.value());
            wordsStimul->setDefaultTextColor(Qt::red);
            wordsStimul->setScale(10);

            blinc(wordsStimul);
        }
        break;
    case colors:
        {
            blinc(colRect->setCol());
        }
        break;
    case combo:
        {

        }
        break;
    }

    if(isExists() && this->isFullScreen())
    {
        //this->startTimer(this->exposition);
        this->startTimer(200);
        --signalsAmount;
    }
    else if (signalsAmount && this->isFullScreen())
        //this->startTimer(rand() % 1000 + 1000);
        this->startTimer(200);
    else
        this->close();
}
