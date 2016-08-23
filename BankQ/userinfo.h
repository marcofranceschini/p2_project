#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include "prouser.h"
#include "database.h"
#include "mainwindow.h"
#include "messagesdatabase.h"
#include "QStandardItemModel"

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = 0);

    ~UserInfo();

    void setUser (const User&);                 // Imposta l'utente (pro o basic) nella schermata di appartenenza

    void setTable (const User&,  const bool&);  // Riempie la tabella con i messaggio per l'utente

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
};

#endif // USERINFO_H
