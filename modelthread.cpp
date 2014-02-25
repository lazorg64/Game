#include "modelthread.h"
#include"gamemodel.h"

ModelThread::ModelThread(gamemodel *input)
{
    ptr=input;
}

void ModelThread::run()
{
    while(true)
    {
        float income = 0;
        foreach(building *cur,ptr->buildings)
        {
            income+=cur->getMoney();
        }
        ptr->balance += income;

        emit setBalance(ptr->balance);
        emit setIncome(income);
        sleep(1);
    }
}
