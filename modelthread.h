#ifndef MODELTHREAD_H
#define MODELTHREAD_H

#include <QThread>
#include "gamemodel.h"
class ModelThread : public QThread
{
    Q_OBJECT
public:
    ModelThread(gamemodel *i);
    gamemodel *ptr;
    void run();
signals:
    void setBalance(float input);
    void setIncome(float input);
};

#endif // MODELTHREAD_H
