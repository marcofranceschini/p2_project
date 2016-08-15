#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>

#include "bronzeuser.h"
#include "silveruser.h"
#include "messagesdatabase.h"

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = 0);

    ~UserInfo();

    void setBronze (BronzeUser const&);

    void setSilver (SilverUser const&);

private slots:
    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

private:
    Ui::UserInfo *ui;

    BronzeUser userB;
    bool bf = false;    // DA RIVEDERE

    SilverUser userS;
    bool sf = false;    // DA RIVEDERE
};

#endif // USERINFO_H
