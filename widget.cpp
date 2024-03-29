#include "widget.h"
#include "ui_widget.h"


widget::widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    checkState();
}

widget::~widget()
{
    delete ui;
}

void widget::checkState()
{
    ui->pb_Return->setEnabled(money>0);
    ui->pb_Tea->setEnabled(money>=50);
    ui->pb_Coffee->setEnabled(money>=100);
    ui->pb_Coke->setEnabled(money>=200);
}

void widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(QString::number(money));
}

void widget::on_pb10_clicked()
{
    changeMoney(10);
    checkState();
}

void widget::on_pb50_clicked()
{
    changeMoney(50);
    checkState();
}

void widget::on_pb100_clicked()
{
    changeMoney(100);
    checkState();
}

void widget::on_pb500_clicked()
{
    changeMoney(500);
    checkState();
}

void widget::on_pb_Coffee_clicked()
{
    changeMoney(-100);
    checkState();
}

void widget::on_pb_Coke_clicked()
{
    changeMoney(-200);
    checkState();
}

void widget::on_pb_Tea_clicked()
{
    changeMoney(-50);
    checkState();
}

void widget::on_pb_Return_clicked()
{
    QMessageBox msg;
    QString msgResult="";
    money / 500 != 0 ? msgResult += "500 X " + QString::number(money/500) + "\n" : msgResult += "";
    money %= 500;
    money / 100 != 0 ? msgResult += "100 X " + QString::number(money/100) + "\n"  : msgResult += "";
    money %= 100;
    money / 50 != 0 ? msgResult += "50 X " + QString::number(money/50) + "\n"  : msgResult += "";
    money %= 50;
    money / 10 != 0 ? msgResult += "10 X " + QString::number(money/10) : msgResult += "";
    msg.information(nullptr,"Return Money",msgResult);
    changeMoney(-money);
    checkState();
}
