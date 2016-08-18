#include "admininfo.h"
#include "ui_admininfo.h"
#include "mainwindow.h"
#include "database.h"

AdminInfo::AdminInfo(QWidget *parent):QDialog(parent), ui(new Ui::AdminInfo) {
    ui->setupUi(this);
}

AdminInfo::~AdminInfo() {
    delete ui;
}

void AdminInfo::setAdmin (const User& cu) {
    User* ncu = const_cast<User*> (&cu);
    Admin* a = dynamic_cast<Admin*>(ncu);
    //admin = *a;

    ui->label_5->setText(QString::fromStdString(admin.getName()));      // Nome amministratore
    ui->label_8->setText(QString::fromStdString(admin.getSurname()));   // Cognome amministratore
    ui->label_7->setText("Amministratore");                             // Tipo account -> "amministratore" rimmarrà fisso
    ui->label_19->setText(QString::fromStdString(admin.getAddress()));  // Indirizzo amministratore
    ui->label_75->setText(QString::fromStdString(admin.getCode()));     // Codice fiscale amministratore
    ui->label_77->setText(QString::number(admin.getTelephone()));       // Numero di telefono amministratore
    ui->label_78->setText(QString::fromStdString(admin.getUsername())); // Username amministratore

    //ui->label_21->setText("Ci sono 3 richieste di chiudere il conto"); // Username amministratore
}

void AdminInfo::on_toolButton_2_clicked() {     // Inserisci nuovo utente
    string nom = (ui->lineEdit->text()).toUtf8().constData();     // Nome
    string cog = (ui->lineEdit_2->text()).toUtf8().constData();   // Cognome
    string ind = (ui->lineEdit_3->text()).toUtf8().constData();   // Indirizzo
    string tel = (ui->lineEdit_4->text()).toUtf8().constData();   // Telefono
    string cod = (ui->lineEdit_5->text()).toUtf8().constData();   // Codice fiscale
    string usr = (ui->lineEdit_6->text()).toUtf8().constData();   // Username
    string pin = (ui->lineEdit_7->text()).toUtf8().constData();   // PIN
    string sal = (ui->lineEdit_8->text()).toUtf8().constData();   // Saldo
    string num = (ui->lineEdit_9->text()).toUtf8().constData();   // Numero conto

    DataBase d;
    if (d.load()) {
        if (atoi(pin.c_str()) && atoi(tel.c_str()) && atoi(sal.c_str()) && atoi(num.c_str())) {    // Verifico che il PIN, telefono, saldo e #conto siano numerici
            int int_pin = atoi(pin.c_str());
            int int_tel = atoi(tel.c_str());
            int int_sal = atoi(sal.c_str());
            double int_num = atoi(num.c_str());
            if (nom != "" && cog != "" && ind != "" && cod != "" && usr != "") {
                if (!d.verifyExistingUsername(usr) && !d.verifyExistingCountNumber(int_num)) {  // Controllo che username e #conto siano univoci

                    d.addUser(*new BasicUser(nom, cog, ind, int_tel, cod, usr, int_pin, int_num, int_sal));

                    ui->lineEdit->setText("");    // Nome
                    ui->lineEdit_2->setText("");  // Cognome
                    ui->lineEdit_3->setText("");  // Indirizzo
                    ui->lineEdit_4->setText("");  // Telefono
                    ui->lineEdit_5->setText("");  // Codice fiscale
                    ui->lineEdit_6->setText("");  // Username
                    ui->lineEdit_7->setText("");  // PIN
                    ui->lineEdit_8->setText("");  // Saldo
                    ui->lineEdit_9->setText("");  // Numero conto

                    QMessageBox::information(
                        this,
                        tr("BankQ - Nuovo Utente"),
                        tr("Aggiunta avvenuta correttamente")
                    );
                } else {
                    if (d.verifyExistingUsername(usr)) {
                        QMessageBox::warning(
                            this,
                            tr("BankQ - Errore"),
                            tr("Username già esistente")
                        );
                    } else {
                        QMessageBox::warning(
                            this,
                            tr("BankQ - Errore"),
                            tr("Numero di conto già esistente")
                        );
                    }
                }
            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Tutti i campi devono essere riempiti")
                );
            }
        } else {
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("PIN, telefono, saldo e numero di conto devono essere numerici")
            );
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }

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
}

void AdminInfo::on_toolButton_clicked() {
    MainWindow* w = new MainWindow(); // Dichiaro una nuova MainWindow
    w->show();
    this->close(); // Chiudo la finestra corrente
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
