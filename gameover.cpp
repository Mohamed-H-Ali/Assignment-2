#include "gameover.h"
#include "ui_gameover.h"
#include "main.cpp"
gameover::gameover(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gameover)
{
    ui->setupUi(this);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_yesbutton_clicked()
{

}

