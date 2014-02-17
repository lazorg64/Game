#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "gamewindow.h"
#include "params.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    gamewindow * window = new gamewindow();
    params par;

    if(par.isFullscreen())
    {
        window->showFullScreen();
    }
    else
    {
        window->setFixedHeight(728);
        window->setFixedWidth(1024);
        window->show();

    }

this->hide();



}

void MainWindow::on_pushButton_4_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    settings * window = new settings();
    window->show();
}
