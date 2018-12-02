#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usermap.h"
#include "Player.h"
#include "inventory.h"
#include "information.h"
#include "endgamebanner.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    zork = new ZorkUL();
    user = new Player("Adventurer");
    user->addItem(new Item("Map", 1, 1));
    user->addItem(new Item("Matches", 1, 1));
    user->addItem(new Item("Teddy Bear", 1, 1));
    ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
    ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
    ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
}

MainWindow::~MainWindow(){
    delete ui;

}

void MainWindow::on_pushButton_clicked(){
    if(zork->getCurrentRoom()->nextRoom("north") == NULL)
        ui->label->setText(QString::fromStdString("There is no path North"));
    else{
        zork->go("north");
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
    }
}

void MainWindow::on_pushButton_2_clicked(){
    if(zork->getCurrentRoom()->nextRoom("south") == NULL)
        ui->label->setText(QString::fromStdString("There is no path South"));
    else{
        zork->go("south");
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
    }
}

void MainWindow::on_pushButton_3_clicked(){
    if(zork->getCurrentRoom()->nextRoom("east") == NULL)
        ui->label->setText(QString::fromStdString("There is no path East"));
    else{
        zork->go("east");
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
    }
}

void MainWindow::on_pushButton_4_clicked(){
    if(zork->getCurrentRoom()->nextRoom("west") == NULL)
        ui->label->setText(QString::fromStdString("There is no path West"));
    else{
        zork->go("west");
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
    }
}

void MainWindow::on_pushButton_5_clicked(){
    if(user->isItemInInventory("Teleport Stone")){
        zork->teleportRoom();
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
    }
    else{
        infoScreen = new Information();
        string info ="You can't do that yet!";
        infoScreen->setInfo(info);
        infoScreen->show();
    }
}


void MainWindow::on_pushButton_6_clicked(){
   userMap = new UserMap();
   userMap->show();
}

void MainWindow::on_pushButton_7_clicked(){
    string inv = "";
    inv = (user->longDescription());
    inventory = new Inventory();
    inventory->PrintInventory(inv);
    inventory->show();
}

void MainWindow::on_pushButton_8_clicked(){
    if((zork->getCurrentRoom()->numberOfItems()) >= 1)
        infoScreen = new Information();
        string temp = user->interact((zork->getCurrentRoom()->returnItem(0)), 0, zork->getCurrentRoom());
        infoScreen->setInfo(temp);
        infoScreen->show();
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
}

void MainWindow::on_pushButton_9_clicked()
{
    if((zork->getCurrentRoom()->numberOfItems()) >= 2)
        infoScreen = new Information();
        string temp = user->interact((zork->getCurrentRoom()->returnItem(1)), 1, zork->getCurrentRoom());
        infoScreen->setInfo(temp);
        infoScreen->show();
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
}

void MainWindow::on_pushButton_10_clicked()
{
    if((zork->getCurrentRoom()->numberOfItems()) >= 3)
        infoScreen = new Information();
        string temp = user->interact((zork->getCurrentRoom()->returnItem(2)), 2, zork->getCurrentRoom());
        infoScreen->setInfo(temp);
        infoScreen->show();
        ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
        ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
        ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
}

void MainWindow::on_pushButton_11_clicked(){
    if((zork->getCurrentRoom()->shortDescription()).compare("H") == 0){
        if(user->isItemInInventory("Rock")){
            infoScreen = new Information();
            string info ="You smash open the glass case with \nthe rock. Inside is a small metal key. \nYou place it in your pocket and move on.";
            user->addItem(new Item("Small Metal Key", 1, 100));
            zork->getCurrentRoom()->removeItemFromRoom(0);
            zork->getCurrentRoom()->addItem((new Item("Broken Glass Case", 100, 75)));
            ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
            ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
            ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
            infoScreen->setInfo(info);
            infoScreen->show();
        }
            else{
            infoScreen = new Information();
            string info ="There is a glass case here, through the \ndirty glass you see what looks like a \nsmall key.";
            infoScreen->setInfo(info);
            infoScreen->show();
            }
    }
    else if((zork->getCurrentRoom()->shortDescription()).compare("B") == 0){
        if(user->isItemInInventory("A Twig")){
            infoScreen = new Information();
            string info ="You use the matches to start a small \nyet warming fire under the oak tree. Almost makes you\nwish you had some marshmallows to roast.";
            zork->getCurrentRoom()->addItem((new Item("A Small Campfire", 100, 75)));
            user->removeItemFromPlayer("A Twig");
            ui->label->setText(QString::fromStdString(zork->getCurrentRoom()->shortDescription()));
            ui->label_2->setText(QString::fromStdString(zork->getCurrentRoom()->exitString()));
            ui->label_3->setText(QString::fromStdString(zork->getCurrentRoom()->displayItem()));
            infoScreen->setInfo(info);
            infoScreen->show();
        }
            else{
            infoScreen = new Information();
            string info ="This looks like a good place to camp \nmaybe I could start a fire if I had \nsome firewood";
            infoScreen->setInfo(info);
            infoScreen->show();
            }
   }
    else if((zork->getCurrentRoom()->shortDescription()).compare("I") == 0){
        if(user->isItemInInventory("Small Metal Key")){
            infoScreen = new Information();
            string info ="You insert the key into the box. It's \nstiff but eventually it begins to turn. \nThe lid opens to reveal a small stone with a weathered \nnote labled 'The Teleport Stone'. You place it \nin your pocket feeling it's power flow through you!";
            user->addItem(new Item("Teleport Stone", 1, 1000));
            infoScreen->setInfo(info);
            infoScreen->show();
        }
            else{
            infoScreen = new Information();
            string info ="This box is locked tight. I'll need to find the key!";
            infoScreen->setInfo(info);
            infoScreen->show();
            }
   }

    else if((zork->getCurrentRoom()->shortDescription()).compare("Z") == 0){
        if(user->isItemInInventory("Teddy Bear")){
            infoScreen = new Information();
            string info ="You place the Top Hat on \nyour Teddy Bears head. Suddenly\nhe begins to move. The hat having magically \ngiven him life. \n\n\nCongratulations!!! You Have Completed The Game!";
            user->addItem(new Item("Teleport Stone", 1, 1000));
            infoScreen->setInfo(info);
            infoScreen->show();
            endScreen = new EndGameBanner();
            endScreen->show();
        }
            else{
            infoScreen = new Information();
            string info ="This box is locked tight. I'll need to find the key!";
            infoScreen->setInfo(info);
            infoScreen->show();
            }
   }
}
