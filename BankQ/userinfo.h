#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>

#include "basicuser.h"
#include "prouser.h"
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

    void setUser (const User&);

    //void setSilver (SilverUser const&);

    void setTable (const User&,  const bool&);

private slots:
    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::UserInfo *ui;

    //BasicUser user;
};

#endif // USERINFO_H
