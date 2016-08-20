#ifndef ADMININFO_H
#define ADMININFO_H

#include <QDialog>
#include "admin.h"

namespace Ui {
    class AdminInfo;
}

class AdminInfo : public QDialog {
    Q_OBJECT

    public:
        explicit AdminInfo(QWidget *parent = 0);

        ~AdminInfo();

        void setAdmin (const User&);

        void setTable (const string&,  const bool&);

        void setComboBox ();

        void setComboBox_2 ();

    private slots:
        void on_toolButton_2_clicked();

        void on_toolButton_clicked();

        void on_toolButton_3_clicked();

        void on_toolButton_4_clicked();

        void on_toolButton_5_clicked();

        void on_toolButton_6_clicked();

        void on_tableView_clicked(const QModelIndex &index);

private:
        Ui::AdminInfo *ui;

        //Admin admin;
};

#endif // ADMININFO_H
