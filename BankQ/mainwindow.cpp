#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinfo.h"
#include "admininfo.h"
#include <QMessageBox>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        //on_centralWidget_windowTitleChanged("BankQ - Login"); // Cambio il titolo della finestra
        this->setWindowTitle("BankQ - Login");  // Cambio il titolo della finestra
        // Funzioni utente
        //connect(ui->actionInfo, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "info" nella toolBar
        //connect(ui->actionPreleva, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "preleva" nella toolBar


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_centralWidget_windowTitleChanged(const QString &title) {
    this->setWindowTitle(title);
}

void MainWindow::on_toolButton_clicked() {
    QString usr = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    if(usr == "admin" && pass == "admin") { // Verifico che un utente o l' amministratore sia prensente nel DB
        this->close(); // Chiudo la finistra di login
        AdminInfo newAdminWindow;
        newAdminWindow.setModal(true);
        newAdminWindow.exec();
    }else if(usr == "marco" && pass == "123") {
            this->close(); // Chiudo la finistra di login
            UserInfo newUserWidow;
            newUserWidow.setModal(true);
            newUserWidow.exec();
          }else{ // Login errato, visualizzo un messaggio di errore
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Dati non corretti")
            );
          }
}

void showInfo () {
}
