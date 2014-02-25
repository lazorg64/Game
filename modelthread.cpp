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
        foreach(building *cur,ptr->buildings)
        {
            ptr->balance+=cur->getMoney();
        }
        emit setBalance(ptr->balance);
        sleep(60);
    }
}
