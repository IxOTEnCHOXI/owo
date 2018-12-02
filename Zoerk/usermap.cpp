#include "usermap.h"
#include "ui_usermap.h"

UserMap::UserMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserMap){
    ui->setupUi(this);
}

UserMap::~UserMap(){
    delete ui;
}
