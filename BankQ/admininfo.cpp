#include "admininfo.h"
#include "ui_admininfo.h"
#include "mainwindow.h"
#include "QMessageBox"

AdminInfo::AdminInfo(QWidget *parent):QDialog(parent), ui(new Ui::AdminInfo) {
    ui->setupUi(this);
    ui->label->setText("Marco"); // Nome amministratore
    ui->label_2->setText("Fr"); // Cognome amministratore
    ui->label_3->setText("Amministratore"); // Tipo account -> amministratore rimmarrà fisso
    ui->label_19->setText("Via bello"); // Indirizzo amministratore
    ui->label_75->setText("MNRC..."); // Codice fiscale amministratore
    ui->label_77->setText("040421"); // Numero di telefono amministratore
    ui->label_78->setText("marco"); // Username amministratore

    ui->label_21->setText("Ci sono 3 richieste di chiudere il conto"); // Username amministratore

}

AdminInfo::~AdminInfo() {
    delete ui;
}




void AdminInfo::on_toolButton_2_clicked() {
    QString n = ui->lineEdit->text(); // Nome
    QString c = ui->lineEdit_2->text(); // Cognome
    QString cod = ui->lineEdit_3->text(); // Codice fiscale
    QString a = ui->lineEdit_7->text(); // Indirizzo
    QString t = ui->lineEdit_4->text(); // Telefono
    QString u = ui->lineEdit_5->text(); // Username
    QString p = ui->lineEdit_6->text(); // PIN
    QString s = ui->lineEdit_9->text(); // Saldo

    // In base al saldo diventa user bronzo o silver

    // Verifico codice fiscale e username se già esistono
    // Il PIN deve essere di 5 numeri
    //Messaggio di errore
    /*QMessageBox::warning(
        this,
        tr("BankQ - Errore"),
        tr("Credito non sufficente")
    );*/
    //Messaggio di avvenuto prelievo
    QMessageBox::information(
        this,
        tr("BankQ - Nuovo Utente"),
        tr("Aggiunta avvenuta correttamente")
    );
}

void AdminInfo::on_toolButton_clicked() {
    MainWindow newLoginWindow;
    newLoginWindow.setWindowTitle("BankQ - Benvenuto");
    //newLoginWindow->show();
    newLoginWindow.setVisible(true);
    this->close();
    //newLoginWindow.setModal(true);
    //newLoginWindow.exec();
}

void AdminInfo::on_toolButton_3_clicked() {
    QString u = ui->lineEdit_8->text(); // Username
    // Se l'utente esiste e ha fatto richiesta di essere eliminato
    QMessageBox::information(
        this,
        tr("BankQ - Rimozione Utente"),
        tr("Rimozione avvenuta correttamente")
    );
    // Altrimenti errore:
    /*QMessageBox::warning(
        this,
        tr("BankQ - Errore"),
        tr("Credito non sufficente")
    );*/
}
