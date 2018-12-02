#ifndef ENDGAMEBANNER_H
#define ENDGAMEBANNER_H

#include <QDialog>
using namespace std;

namespace Ui {
class EndGameBanner;
}

class EndGameBanner : public QDialog{
    Q_OBJECT

public:
    explicit EndGameBanner(QWidget *parent = 0);
    ~EndGameBanner();

private:
    Ui::EndGameBanner *ui;
};

#endif // ENDGAMEBANNER_H
