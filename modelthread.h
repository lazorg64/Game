#ifndef MODELTHREAD_H
#define MODELTHREAD_H

#include <QThread>
#include "gamemodel.h"
class ModelThread : public QThread
{
    Q_OBJECT
public:
    ModelThread(gamemodel *ptr);
    void run();
};

#endif // MODELTHREAD_H
