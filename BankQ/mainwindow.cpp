using namespace std;

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "userinfo.h"
#include "admininfo.h"
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

    /*QString filename = QFileDialog::getOpenFileName(this, tr("Open Xml"), ".", tr("Xml files (*.xml)"));
    QFile file("/db.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;

    }
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    xmlReader.readNext();
    // Inizio la lettura del file
    while (!xmlReader.isEndDocument()) {
        if (xmlReader.isStartElement()) {
            QString name = xmlReader.name().toString();
            if (name == "username") {
                QMessageBox::information(this,name,xmlReader.readElementText());
            }
        }else if (xmlReader.isEndElement()) {
                    xmlReader.readNext();
        }
    }*/
    Container <User> utenti;
    DataBase <User> d;
    if(d.loadDB(utenti)) {          // UTENTI NON È PIÙ UN VETTORE
        //string *vet = verifyLogin(usr.toUtf8().constData(), pass.toUtf8().constData());
        bool flag = false;
        bool admin = false;
        string pin = pass.toUtf8().constData();
        int int_pin = atoi(pin.c_str());
        /*for(int i = 0; i < utenti.getSize(); ++i) { // Verifico che le credenziali siano corrette
            if(utenti[i].getUsername() == usr.toUtf8().constData() && utenti[i].getPin() == int_pin) {
                flag = true; // Dati del login verificati
                User a = utenti[i]; // Ritorna l'utente nella i-esima posizione
                if(dynamic_cast<Admin>(a)) // Verifico che l'utente sia un amministratore
                    admin = true;
                break;
            }
        }*/
        for(Container<User>::Iteratore it = utenti.begin(); it != utenti.end(); ++it) { // Verifico che le credenziali siano corrette
            if(utenti[it].getUsername() == usr.toUtf8().constData() && utenti[it].getPin() == int_pin) {
                flag = true; // Dati del login verificati
                User a = utenti[it]; // Ritorna l'utente nella i-esima posizione
                if(dynamic_cast<Admin>(a)) // Verifico che l'utente sia un amministratore
                    admin = true;
                break;
            }
        }

        if(flag) {  // Login corretto
            if(admin) { // Verifico se e' un amministratore e apro la relativa finestra
                this->close(); // Chiudo la finistra di login
                AdminInfo newAdminWindow;
                newAdminWindow.setModal(true);
                newAdminWindow.exec();
            }else{ // Utente "normale"
                this->close(); // Chiudo la finistra di login
                UserInfo newUserWidow;
                newUserWidow.setModal(true);
                newUserWidow.exec();
            }
        }else{ // Login errato, visualizzo un messaggio di errore
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Dati non corretti")
            );
        }
    }else{ // Creazione del contenitore errata o errore di accesso al DB
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento")
        );
    }
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
