#ifndef SNP_H
#define SNP_H

#include "testbase.h"

class SNP : public TestBase
{
public:
    SNP();

    //��� ��� ��������, ��?? ������ ������� ��������� ����� �� ������ ����� � �����, �������� �� ������� ��������
    ushort getExpo() { return exposition; } const
    ushort getDuration() const { return duration; }

protected:
    ushort exposition;
    ushort duration;

    virtual void timerEvent(QTimerEvent *) {}
};

#endif // SNP_H
