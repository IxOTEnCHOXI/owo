#ifndef USERMAP_H
#define USERMAP_H

#include <QDialog>

namespace Ui{
class UserMap;
}

class UserMap : public QDialog{
    Q_OBJECT

public:
    explicit UserMap(QWidget *parent = 0);
    ~UserMap();

private:
    Ui::UserMap *ui;
};

#endif // USERMAP_H
