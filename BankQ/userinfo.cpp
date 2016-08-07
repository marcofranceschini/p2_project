using namespace std;
#include "userinfo.h"
#include "ui_userinfo.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "bronzeuser.h"
#include "database.h"
#include "bronzeuser.h"
#include "silveruser.h"

UserInfo::UserInfo(QWidget *parent):QDialog(parent), ui(new Ui::UserInfo) {
    ui->setupUi(this);

    if (bf) {

    }
}

UserInfo::~UserInfo() {
    delete ui;
}

void UserInfo::setBronze (BronzeUser const& b) {
    userB = b;
    bf = true;

    ui->label_4->setText(QString::fromStdString(userB.getName()));  // Nome
    ui->label_5->setText(QString::fromStdString(userB.getSurname()));     // Cognome
    ui->label_6->setText("Bronze"); // Tipo conto
    ui->label_10->setText(QString::number(userB.getTotalTax()));  // Tasse anno
    ui->label_11->setText(QString::number(userB.getTotalBonus()));  // Bonus anno
    ui->label_24->setText(QString::fromStdString(userB.getCountNumber()));  // Numero conto
    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
    //ui->label_70->setText("3% = 30 €"); // Costo per diventare gold in base alla percentuale sul saldo
    //ui->label_71->setText("+ 5 %"); // Aumento tasse gold fisse
    //ui->label_73->setText("+ 5.5 %"); // Aumento bonus gold fisso
    ui->label_75->setText(QString::fromStdString(userB.getCode())); // Codice fiscale
    ui->label_77->setText(QString::number(userB.getTelephone())); // Numero di telefono
    ui->label_78->setText(QString::fromStdString(userB.getUsername())); // Username
}

void UserInfo::setSilver (SilverUser const& s) {
    userS = s;
    sf = true;

    ui->label_4->setText(QString::fromStdString(userS.getName()));  // Nome
    ui->label_5->setText(QString::fromStdString(userS.getSurname()));     // Cognome
    ui->label_6->setText("Bronze"); // Tipo conto
    ui->label_10->setText(QString::number(userS.getTotalTax()));  // Tasse anno
    ui->label_11->setText(QString::number(userS.getTotalBonus()));  // Bonus anno
    ui->label_24->setText(QString::fromStdString(userS.getCountNumber()));  // Numero conto
    ui->label_12->setText(QString::number(userS.getCount()));   // Saldo
    ui->label_19->setText(QString::number(userS.getCount()));   // Saldo prelievo
    ui->label_22->setText(QString::number(userS.getCount()));   // Saldo ricarica
    ui->label_66->setText(QString::number(userS.getCount()));   // Saldo
    //ui->label_70->setText("3% = 30 €"); // Costo per diventare gold in base alla percentuale sul saldo
    //ui->label_71->setText("+ 5 %"); // Aumento tasse gold fisse
    //ui->label_73->setText("+ 5.5 %"); // Aumento bonus gold fisso
    ui->label_75->setText(QString::fromStdString(userS.getCode())); // Codice fiscale
    ui->label_77->setText(QString::number(userS.getTelephone())); // Numero di telefono
    ui->label_78->setText(QString::fromStdString(userS.getUsername())); // Username
}

void UserInfo::on_toolButton_3_clicked() {  // Prelievo
    QString a = ui->lineEdit_2->text();
    QString b = ui->lineEdit_3->text();

    float cifra = a.toFloat();
    string conto = b.toUtf8().constData();
    bool flag = false;
    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (bf) { // E' un utente bronze
            if (0 <= userB.getCount()-cifra) {
                userB.setCount(userB.getCount()-cifra);
                flag = true;
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Credito insufficiente")
                );
            }
        } else {    // Utente silver
            if (0 <= userS.getCount()-cifra) {
                userS.setCount(userS.getCount()-cifra);
                flag = true;
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Credito insufficiente")
                );
            }
        }

        bool bronze = false;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBronze()) {   // Carico gli utenti bronze
                if (d.verifyNumberBronze(conto)) {   // Verifico che il numero di conto sia di un utente bronze
                    BronzeUser b = d.getBronzeByCount(conto);
                    b.setCount(b.getCount()+cifra);
                    bronze = true;

                    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
                }

            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Errore di caricamento (bronze)")
                );
            }

            bool silver = false;

            if (!bronze) {
                if (d.loadSilver()) {   // Carico gli utenti silver
                    if (d.verifyNumberSilver(conto)) {   // Verifico che il numero di conto sia di un utente silver
                        SilverUser s = d.getSilverByCount(conto);
                        s.setCount(s.getCount()+cifra);
                        silver = true;

                        ui->label_12->setText(QString::number(userS.getCount()));   // Saldo
                        ui->label_19->setText(QString::number(userS.getCount()));   // Saldo prelievo
                        ui->label_22->setText(QString::number(userS.getCount()));   // Saldo ricarica
                        ui->label_66->setText(QString::number(userS.getCount()));   // Saldo
                    } else {    // Se il numero non è né silver né bronze allora è errato

                        QMessageBox::information(
                            this,
                            tr("BankQ - Prelievo"),
                            tr("Numbero di conto errato")
                        );
                    }
                } else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Errore"),
                        tr("Errore di caricamento (silver)")
                    );
                }
            }
            // Se non ho trovato un numero di conto ritorno l'importo prelevato
            if (!bronze && !silver) {
                if (bf) // E' un utente bronze
                    userB.setCount(userB.getCount()+cifra);
                else
                    userS.setCount(userS.getCount()+cifra);
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Prelievo avvenuto correttamente")
                );
            }
        }

    }else{
        QMessageBox::information(
            this,
            tr("BankQ - Prelievo"),
            tr("Importo errato")
        );
    }
    //qDebug()  << withdraw << QString("float %1").arg(f, 20, 'f', 20);
    // Verifico se prelevo oltre il limite del conto
    //if....
    //Messaggio di errore
    /*QMessageBox::warning(
        this,
        tr("BankQ - Errore"),
        tr("Credito non sufficente")
    );*/
    //Messaggio di avvenuto prelievo

    // Verifico se l'utente scende ad utente bronze + messaggio

}

void UserInfo::on_toolButton_4_clicked() {  // Ricarica



    // DA FARE
    // Verifico se l'utente passa ad utente silver + messaggio



    QString a = ui->lineEdit_2->text();
    QString b = ui->lineEdit_3->text();

    float cifra = a.toFloat();
    string conto = b.toUtf8().constData();
    bool flag = false;
    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (bf) { // E' un utente bronze
            if (0 <= userB.getCount()-cifra) {
                userB.setCount(userB.getCount()-cifra);
                flag = true;
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Credito insufficiente")
                );
            }
        } else {    // Utente silver
            if (0 <= userS.getCount()-cifra) {
                userS.setCount(userS.getCount()-cifra);
                flag = true;
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Credito insufficiente")
                );
            }
        }

        bool bronze = false;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBronze()) {   // Carico gli utenti bronze
                if (d.verifyNumberBronze(conto)) {   // Verifico che il numero di conto sia di un utente bronze
                    BronzeUser b = d.getBronzeByCount(conto);
                    b.setCount(b.getCount()+cifra);
                    bronze = true;

                    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
                }

            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Errore di caricamento (bronze)")
                );
            }

            bool silver = false;

            if (!bronze) {
                if (d.loadSilver()) {   // Carico gli utenti silver
                    if (d.verifyNumberSilver(conto)) {   // Verifico che il numero di conto sia di un utente silver
                        SilverUser s = d.getSilverByCount(conto);
                        s.setCount(s.getCount()+cifra);
                        silver = true;

                        ui->label_12->setText(QString::number(userS.getCount()));   // Saldo
                        ui->label_19->setText(QString::number(userS.getCount()));   // Saldo prelievo
                        ui->label_22->setText(QString::number(userS.getCount()));   // Saldo ricarica
                        ui->label_66->setText(QString::number(userS.getCount()));   // Saldo
                    } else {    // Se il numero non è né silver né bronze allora è errato

                        QMessageBox::information(
                            this,
                            tr("BankQ - Prelievo"),
                            tr("Numbero di conto errato")
                        );
                    }
                } else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Errore"),
                        tr("Errore di caricamento (silver)")
                    );
                }
            }
            // Se non ho trovato un numero di conto ritorno l'importo prelevato
            if (!bronze && !silver) {
                if (bf) // E' un utente bronze
                    userB.setCount(userB.getCount()+cifra);
                else
                    userS.setCount(userS.getCount()+cifra);
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Prelievo avvenuto correttamente")
                );
            }
        }

    }else{
        QMessageBox::information(
            this,
            tr("BankQ - Prelievo"),
            tr("Importo errato")
        );
    }
}

void UserInfo::on_toolButton_13_clicked() {
    QString appCost = ui->label_70->text();
    QString appTax = ui->label_71->text();
    float cost = appCost.toFloat();
    float tax = appTax.toFloat();
    //qDebug()  << withdraw << QString("float %1").arg(f, 20, 'f', 20);
    // Verifico se prelevo oltre il limite del conto
    //if....
    //Messaggio di errore
    /*QMessageBox::warning(
        this,
        tr("BankQ - Errore"),
        tr("Credito non sufficente")
    );*/

    // Modifico tassa e bonus

    //Messaggio di avvenuto prelievo
    QMessageBox::information(
        this,
        tr("BankQ - Upgrade"),
        tr("Upgrade corretto, ora sei un utente gold")
    );
    // Verifico se l'utente scende ad utente bronze + messaggio
}

void UserInfo::on_toolButton_clicked() { // Logout
    MainWindow* w = new MainWindow(); // Dichiaro una nuova MainWindow
    w->show();
    this->close(); // Chiudo la finestra corrente
}

void UserInfo::on_toolButton_2_clicked() { // Chiusura conto
    // Chiamo la funzione per inviare una notifica all'admin
    QString app = ui->label_78->text();
    string usr = app.toUtf8().constData(); // Conversione da QString a string
    string mex = "L'utente "+usr+" desidera chiudere il proprio conto.";
    //User::closeAccount(username);
    //string username = static_cast<string*>(usr);
}


