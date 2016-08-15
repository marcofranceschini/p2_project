using namespace std;
#include "userinfo.h"
#include "ui_userinfo.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "bronzeuser.h"
#include "database.h"
#include "bronzeuser.h"
#include "silveruser.h"
#include "QStandardItemModel"

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
    ui->label_24->setText(QString::number(userB.getCountNumber()));  // Numero conto
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

    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex = message->countMessage(userB.getUsername());
        if (0 < mex) {

            // QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            QString s = QString::number(mex);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");
            QMessageBox::warning(
                this,
                tr("BankQ - Messagi"),
                tr("Ci sono dei messaggi da leggere")
            );

            //int num = 0;
            Container<Message> app = message->getMessageByUser(userB.getUsername());
            Container<Message>::Iteratore it = app.begin();
            for (int row = 0; row < mex; ++row) {
                for (int col = 0; col < 2; ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());  // 0 for all data

                    /*if (!app[it]->getRead()) {    // Conto il numero di messaggi non letti
                        num ++;
                        // Risalto i messaggi da leggere
                        QFont font;
                        font.setBold(true);
                        //ui->tableView->itemDelegateForRow(row)->set(font);
                    }*/
                    //tableWidget->item(2, 2)->setFont(font);
                    //model->
                    switch (col) {
                        case 0:
                            model->setData(index, QString::fromStdString(app[it]->getRecipient()));
                        break;

                        case 1:
                            model->setData(index, QString::fromStdString(app[it]->getSender()));
                        break;
                    }
                }
                it++;
            }


        } else {
            ui->label_25->setText("Non sono presenti nuovi messaggi da leggere");
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }
}

void UserInfo::setSilver (SilverUser const& s) {
    userS = s;
    sf = true;

    ui->label_4->setText(QString::fromStdString(userS.getName()));  // Nome
    ui->label_5->setText(QString::fromStdString(userS.getSurname()));     // Cognome
    ui->label_6->setText("Silver"); // Tipo conto
    ui->label_10->setText(QString::number(userS.getTotalTax()));  // Tasse anno
    ui->label_11->setText(QString::number(userS.getTotalBonus()));  // Bonus anno
    ui->label_24->setText(QString::number(userS.getCountNumber()));  // Numero conto
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

    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex = message->countMessage(userS.getUsername());
        if (0 < mex) {

            // QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            QString s = QString::number(mex);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");
            QMessageBox::warning(
                this,
                tr("BankQ - Messagi"),
                tr("Ci sono dei messaggi da leggere")
            );

            //int num = 0;
            Container<Message> app = message->getMessageByUser(userS.getUsername());
            Container<Message>::Iteratore it = app.begin();
            for (int row = 0; row < mex; ++row) {
                for (int col = 0; col < 2; ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());  // 0 for all data

                    /*if (!app[it]->getRead()) {    // Conto il numero di messaggi non letti
                        num ++;
                        // Risalto i messaggi da leggere
                        QFont font;
                        font.setBold(true);
                        //ui->tableView->itemDelegateForRow(row)->set(font);
                    }*/
                    //tableWidget->item(2, 2)->setFont(font);
                    //model->
                    switch (col) {
                        case 0:
                            model->setData(index, QString::fromStdString(app[it]->getRecipient()));
                        break;

                        case 1:
                            model->setData(index, QString::fromStdString(app[it]->getSender()));
                        break;
                    }
                }
                it++;
            }


        } else {
            ui->label_25->setText("Non sono presenti nuovi messaggi da leggere");
            ui->toolButton_5->setCheckable(false);
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }
}

void UserInfo::on_toolButton_3_clicked() {  // Prelievo
    QString a = ui->lineEdit_2->text();
    QString b = ui->lineEdit_3->text();

    /*double cifra = a.toDouble();
    int conto = b.toInt();
    bool flag = false;

    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (bf) {   // E' un utente bronze
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
    }*/
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

    // Scrivere nel DB



    QString a = ui->lineEdit_2->text();
    QString b = ui->lineEdit_3->text();

    double cifra = a.toDouble();
    int conto = b.toInt();
    bool flag = false;

    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (bf) {   // E' un utente bronze
            if (0 <= userB.getCount()-cifra) {
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
        SilverUser s;
        BronzeUser b;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBronze()) {   // Carico gli utenti bronze
                if (d.verifyNumberBronze(conto)) {   // Verifico che il numero di conto sia di un utente bronze
                    b = d.getBronzeByCount(conto);
                    b.setCount(b.getCount() + cifra);
                    bronze = true;
                    if (!d.verifyStillBronze(b)) {
                        // MANDO UN MESSAGGIO ALL'UTENTE PER L'AVVENUTO PASSAGGIO

                    } else {
                        // MANDO UN MESSAGGIO PER LA RICARICA
                    }
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
                        s = d.getSilverByCount(conto);
                        s.setCount(s.getCount() + cifra);
                        silver = true;

                         // Un utente silver non può "salire" ma verifyStillSilver riscrive sul DB con il conto aggiornato
                         d.verifyStillSilver(s);
                        // MANDO UN MESSAGGIO PER LA RICARICA

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

            MainWindow u;   // DA RIMUOVERE


            if ((bronze && !silver) || (!bronze && silver)) {   // Se ho trovato un numero di conto sottraggo l'importo
                if (bf) {   // Aggiorno i campi con il nuovo saldo
                    userB.setCount(userB.getCount() - cifra);

                    // L'utente bronze non può "scendere" però verifyStillBronze riscrive nel DB l'utente con il conto decrementato
                    d.verifyStillBronze(userB);

                    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
                } else {
                    userS.setCount(userS.getCount() - cifra);

                    if (!d.verifyStillSilver(userS)) {      // Verifico se l'utente è ancora silver
                        sf = false;
                        bf = true;
                        BronzeUser* app = new BronzeUser(userS);
                        userB = *app;
                        delete app;
                        //delete &userS;    // CAUSA CRASH
                        ui->label_6->setText("Bronze"); // Cambio il tipo di conto

                        QMessageBox::information(
                            this,
                            tr("BankQ - Avviso"),
                            tr("Con l'ultimo ricarica il tuo account è sceso a bronze")
                        );
                    }

                    ui->label_12->setText(QString::number(userS.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userS.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userS.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userS.getCount()));   // Saldo
                }
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



void UserInfo::on_toolButton_5_clicked() { // Messaggi spuntati come visualizzati
    MessagesDataBase* mdb = new MessagesDataBase();
    if (mdb->loadMessages()) {
        if (bf) {
            // QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (0, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            QString s = QString::number(0);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");

            mdb->deleteMessages(userB.getUsername());
        } else {
            // QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (0, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            QString s = QString::number(0);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");

            mdb->deleteMessages(userS.getUsername());
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }
}
