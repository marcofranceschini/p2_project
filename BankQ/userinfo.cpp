using namespace std;
#include "userinfo.h"
#include "ui_userinfo.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "database.h"
#include "basicuser.h"
#include "prouser.h"
#include "QStandardItemModel"

UserInfo::UserInfo(QWidget *parent):QDialog(parent), ui(new Ui::UserInfo) {
    ui->setupUi(this);
}

UserInfo::~UserInfo() {
    delete ui;
}

void UserInfo::setUser (const User& cu) {
    User* ncu = const_cast<User*> (&cu);
    BasicUser* u = dynamic_cast<BasicUser*> (ncu);

    ui->label_4->setText(QString::fromStdString(u->getName()));     // Nome
    ui->label_5->setText(QString::fromStdString(u->getSurname()));  // Cognome
    ui->label_75->setText(QString::fromStdString(u->getCode()));    // Codice fiscale
    ui->label_77->setText(QString::number(u->getTelephone()));      // Numero di telefono
    ui->label_78->setText(QString::fromStdString(u->getUsername()));// Username
    ui->label_10->setText(QString::number(u->getTax()));            // Tasse anno
    ui->label_10->setText(QString::number(u->getTax()));            // Tasse anno
    ui->label_24->setText(QString::number(u->getCountNumber()));    // Numero conto
    ui->label_12->setText(QString::number(u->getCount()));          // Saldo
    ui->label_22->setText(QString::number(u->getCount()));          // Saldo ricarica
    ui->label_66->setText(QString::number(u->getCount()));          // Saldo


    if (dynamic_cast<ProUser*> (u)) {
        ProUser* p = dynamic_cast<ProUser*> (u);
        ui->label_11->setText(QString::number(p->getBonus()));     // Bonus anno
        ui->label_6->setText("Pro");                               // Tipo conto
        if (p->getRequest()) {
            ui->toolButton_3->setEnabled(false);
            ui->label_17->setText("Bonus già ricevuto");
            ui->label_18->setEnabled(false);
        }
    } else {
        ui->label_9->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_6->setText("Basic");                             // Tipo conto
        ui->tabWidget->removeTab(1);
    }
    this->setTable(cu);
}

/*void UserInfo::setPro (ProUser const& s) {
    userS = s;
    sf = true;

    ui->label_4->setText(QString::fromStdString(Pro->getName()));  // Nome
    ui->label_5->setText(QString::fromStdString(Pro->getSurname()));     // Cognome
    ui->label_6->setText("Pro"); // Tipo conto
    ui->label_10->setText(QString::number(Pro->getTotalTax()));  // Tasse anno
    ui->label_11->setText(QString::number(Pro->getTotalBonus()));  // Bonus anno
    ui->label_24->setText(QString::number(Pro->getCountNumber()));  // Numero conto
    ui->label_12->setText(QString::number(Pro->getCount()));   // Saldo
    ui->label_19->setText(QString::number(Pro->getCount()));   // Saldo prelievo
    ui->label_22->setText(QString::number(Pro->getCount()));   // Saldo ricarica
    ui->label_66->setText(QString::number(Pro->getCount()));   // Saldo
    //ui->label_70->setText("3% = 30 €"); // Costo per diventare gold in base alla percentuale sul saldo
    //ui->label_71->setText("+ 5 %"); // Aumento tasse gold fisse
    //ui->label_73->setText("+ 5.5 %"); // Aumento bonus gold fisso
    ui->label_75->setText(QString::fromStdString(Pro->getCode())); // Codice fiscale
    ui->label_77->setText(QString::number(Pro->getTelephone())); // Numero di telefono
    ui->label_78->setText(QString::fromStdString(Pro->getUsername())); // Username


    this->setTable();


}*/
/*MessagesDataBase* message = new MessagesDataBase();
if (message->loadMessages()) {
    int mex = message->countMessage(Pro->getUsername());
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
        Container<Message> app = message->getMessageByUser(Pro->getUsername());
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

void UserInfo::setTable (const User& u) {   // Riempie la tabella in caso vi siano messaggi per l'utente loggato
    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex;
        mex = message->countMessage(u.getUsername());
        if (0 < mex) {

            // QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  // Rende le celle non editabili

            QString s = QString::number(mex);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");
            QMessageBox::warning(
                this,
                tr("BankQ - Messagi"),
                tr("Ci sono nuovi messaggi da leggere")
            );

            //int num = 0;
            Container<Message> app;
            app = message->getMessageByUser(u.getUsername());
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

void UserInfo::on_toolButton_3_clicked() {  // Richiesta bonus anticipato

    QString s = ui->label_78->text();       // Username dell'utente loggato
    string username = s.toUtf8().constData();

    MessagesDataBase m;
    if (m.loadMessages()) {
        m.addMessage(*new Message ("BankQ", username, "L'utente desidera ricevere il bonus anticipato"));
        //ProUser* pro = dynamic_cast<ProUser*>(user);
        ui->toolButton_3->setEnabled(false);
        ui->label_17->setText("Bonus già richiesto");

        QMessageBox::information(
            this,
            tr("BankQ - Chiusura"),
            tr("La sua richiesta è stata presa in carico")
        );
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB messaggi")
        );
    }
    /*double cifra = a.toDouble();
    int conto = b.toInt();
    bool flag = false;

    if (cifra > 0) {
        // Tolgo l'importo dal conto dell'utente loggato
        if (bf) {   // E' un utente Basic
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
        } else {    // Utente Pro
            if (0 <= Pro->getCount()-cifra) {
                Pro->setCount(Pro->getCount()-cifra);
                flag = true;
            } else {
                QMessageBox::information(
                    this,
                    tr("BankQ - Prelievo"),
                    tr("Credito insufficiente")
                );
            }
        }

        bool Basic = false;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBasic()) {   // Carico gli utenti Basic
                if (d.verifyNumberBasic(conto)) {   // Verifico che il numero di conto sia di un utente Basic
                    BasicUser b = d.getBasicByCount(conto);
                    b.setCount(b.getCount()+cifra);
                    Basic = true;

                    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
                }

            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Errore di caricamento (Basic)")
                );
            }

            bool Pro = false;

            if (!Basic) {
                if (d.loadPro()) {   // Carico gli utenti Pro
                    if (d.verifyNumberPro(conto)) {   // Verifico che il numero di conto sia di un utente Pro
                        ProUser s = d.getProByCount(conto);
                        s.setCount(s.getCount()+cifra);
                        Pro = true;

                        ui->label_12->setText(QString::number(Pro->getCount()));   // Saldo
                        ui->label_19->setText(QString::number(Pro->getCount()));   // Saldo prelievo
                        ui->label_22->setText(QString::number(Pro->getCount()));   // Saldo ricarica
                        ui->label_66->setText(QString::number(Pro->getCount()));   // Saldo
                    } else {    // Se il numero non è né Pro né Basic allora è errato

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
                        tr("Errore di caricamento (Pro)")
                    );
                }
            }
            // Se non ho trovato un numero di conto ritorno l'importo prelevato
            if (!Basic && !Pro) {
                if (bf) // E' un utente Basic
                    userB.setCount(userB.getCount()+cifra);
                else
                    Pro->setCount(Pro->getCount()+cifra);
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

    // Verifico se l'utente scende ad utente Basic + messaggio

}

void UserInfo::on_toolButton_4_clicked() {  // Ricarica un altro utente
    QString a = ui->lineEdit_2->text();     // Cifra da caricare
    QString bi = ui->lineEdit_3->text();    // Numero di conto
    QString c = ui->label_78->text();       // Username dell'utente loggato

    double cifra = a.toDouble();
    int conto = bi.toInt();
    string username = c.toUtf8().constData();
    //bool flag = false;

    if (cifra > 0) {
        DataBase d;
        if (d.load()) {
            User* m_app = d.getUser(username);
            BasicUser* mittente = dynamic_cast<BasicUser*> (m_app); // Username dell'utente loggato

            QString st =QString::fromStdString(mittente->getName());    // DA RIMUOVERE
            qDebug("MMM-" + st.toLatin1() + "-MMM");                    // DA RIMUOVERE

            if (mittente->getCountNumber() != conto) {      // Verifico che il conto da ricarica e quello dell'utente loggato siano diversi
                if (0 <= mittente->getCount() - cifra) {    // Verifico che il conto abbia sufficiente credito

                    User* r_app = d.getUserByCountNumber(conto);  // Username del "ricevente"
                    BasicUser* ricevente = dynamic_cast<BasicUser*> (r_app);

                    QString st =QString::fromStdString(ricevente->getName());    // DA RIMUOVERE
                    qDebug("RRR-" + st.toLatin1() + "-RRR");                    // DA RIMUOVERE

                    // Aggiunto l'importo al conto dell'utente "ricevente"
                    ricevente->setCount(ricevente->getCount() + cifra);
                    QString qstr = "Ricevuta una ricarica di € " + QString::number(cifra);
                    string str = qstr.toUtf8().constData();
                    MessagesDataBase m;
                    if (m.loadMessages())   {
                        // Messaggio per la ricarica ricevuta
                        m.addMessage(*new Message(ricevente->getUsername(), mittente->getUsername(), str));

                        // Messaggio per un'eventuale passaggio da Basic a Pro
                        if (!d.verifyStillSame(*ricevente))   // Se l'utente è Basic allora può diventare Pro, altrimenti non accade "nulla"
                            // Se l'utente passa a Pro invio un messaggio
                            m.addMessage(*new Message(ricevente->getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));
                    } else {
                        QMessageBox::warning(
                            this,
                            tr("BankQ - Errore"),
                            tr("Errore di caricamento (messaggi)")
                        );
                    }
                        // MANDO UN MESSAGGIO PER LA RICARICA RICEVUTA


                     //ProUser* Pro = dynamic_cast<ProUser*> (user);
                    // Tolgo l'importo dal conto dell'utente loggato
                    mittente->setCount(mittente->getCount() - cifra);

                    if (!d.verifyStillSame(*mittente)) {   // Se l'utente è Pro allora può diventare Basic, altrimenti non accade "nulla"
                        /*BasicUser* app = new BasicUser(*s);
                        user = app;
                        delete app;*/
                        //delete &userS;    // CAUSA CRASH
                        ui->label_6->setText("Basic"); // Cambio il tipo di conto

                        QMessageBox::information(
                            this,
                            tr("BankQ - Avviso"),
                            tr("Con l'ultimo ricarica il tipo di conto è diventanto Basic")
                        );
                    }
                    // Aggiorno la "grafica" del saldo
                    ui->label_12->setText(QString::number(mittente->getCount()));   // Saldo
                    ui->label_22->setText(QString::number(mittente->getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(mittente->getCount()));   // Saldo

                    ui->lineEdit_2->setText("");    // Cifra da caricare
                    ui->lineEdit_3->setText("");    // Numero di conto

                    QMessageBox::information(
                        this,
                        tr("BankQ - Ricarica"),
                        tr("Ricarica avvenuta correttamenta")
                    );
                    /*} else {    // Il "ricevente" è Basic
                        BasicUser* b = dynamic_cast<BasicUser*> (u);
                        MainWindow f;   // DA RIMUOVERE
                        f.boom();       // DA RIMUOVERE
                        b->setCount(b->getCount() + cifra);

                        MessagesDataBase m;
                        if (m.loadMessages()) {
                            m.addMessage(*new Message(b->getUsername(), user->getUsername(), "Ricevuta una ricarica"));
                            if (d.verifyStillBasic(*b))    // Verifico se l'utene "ricevente" diventa Pro
                                m.addMessage(*new Message(b->getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));

                            //BasicUser* Basic = dynamic_cast<BasicUser*> (user);

                            user->setCount(user->getCount() - cifra);

                            // L'utente Basic non può "scendere" però verifyStillBasic riscrive nel DB l'utente con il conto decrementato
                            d.verifyStillBasic(*user);

                            ui->label_12->setText(QString::number(user->getCount()));   // Saldo
                            ui->label_19->setText(QString::number(user->getCount()));   // Saldo prelievo
                            ui->label_22->setText(QString::number(user->getCount()));   // Saldo ricarica
                            ui->label_66->setText(QString::number(user->getCount()));   // Saldo

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
                    }*/
                } else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Prelievo"),
                        tr("Credito insufficiente")
                    );
                }
            } else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Prelievo"),
                        tr("Non è possibile inserire il proprio conto")
                    );
                }
        } else {
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Errore di caricamento del DB")
            );
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Prelievo"),
            tr("Importo errato")
        );
    }

  /*      bool Basic = false;
        ProUser s;
        BasicUser b;
        // Ricarico il conto di destinazione
        if (flag) {
            DataBase d;
            if (d.loadBasic()) {   // Carico gli utenti Basic
                if (d.verifyNumberBasic(conto)) {   // Verifico che il numero di conto sia di un utente Basic
                    b = d.getBasicByCount(conto);  // Username del "ricevente"
                    b.setCount(b.getCount() + cifra);
                    Basic = true;
                    if (!d.verifyStillBasic(b)) {
                        // MANDO UN MESSAGGIO ALL'UTENTE PER L'AVVENUTO PASSAGGIO E PER LA RICARICA
                        MessagesDataBase m;
                        if (m.loadMessages()) {
                            if (bf) {
                                m.addMessage(*new Message(b.getUsername(), userB.getUsername(), "Ricevuta una ricarica"));
                                m.addMessage(*new Message(b.getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));
                            } else {
                                m.addMessage(*new Message(b.getUsername(), Pro->getUsername(), "Ricevuta una ricarica"));
                                m.addMessage(*new Message(b.getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));
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
                                m.addMessage(*new Message(b.getUsername(), Pro->getUsername(), "Ricevuta una ricarica"));
                        }
                    }
                }

            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Errore"),
                    tr("Errore di caricamento (Basic)")
                );
            }

            bool Pro = false;

            if (!Basic) {
                if (d.loadPro()) {   // Carico gli utenti Pro
                    if (d.verifyNumberPro(conto)) {   // Verifico che il numero di conto sia di un utente Pro
                        s = d.getProByCount(conto);
                        s.setCount(s.getCount() + cifra);
                        Pro = true;

                         // Un utente Pro non può "salire" ma verifyStillPro riscrive sul DB con il conto aggiornato
                         d.verifyStillPro(s);
                        // MANDO UN MESSAGGIO PER LA RICARICA
                         MessagesDataBase m;
                         if (m.loadMessages()) {
                             if (bf)
                                 m.addMessage(*new Message(s.getUsername(), userB.getUsername(), "Ricevuta una ricarica"));
                             else
                                 m.addMessage(*new Message(s.getUsername(), Pro->getUsername(),"Ricevuta una ricarica"));
                         }

                    } else {    // Se il numero non è né Pro né Basic allora è errato

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
                        tr("Errore di caricamento (Pro)")
                    );
                }
            }

            MainWindow u;   // DA RIMUOVERE


            if ((Basic && !Pro) || (!Basic && Pro)) {   // Se ho trovato un numero di conto sottraggo l'importo
                if (bf) {   // Aggiorno i campi con il nuovo saldo
                    userB.setCount(userB.getCount() - cifra);

                    // L'utente Basic non può "scendere" però verifyStillBasic riscrive nel DB l'utente con il conto decrementato
                    d.verifyStillBasic(userB);

                    ui->label_12->setText(QString::number(userB.getCount()));   // Saldo
                    ui->label_19->setText(QString::number(userB.getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(userB.getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(userB.getCount()));   // Saldo
                } else {
                    Pro->setCount(Pro->getCount() - cifra);

                    if (!d.verifyStillPro(userS)) {      // Verifico se l'utente è ancora Pro
                        sf = false;
                        bf = true;
                        BasicUser* app = new BasicUser(userS);
                        userB = *app;
                        delete app;
                        //delete &userS;    // CAUSA CRASH
                        ui->label_6->setText("Basic"); // Cambio il tipo di conto

                        QMessageBox::information(
                            this,
                            tr("BankQ - Avviso"),
                            tr("Con l'ultimo ricarica il tipo di conto è diventanto Basic")
                        );
                    }

                    ui->label_12->setText(QString::number(Pro->getCount()));   // Saldo
                    ui->label_19->setText(QString::number(Pro->getCount()));   // Saldo prelievo
                    ui->label_22->setText(QString::number(Pro->getCount()));   // Saldo ricarica
                    ui->label_66->setText(QString::number(Pro->getCount()));   // Saldo
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
    // Verifico se l'utente scende ad utente Basic + messaggio
}

void UserInfo::on_toolButton_clicked() {    // Logout
    MainWindow* w = new MainWindow(); // Dichiaro una nuova MainWindow
    w->show();
    this->close(); // Chiudo la finestra corrente
}

void UserInfo::on_toolButton_2_clicked() { // Chiusura conto
    // DA FARE - notificare con un messaggio all'admin della chiusura
    DataBase d;
    MessagesDataBase m;

    if (d.load()) {
        QString u = ui->label_78->text();
        string username = u.toUtf8().constData();
        //User* user = d.getUser(username);
        //d.remove(*user);
        if (m.loadMessages()) {
            m.deleteMessages(username); // Elimino i messaggi dell'utente

            QMessageBox::information(
                this,
                tr("BankQ - Chiusura"),
                tr("La sua richiesta è stata presa in carico, arrivederci")
            );
            this->on_toolButton_clicked();
            m.addMessage(*new Message ("admin", username, "L'utente desidera chiudere il proprio conto"));
        } else {
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



void UserInfo::on_toolButton_5_clicked() {  // Messaggi spuntati come "visualizzati"
    MessagesDataBase* mdb = new MessagesDataBase();
    if (mdb->loadMessages()) {
        DataBase d;
        if (d.load()) {// QStandardItemModel(int rows, int columns, QObject * parent = 0)
            QStandardItemModel *model = new QStandardItemModel (0, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);
            ui->label_25->setText("Non sono presenti messaggi da leggere");

            QString c = ui->label_78->text();
            string username = c.toUtf8().constData();
            User* user = d.getUser(username);

            mdb->deleteMessages(user->getUsername());
            ui->toolButton_5->setEnabled(false);
        } else {
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
            tr("Errore di caricamento (messaggi)")
        );
    }
}

void UserInfo::on_tableView_clicked(const QModelIndex &index) { // Elimino la riga selezionata della tabella

    /*QItemSelectionModel *select = ui->tableView->selectionModel();
    select->selectedRows(); // return selected row(s)
    */

    int riga = ui->tableView->selectionModel()->currentIndex().row();
    QString qstr_u = ui->tableView->model()->data(ui->tableView->model()->index(riga, 0)).toString();
    QString qstr_m = ui->tableView->model()->data(ui->tableView->model()->index(riga, 1)).toString();

    string mit = qstr_u.toUtf8().constData();   // Username del mittente
    string mex = qstr_m.toUtf8().constData();   // Testo del messaggio

    QString c = ui->label_78->text();
    string username = c.toUtf8().constData();   // Username dell'utente loggato

    QString st =QString::fromStdString(mex);   // DA RIMUOVERE
    qDebug("QQQ-" + st.toLatin1() + "-QQQ");                              // DA RIMUOVERE

    MessagesDataBase m;
    if (m.loadMessages()) {
        if (m.deleteOneMessage(*new Message(username, mit, mex))) {
            DataBase d;
            if (d.load()) {
                this->setTable(*d.getUser(username));
                QMessageBox::information(
                        this,
                        tr("BankQ - Rimozione"),
                        tr("Messaggio rimosso")
                    );
            } else {
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
                tr("Errore")
            );
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }

}
