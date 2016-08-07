using namespace std;
#include "userinfo.h"
#include "ui_userinfo.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "bronzeuser.h"

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
    QString app = ui->lineEdit->text();
    float withdraw = app.toFloat();
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
    QMessageBox::information(
        this,
        tr("BankQ - Prelievo"),
        tr("Prelievo avvenuto correttamente")
    );
    // Verifico se l'utente scende ad utente bronze + messaggio

}

void UserInfo::on_toolButton_4_clicked() {  // Ricarica
    QString app = ui->lineEdit_2->text();
    float add = app.toFloat();
    //qDebug()  << withdraw << QString("float %1").arg(f, 20, 'f', 20);
    //Messaggio di avvenuta ricarica
    QMessageBox::information(
        this,
        tr("BankQ - Ricarica"),
        tr("Ricarica avvenuta correttamente")
    );
    // Verifico se l'utente passa ad utente silver + messaggio
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


