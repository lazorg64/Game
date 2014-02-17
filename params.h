#ifndef PARAMS_H
#define PARAMS_H
#include <QFile>
#include <iostream>

using namespace std;

class params
{
    QFile * sfile;
    bool fs;

public:
    params();
    bool isFullscreen();
    void setDefault();
    void getSettings();
};

#endif // PARAMS_H
