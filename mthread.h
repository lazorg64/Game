#ifndef MTHREAD_H
#define MTHREAD_H

#include <QThread>
class MThread: public QThread
{
    Q_OBJECT
public:
    MThread();
protected:

    void run();

};

#endif // MODELTHREAD_H
