#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_toolButton_clicked() {
    QString usr = ui->lineEdit->text();             // Username inserito
    QString pass = ui->lineEdit_2->text();          // PIN inserito

    string pin = pass.toUtf8().constData();         // "cast" da QString a string
    string user = usr.toUtf8().constData();         // "cast" da QString a string

    if (atoi(pin.c_str()) && 0 < user.length() && 5 == pass.length()) {   // Verifico che i dati siano coerenti
        DataBase* d = new DataBase();
        if (d->load()) {                             // Entro sse è la funzione load non ha avuto problemi

            if (d->verifyLogin(user, pin)) {
                this->close();                      // Chiudo la finistra di login
                if (d->verifyAdmin(user)) {          // Verifico se l'utente è amministratore
                    User* u = d->getUser(user);

                    AdminInfo newAdminWindow;
                    newAdminWindow.setAdmin(*u);
                    newAdminWindow.setModal(true);
                    newAdminWindow.exec();
                } else {                            // Non è amministratore
                    UserInfo newUserWindow;
                    User* h = d->getUser(user);

                    newUserWindow.setUser(*h);
                    newUserWindow.setModal(true);
                    newUserWindow.exec();
                }
            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Dati di accesso non corretti")
                );
            }
        } else {    // Creazione del contenitore errata o errore di accesso al DB
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Errore di caricamento del DB")
                );
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Dati non validi")
        );
    }
}
