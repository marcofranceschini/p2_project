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

    //bool admin = false;
    //bool bronze = false;

    string pin = pass.toUtf8().constData();
    string user = usr.toUtf8().constData();

    if (atoi(pin.c_str())) {                // Verifico che il PIN sia numerico // isdigit(atoi(pin.c_str()))
        int int_pin = atoi(pin.c_str());
        if (d.load()) {                     // Entro sse è stato riempito il Container con gli utenti del DB
            if (d.verifyLogin(user, int_pin)) {
                this->close();              // Chiudo la finistra di login
                if (d.verifyAdmin(user)) {  // Verifico se l'utente è amministratore
                    User* u = d.getUser(user);
                    AdminInfo newAdminWindow;
                    newAdminWindow.setAdmin(*u);
                    newAdminWindow.setModal(true);
                    newAdminWindow.exec();
                } else {                    // Non è amministratore
                    UserInfo newUserWindow;
                    User* h = d.getUser(user);
                    //QString st =QString::fromStdString(h.getName());   // DA RIMUOVERE
                    //qDebug("USR-" + st.toLatin1() + "-USR");           // DA RIMUOVERE
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
}

void showInfo () {
}
