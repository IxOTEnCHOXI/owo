#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class Information;
}

class Information : public QDialog{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = 0);
    void setInfo(string info);
    ~Information();

private:
    Ui::Information *ui;
};

#endif // INFORMATION_H
