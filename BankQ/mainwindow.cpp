#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinfo.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        // Funzioni utente
        //connect(ui->actionInfo, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "info" nella toolBar
        //connect(ui->actionPreleva, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "preleva" nella toolBar


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_centralWidget_windowTitleChanged(const QString &title) {

}

void MainWindow::on_toolButton_clicked() {
    QString usr = ui->lineEdit->text();
    QString pass = ui->lineEdit->text();
    if(usr == "admin" && pass == "admin") { // Verifico che un utente o l' amministratore sia prensente nel DB
        // Se si è loggato l' amministratore apro una nuova finistra relativa ad esso
        //ui->menuAmministratore->setEnabled(1);
        // Se si è loggato un utente apro una nuova finistra relativa ad esso
        this->close(); // Chiuso la finistra di login
        UserInfo newWidow;
        newWidow.setModal(true);
        newWidow.exec();


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
