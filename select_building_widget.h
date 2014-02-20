#ifndef SELECT_BUILDING_WIDGET_H
#define SELECT_BUILDING_WIDGET_H

#include <QWidget>

namespace Ui {
class select_building_widget;
}

class select_building_widget : public QWidget
{
    Q_OBJECT

public:
    explicit select_building_widget(QWidget *parent = 0);
    ~select_building_widget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::select_building_widget *ui;
};

#endif // SELECT_BUILDING_WIDGET_H
