#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "select_building_widget.h"

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);

}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::on_pushButton_2_clicked()
{
    exit(0);
}

void gamewindow::on_pushButton_3_clicked()
{
    select_building_widget * wid = new select_building_widget(this);
    wid->show();
    wid->raise();

    wid->move(width()/2-(wid->width()/2),height()/2-(wid->height()/2));

}
