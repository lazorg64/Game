#include "select_building_widget.h"
#include "ui_select_building_widget.h"

select_building_widget::select_building_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_building_widget)
{
    ui->setupUi(this);
    this->raise();
    parent_link = parent;


}

select_building_widget::~select_building_widget()
{
    delete ui;
}

void select_building_widget::on_pushButton_2_clicked()
{
    emit selectedBuilding("smallhouse");
    this->close();
}

void select_building_widget::on_pushButton_5_clicked()
{
    this->close();
}

void select_building_widget::on_pushButton_clicked()
{
    emit selectedBuilding("factory");
    this->close();
}

void select_building_widget::on_pushButton_3_clicked()
{
    emit selectedBuilding("hospital");
    this->close();
}

void select_building_widget::on_pushButton_4_clicked()
{
    emit selectedBuilding("bar");
    this->close();
}
