#ifndef XERNYATHREAD_H
#define XERNYATHREAD_H

#include <QThread>
#include <gamemodel.h>
class XernyaThread : public QThread
{
public:
    XernyaThread(gamemodel *uk);
public:
    void run();
};
#endif // XERNYATHREAD_H



