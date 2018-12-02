#ifndef INVENTORY_H
#define INVENTORY_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui{
class Inventory;
}

class Inventory : public QDialog{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = 0);
    void PrintInventory(string inv);
    ~Inventory();

private slots:


private:
    Ui::Inventory *ui;
};

#endif // INVENTORY_H
