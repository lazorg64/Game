#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    getSettings();

}

settings::~settings()
{
    delete ui;
}

void settings::on_buttonBox_accepted()
{
    setData();
}

void settings::setData()
{
    sfile = new QFile("settings.ini");
    if(sfile->exists())
        cout << "settings file exists" << endl;
    else
        cout << "settings file not exists" << endl;

    sfile->open(QIODevice::WriteOnly);
    bool fs = ui->checkBox->isChecked();
    if(fs)
    sfile->write("fs=true");
    else
    sfile->write("fs=false");
    sfile->close();
}

void settings::getSettings()
{
    QFile * file= new QFile("settings.ini");
    file->open(QIODevice::ReadOnly);

    char * buff = new char[128];
    file->readLine(buff,128);
    string str(buff);

    fs=(str.find("true")!=string::npos);
    ui->checkBox->setChecked(fs);
    file->close();
}
