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
}

UserInfo::~UserInfo() {
    delete ui;
}

void UserInfo::setUser (User const& cu) {
    User* ncu = const_cast<User*> (&cu);

    BronzeUser* u = dynamic_cast<BronzeUser*> (ncu);
    QString st =QString::fromStdString(ncu->getUsername());   // DA RIMUOVERE
    qDebug("RRR-" + st.toLatin1() + "-RRR");   // DA RIMUOVERE
    MainWindow uf;  // DA RIMUOVERE

    uf.boom();  // DA RIMUOVERE


    uf.boom();  // DA RIMUOVERE
    user = *u;
    uf.boom();  // DA RIMUOVERE

    //MainWindow uf;  // DA RIMUOVERE
    uf.boom();  // DA RIMUOVERE
    ui->label_4->setText(QString::fromStdString(u->getName()));     // Nome
    ui->label_5->setText(QString::fromStdString(u->getSurname()));  // Cognome
    ui->label_75->setText(QString::fromStdString(u->getCode()));    // Codice fiscale
    ui->label_77->setText(QString::number(u->getTelephone()));      // Numero di telefono
    ui->label_78->setText(QString::fromStdString(u->getUsername()));// Username
    ui->label_10->setText(QString::number(u->getTotalTax()));       // Tasse anno
    ui->label_11->setText(QString::number(u->getTotalBonus()));     // Bonus anno
    //MainWindow uf;  // DA RIMUOVERE
    uf.boom();  // DA RIMUOVERE
    ui->label_24->setText(QString::number(u->getCountNumber()));    // Numero conto
    ui->label_12->setText(QString::number(u->getCount()));          // Saldo
    ui->label_19->setText(QString::number(u->getCount()));          // Saldo prelievo
    ui->label_22->setText(QString::number(u->getCount()));          // Saldo ricarica
    ui->label_66->setText(QString::number(u->getCount()));          // Saldo


    if (dynamic_cast<SilverUser*> (u))
        ui->label_6->setText("Silver"); // Tipo conto
    else
        ui->label_6->setText("Bronze"); // Tipo conto

    this->setTable();
}

/*void UserInfo::setSilver (SilverUser const& s) {
    userS = s;
    sf = true;

    ui->label_4->setText(QString::fromStdString(silver->getName()));  // Nome
    ui->label_5->setText(QString::fromStdString(silver->getSurname()));     // Cognome
    ui->label_6->setText("Silver"); // Tipo conto
    ui->label_10->setText(QString::number(silver->getTotalTax()));  // Tasse anno
    ui->label_11->setText(QString::number(silver->getTotalBonus()));  // Bonus anno
    ui->label_24->setText(QString::number(silver->getCountNumber()));  // Numero conto
    ui->label_12->setText(QString::number(silver->getCount()));   // Saldo
    ui->label_19->setText(QString::number(silver->getCount()));   // Saldo prelievo
    ui->label_22->setText(QString::number(silver->getCount()));   // Saldo ricarica
    ui->label_66->setText(QString::number(silver->getCount()));   // Saldo
    //ui->label_70->setText("3% = 30 €"); // Costo per diventare gold in base alla percentuale sul saldo
    //ui->label_71->setText("+ 5 %"); // Aumento tasse gold fisse
    //ui->label_73->setText("+ 5.5 %"); // Aumento bonus gold fisso
    ui->label_75->setText(QString::fromStdString(silver->getCode())); // Codice fiscale
    ui->label_77->setText(QString::number(silver->getTelephone())); // Numero di telefono
    ui->label_78->setText(QString::fromStdString(silver->getUsername())); // Username


    this->setTable();


}*/
/*MessagesDataBase* message = new MessagesDataBase();
if (message->loadMessages()) {
    int mex = message->countMessage(silver->getUsername());
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
        Container<Message> app = message->getMessageByUser(silver->getUsername());
        Container<Message>::Iteratore it = app.begin();
        for (int row = 0; row < mex; ++row) {
            for (int col = 0; col < 2; ++col) {
                QModelIndex index = model->index(row, col, QModelIndex());  // 0 for all data


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
}*/

void UserInfo::setTable () {
    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex;
        mex = message->countMessage(user.getUsername());
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
                tr("Ci sono nuovi messaggi da leggere")
            );

            //int num = 0;
            Container<Message> app;
            app = message->getMessageByUser(user.getUsername());
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
                            model->setData(index, QString::fromStdString(app[it]->getSender()));    // Mostro il mittente
                        break;

                        case 1:
                            model->setData(index, QString::fromStdString(app[it]->getText()));  // Mostro il contenuto
                        break;
                    }
                }
                it++;
            }


        } else {
            ui->label_25->setText("Non sono presenti nuovi messaggi da leggere");
            ui->toolButton_5->setEnabled(false);
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
            if (0 <= silver->getCount()-cifra) {
                silver->setCount(silver->getCount()-cifra);
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

                        ui->label_12->setText(QString::number(silver->getCount()));   // Saldo
                        ui->label_19->setText(QString::number(silver->getCount()));   // Saldo prelievo
                        ui->label_22->setText(QString::number(silver->getCount()));   // Saldo ricarica
                        ui->label_66->setText(QString::number(silver->getCount()));   // Saldo
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
                    silver->setCount(silver->getCount()+cifra);
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
    QString bi = ui->lineEdit_3->text();

    double cifra = a.toDouble();
    int conto = bi.toInt();
    bool flag = false;


    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (user.getCountNumber() != conto) {
            if (0 <= user.getCount() - cifra) {
                DataBase d;
                if (d.load()) {
                    User u = d.getUserByCountNumber(conto);  // Username del "ricevente"
                    SilverUser* s = dynamic_cast<SilverUser*> (&u);
                    if (s) {
                        s->setCount(s->getCount() + cifra);
                        d.verifyStillSilver(*s);  // Un utente silver non può "salire" ma verifyStillSilver scrive nel DB l'utente con il conto aggiornato
                        // MANDO UN MESSAGGIO PER LA RICARICA RICEVUTA
                        MessagesDataBase m;
                        if (m.loadMessages()) {
                                m.addMessage(*new Message(s->getUsername(), user.getUsername(), "Ricevuta una ricarica"));

                                SilverUser* silver = dynamic_cast<SilverUser*> (&user);

                                silver->setCount(silver->getCount() - cifra);

                                if (!d.verifyStillSilver(*silver)) {      // Verifico se l'utente è ancora silver
                                    BronzeUser* app = new BronzeUser(*silver);
                                    user = *app;
                                    delete app;
                                    //delete &userS;    // CAUSA CRASH
                                    ui->label_6->setText("Bronze"); // Cambio il tipo di conto

                                    QMessageBox::information(
                                        this,
                                        tr("BankQ - Avviso"),
                                        tr("Con l'ultimo ricarica il tipo di conto è diventanto bronze")
                                    );
                                }

                                ui->label_12->setText(QString::number(silver->getCount()));   // Saldo
                                ui->label_19->setText(QString::number(silver->getCount()));   // Saldo prelievo
                                ui->label_22->setText(QString::number(silver->getCount()));   // Saldo ricarica
                                ui->label_66->setText(QString::number(silver->getCount()));   // Saldo

                                QMessageBox::information(
                                    this,
                                    tr("BankQ - Prelievo"),
                                    tr("Prelievo avvenuto correttamente")
                                );
                        } else {
                            QMessageBox::warning(
                                this,
                                tr("BankQ - Errore"),
                                tr("Errore di caricamento (messaggi)")
                            );
                        }
                    } else {    // È un utente bronze
                        BronzeUser* b = dynamic_cast<BronzeUser*> (&u);
                        b->setCount(b->getCount() + cifra);

                        MessagesDataBase m;
                        if (m.loadMessages()) {
                            m.addMessage(*new Message(b->getUsername(), user.getUsername(), "Ricevuta una ricarica"));
                            if (d.verifyStillBronze(*b))    // Verifico se l'utene "ricevente" diventa Silver
                                m.addMessage(*new Message(b->getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo SILVER"));

                            BronzeUser* bronze = dynamic_cast<BronzeUser*> (&user);

                            bronze->setCount(bronze->getCount() - cifra);

                            // L'utente bronze non può "scendere" però verifyStillBronze riscrive nel DB l'utente con il conto decrementato
                            d.verifyStillBronze(*bronze);

                            ui->label_12->setText(QString::number(bronze->getCount()));   // Saldo
                            ui->label_19->setText(QString::number(bronze->getCount()));   // Saldo prelievo
                            ui->label_22->setText(QString::number(bronze->getCount()));   // Saldo ricarica
                            ui->label_66->setText(QString::number(bronze->getCount()));   // Saldo

                            QMessageBox::information(
                                this,
                                tr("BankQ - Prelievo"),
                                tr("Prelievo avvenuto correttamente")
                            );
                        } else {
                            QMessageBox::warning(
                                this,
                                tr("BankQ - Errore"),
                                tr("Errore di caricamento (messaggi)")
                            );
                        }
                    }
                } else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Errore"),
                        tr("Errore di caricamento del DB")
                    );
                }
            } else {
                    QMessageBox::information(
                        this,
                        tr("BankQ - Prelievo"),
                        tr("Credito insufficiente")
                    );
                }
        } else {
            QMessageBox::information(
                this,
                tr("BankQ - Prelievo"),
                tr("Non è possibile inserire il proprio conto")
            );
        }
    } else {
        QMessageBox::information(
            this,
            tr("BankQ - Prelievo"),
            tr("Importo errato")
        );
    }

  /*      bool bronze = false;
        SilverUser s;
        BronzeUser b;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBronze()) {   // Carico gli utenti bronze
                if (d.verifyNumberBronze(conto)) {   // Verifico che il numero di conto sia di un utente bronze
                    b = d.getBronzeByCount(conto);  // Username del "ricevente"
                    b.setCount(b.getCount() + cifra);
                    bronze = true;
                    if (!d.verifyStillBronze(b)) {
                        // MANDO UN MESSAGGIO ALL'UTENTE PER L'AVVENUTO PASSAGGIO E PER LA RICARICA
                        MessagesDataBase m;
                        if (m.loadMessages()) {
                            if (bf) {
                                m.addMessage(*new Message(b.getUsername(), userB.getUsername(), "Ricevuta una ricarica"));
                                m.addMessage(*new Message(b.getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo SILVER"));
                            } else {
                                m.addMessage(*new Message(b.getUsername(), silver->getUsername(), "Ricevuta una ricarica"));
                                m.addMessage(*new Message(b.getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo SILVER"));
                            }
                        } else {
                            QMessageBox::warning(
                                this,
                                tr("BankQ - Errore"),
                                tr("Errore di caricamento (messaggi)")
                            );
                        }
                    } else {
                        // MANDO UN MESSAGGIO PER LA RICARICA
                        MessagesDataBase m;
                        if (m.loadMessages()) {
                            if (bf)
                                m.addMessage(*new Message(b.getUsername(), userB.getUsername(), "Ricevuta una ricarica"));
                            else
                                m.addMessage(*new Message(b.getUsername(), silver->getUsername(), "Ricevuta una ricarica"));
                        }
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
                         MessagesDataBase m;
                         if (m.loadMessages()) {
                             if (bf)
                                 m.addMessage(*new Message(s.getUsername(), userB.getUsername(), "Ricevuta una ricarica"));
                             else
                                 m.addMessage(*new Message(s.getUsername(), silver->getUsername(),"Ricevuta una ricarica"));
                         }

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
                    silver->setCount(silver->getCount() - cifra);

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
                            tr("Con l'ultimo ricarica il tipo di conto è diventanto bronze")
                        );
                    }

                    ui->label_12->setText(QString::number(silver->getCount()));   // Saldo
                    ui->label_19->setText(QString::number(silver->getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(silver->getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(silver->getCount()));   // Saldo
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
    }*/
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
    DataBase d;
    MessagesDataBase m;
    if (d.load()) {
        d.remove(user);
        if (m.loadMessages())
            m.deleteMessages(user.getUsername());
        else {
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Errore di caricamento (messaggi)")
            );
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }
    //string usr = app.toUtf8().constData(); // Conversione da QString a string
    //string mex = "L'utente "+usr+" desidera chiudere il proprio conto.";
    //User::closeAccount(username);
    //string username = static_cast<string*>(usr);
}



void UserInfo::on_toolButton_5_clicked() { // Messaggi spuntati come visualizzati
    MessagesDataBase* mdb = new MessagesDataBase();
    if (mdb->loadMessages()) {
        // QStandardItemModel(int rows, int columns, QObject * parent = 0)
        QStandardItemModel *model = new QStandardItemModel (0, 2, this);
        QStringList columnName;
        columnName.push_back("Mittente");
        columnName.push_back("Messaggio");
        model->setHorizontalHeaderLabels(columnName);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setModel(model);

        ui->label_25->setText("Non sono presenti messaggi da leggere");

        mdb->deleteMessages(user.getUsername());
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }
}
