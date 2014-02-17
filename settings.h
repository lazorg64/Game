#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QFile>
#include <iostream>

using namespace std;

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();
    void getSettings();

private slots:
    void on_buttonBox_accepted();

private:
    bool fs;
    Ui::settings *ui;
    QFile * sfile;
    void setData();
};

#endif // SETTINGS_H
