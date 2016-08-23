#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "user.h"
#include "database.h"
#include "userinfo.h"       // Per la schermata degli utenti
#include "admininfo.h"      // Per la schermata degli amministratori

#include <QMainWindow>
#include <QMessageBox>      // Per i messaggi di errore



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
