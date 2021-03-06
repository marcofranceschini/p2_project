#ifndef ADMININFO_H
#define ADMININFO_H

#include <QDialog>
#include "admin.h"
#include "ui_admininfo.h"

#include "mainwindow.h"
#include "database.h"
#include "messagesdatabase.h"
#include "QStandardItemModel"   // Per QTable

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

        void empty_ComboBox ();

        void setComboBox_2 ();

        void empty_ComboBox_2 ();

        void setComboBox_5 ();

        void empty_ComboBox_5 ();

    private slots:
        void on_toolButton_2_clicked();

        void on_toolButton_clicked();

        void on_toolButton_3_clicked();

        void on_toolButton_4_clicked();

        void on_toolButton_5_clicked();

        void on_toolButton_6_clicked();

        void on_tableView_clicked(const QModelIndex &index);

        void on_toolButton_7_clicked();

        void on_comboBox_5_currentIndexChanged(int index);

        void on_toolButton_8_clicked();

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

private:
        Ui::AdminInfo *ui;
};

#endif // ADMININFO_H
