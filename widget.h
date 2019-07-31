#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
    class widget;
}

class widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

    int money{0};
    void changeMoney(int n);
    void checkState();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pb_Coffee_clicked();

    void on_pb_Coke_clicked();

    void on_pb_Tea_clicked();

    void on_pb_Return_clicked();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
