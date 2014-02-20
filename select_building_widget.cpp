#include "select_building_widget.h"
#include "ui_select_building_widget.h"

select_building_widget::select_building_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_building_widget)
{
    ui->setupUi(this);
    this->raise();


}

select_building_widget::~select_building_widget()
{
    delete ui;
}

void select_building_widget::on_pushButton_2_clicked()
{
    this->close();
}

void select_building_widget::on_pushButton_5_clicked()
{
    this->close();
}
