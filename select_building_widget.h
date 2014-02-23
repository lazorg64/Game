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

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

signals:
     void selectedBuilding(std::string input);

private:

    QWidget * parent_link;
    Ui::select_building_widget *ui;
};

#endif // SELECT_BUILDING_WIDGET_H
