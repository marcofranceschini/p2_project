#ifndef ADMININFO_H
#define ADMININFO_H

#include <QDialog>

namespace Ui {
    class AdminInfo;
}

class AdminInfo : public QDialog {
    Q_OBJECT

    public:
        explicit AdminInfo(QWidget *parent = 0);
        ~AdminInfo();

    private slots:
        void on_toolButton_2_clicked();

        void on_toolButton_clicked();

        void on_toolButton_3_clicked();

    private:
        Ui::AdminInfo *ui;
};

#endif // ADMININFO_H
