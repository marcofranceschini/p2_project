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

        void setTable (const Admin&);

        void setComboBox ();

    private slots:
        void on_toolButton_2_clicked();

        void on_toolButton_clicked();

        void on_toolButton_3_clicked();

        void on_toolButton_4_clicked();

private:
        Ui::AdminInfo *ui;

        //Admin admin;
};

#endif // ADMININFO_H
