#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information){
    ui->setupUi(this);
}

void Information::setInfo(string inv){
    ui->label->setText(QString::fromStdString(inv));
}

Information::~Information(){
    delete ui;
}
