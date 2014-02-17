#include "params.h"

params::params()
{
    sfile = new QFile("settings.ini");
    if(sfile->exists())
    {
        cout << "settings file exists" << endl;
        getSettings();
    }
    else
    {
        cout << "settings file not exists" << endl;
        setDefault();
    }
}

bool params::isFullscreen()
{
    return fs;
}

void params::setDefault()
{
    fs = true;
}

void params::getSettings()
{
    sfile->open(QIODevice::ReadOnly);
    char * buff = new char[128];
    sfile->readLine(buff,128);
    string str(buff);
    fs=(str.find("true")!=string::npos);

    sfile->close();
}
