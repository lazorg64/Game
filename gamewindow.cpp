#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "select_building_widget.h"
#include "gamemenu.h"
#include "xernyathread.h"
gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{

//    MThread *t=new MThread();
//    gamemodel m=new gamemodel();//фиктивный
//    t->init(m);
//    t->start();
    ui->setupUi(this);
    model = new gamemodel();
    ui->gamewidget->setModel(model);
    state = new std::string("default");
    ui->gamewidget->setState(state);
    ui->gamewidget->setFocus();
//    t=new MThread();
//    t->init(model);
//    t->start();
    t=new XernyaThread(model);
    t->start();
}

std::string * gamewindow::getState()
{
    return state;
}
void gamewindow::setState(std::string * input)
{
    state = input;
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::on_pushButton_2_clicked()
{
    gamemenu * wid = new gamemenu(this);
    wid->show();
    wid->raise();

    wid->move(width()/2-(wid->width()/2),height()/2-(wid->height()/2));

}

void gamewindow::on_pushButton_3_clicked()
{
    select_building_widget * wid = new select_building_widget(this);
    wid->show();
    wid->raise();
    connect(wid,SIGNAL(selectedBuilding(std::string)),this,SLOT(selectBuilding(std::string)));

    wid->move(width()/2-(wid->width()/2),height()/2-(wid->height()/2));


}



void gamewindow::selectBuilding(std::string input)
{
    cout << "Building selected: "<<input << endl;
    ui->gamewidget->setCurrentBuilding(input);
    *state = "build";
}


