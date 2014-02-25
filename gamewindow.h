#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "gamemodel.h"
#include "modelthread.h"
namespace Ui {
class gamewindow;
}

class gamewindow : public QWidget
{
    Q_OBJECT
    gamemodel * model;
    std::string * state;
public:
    explicit gamewindow(QWidget *parent = 0);
    ~gamewindow();
    std::string * getState();
    void setState(std::string * input);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void selectBuilding(std::string input);
public slots:
    void setBalance(float input);

private:
    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H
