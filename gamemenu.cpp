#include "gamemenu.h"
#include "ui_gamemenu.h"

gamemenu::gamemenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemenu)
{
    ui->setupUi(this);
}

gamemenu::~gamemenu()
{
    delete ui;
}

void gamemenu::on_pushButton_4_clicked()
{
    exit(0);
}

void gamemenu::on_pushButton_clicked()
{
    this->close();
}
