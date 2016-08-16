#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "userinfo.h"   // GUI
#include "admininfo.h"  // GUI

#include "user.h"
#include "admin.h"

#include "database.h"
#include "container.h"

// Per la finestra di errore
#include <QMessageBox>

// Per lavorare sul DB
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        //on_centralWidget_windowTitleChanged("BankQ - Login"); // Cambio il titolo della finestra
       // setWindowTitle("BankQ - Login");  // Cambio il titolo della finestra
        // Funzioni utente
        //connect(ui->actionInfo, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "info" nella toolBar
        //connect(ui->actionPreleva, SIGNAL(clicked()), this, SLOT(showInfo())); // Aggiungo chiamata ad una funzione quando schiaccio "preleva" nella toolBar
}

MainWindow::~MainWindow() {
    delete ui;
}

/*void MainWindow::on_centralWidget_windowTitleChanged(const QString& title) {
    setWindowTitle(title);
}*/

void MainWindow::on_toolButton_clicked() {
    QString usr = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    DataBase d;

    bool admin = false;
    bool bronze = false;

    string pin = pass.toUtf8().constData();
    string user = usr.toUtf8().constData();

    MainWindow u; //    DA RIMUOVERE

    if (atoi(pin.c_str())) {    // Verifico che il PIN sia numerico // isdigit(atoi(pin.c_str()))
        int int_pin = atoi(pin.c_str());
        if (d.load()) {  // Entro sse non ci sono stati problemi a riempire la lista degli admin
            //u.boom();
            if (d.verifyLogin(user, int_pin)) {
                this->close(); // Chiudo la finistra di login
                if (d.verifyAdmin(user)) {
                    AdminInfo newAdminWindow;
                    User u = d.getUser(user);
                    Admin* a = dynamic_cast<Admin*>(&u);
                    newAdminWindow.setAdmin(*a);
                    newAdminWindow.setModal(true);
                    newAdminWindow.exec();
                } else {    // Non è amministratore
                    UserInfo newUserWindow;
                    newUserWindow.setUser(d.getUser(user));
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
        } else { // Creazione del contenitore errata o errore di accesso al DB
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
            tr("PIN non numerico")
        );
    }
   /* if (d.loadAdmin()) {  // Entro sse non ci sono stati problemi a riempire la lista degli admin
        if (atoi(pin.c_str())) {    // Verifico che il PIN sia numerico // isdigit(atoi(pin.c_str()))
            int int_pin = atoi(pin.c_str());

        //string *vet = verifyLogin(usr.toUtf8().constData(), pass.toUtf8().constData());
        //u.boom();

        //bool admin = false;

        //string pin = pass.toUtf8().constData();
        //string user = usr.toUtf8().constData();

        if (atoi(pin.c_str())) {    // Verifico che il PIN sia numerico // isdigit(atoi(pin.c_str()))
            int int_pin = atoi(pin.c_str());*/
            /*for(int i = 0; i < utenti.getSize(); ++i) { // Verifico che le credenziali siano corrette
                if(utenti[i].getUsername() == usr.toUtf8().constData() && utenti[i].getPin() == int_pin) {
                    flag = true; // Dati del login verificati
                    User a = utenti[i]; // Ritorna l'utente nella i-esima posizione
                    if(dynamic_cast<Admin>(a)) // Verifico che l'utente sia un amministratore
                        admin = true;
                    break;
                }
            }*/
            /*for (Container<User>::Iteratore it = utenti.begin(); it != utenti.end(); it++) { // Verifico che le credenziali siano corrette
                //if(dynamic_cast<Admin*>(utenti[it])) // Verifico che l'utente sia un amministratore

                //QString app = QString::fromStdString(utenti[it]->getUsername());
                QString app;
                ui->lineEdit->setText(app);

                if (utenti[it]->verifyLogin(user, int_pin)) {  // Login corretto
                    //Admin* ad = dynamic_cast<Admin*>(&(utenti[it]));
                    if (true) { // Verifico se e' un amministratore e apro la relativa finestra
                        this->close(); // Chiudo la finistra di login
                        AdminInfo newAdminWindow;
                        newAdminWindow.setModal(true);
                        newAdminWindow.exec();
                        break;
                    }else{ // Utente "normale"
                        this->close(); // Chiudo la finistra di login
                        UserInfo newUserWidow;
                        newUserWidow.setModal(true);
                        newUserWidow.exec();
                        break;
                    }
                }else{ // Login errato, visualizzo un messaggio di errore
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Errore"),
                        tr("Dati non corretti")
                    );
                    break;
                }
            }
        }else{
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("PIN non numerico")
            );
        }

    }else{ // Creazione del contenitore errata o errore di accesso al DB
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento")
        );
    }*/
    /*if (usr == "admin" && pass == "admin") { // Verifico che un utente o l' amministratore sia prensente nel DB
        this->close(); // Chiudo la finistra di login
        AdminInfo newAdminWindow;
        newAdminWindow.setModal(true);
        newAdminWindow.exec();
    } else if (usr == "marco" && pass == "123") {
            this->close(); // Chiudo la finistra di login
            UserInfo newUserWidow;
            newUserWidow.setModal(true);
            newUserWidow.exec();
    } else { // Login errato, visualizzo un messaggio di errore
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Dati non corretti")
            );
    }*/
}

void showInfo () {
}
