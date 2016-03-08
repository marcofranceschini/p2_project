using namespace std;
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "userinfo.h"
#include "admininfo.h"
#include "user.h"
#include "database.h"


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

    string *vet = verifyLogin(usr, pass);
    if(vet[0] == usr.toUtf8().constData()) {
        if(vet[1] == "1") {
            this->close(); // Chiudo la finistra di login
            AdminInfo newAdminWindow;
            newAdminWindow.setModal(true);
            newAdminWindow.exec();
        }else{
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
