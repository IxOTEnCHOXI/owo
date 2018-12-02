#include "endgamebanner.h"
#include "ui_endgamebanner.h"

EndGameBanner::EndGameBanner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndGameBanner){
    ui->setupUi(this);
}

EndGameBanner::~EndGameBanner()
{
    delete ui;
}
