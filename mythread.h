#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>

using namespace std;
class MyThread: public QThread
{
    Q_OBJECT
public:
    MyThread();

    void run();

};

#endif // MYTHREAD_H
