#include "inventory.h"
#include "ui_inventory.h"
#include "Player.h"

Inventory::Inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inventory){
    ui->setupUi(this);
}

void Inventory::PrintInventory(string inv){
    ui->label->setText(QString::fromStdString(inv));
}

Inventory::~Inventory(){
    delete ui;
}
