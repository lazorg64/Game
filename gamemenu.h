#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>

namespace Ui {
class gamemenu;
}

class gamemenu : public QWidget
{
    Q_OBJECT

public:
    explicit gamemenu(QWidget *parent = 0);
    ~gamemenu();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::gamemenu *ui;
};

#endif // GAMEMENU_H
