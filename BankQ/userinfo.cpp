#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent):QDialog(parent), ui(new Ui::UserInfo) {
    ui->setupUi(this);
}

UserInfo::~UserInfo() {
    delete ui;
}

void UserInfo::setUser (const User& cu) {
    User* ncu = const_cast<User*> (&cu);
    BasicUser* u = dynamic_cast<BasicUser*> (ncu);

    ui->label_4->setText(QString::fromStdString(u->getName()));         // Nome
    ui->label_5->setText(QString::fromStdString(u->getSurname()));      // Cognome
    ui->label_75->setText(QString::fromStdString(u->getCode()));        // Codice fiscale
    ui->label_77->setText(QString::fromStdString(u->getTelephone()));   // Numero di telefono
    ui->label_78->setText(QString::fromStdString(u->getUsername()));    // Username
    ui->label_10->setText(QString::number(u->getTax()));                // Tasse anno
    ui->label_10->setText(QString::number(u->getTax()));                // Tasse anno
    ui->label_24->setText(QString::number(u->getCountNumber()));        // Numero conto
    ui->label_12->setText(QString::number(u->getCount()));              // Saldo info utente
    ui->label_22->setText(QString::number(u->getCount()));              // Saldo ricarica


    if (dynamic_cast<ProUser*> (u)) {
        ProUser* p = dynamic_cast<ProUser*> (u);
        ui->label_11->setText(QString::number(p->getBonus()));          // Bonus anno
        ui->label_6->setText("Pro");                                    // Tipo conto
        if (p->getRequest()) {
            ui->toolButton_3->setEnabled(false);
            ui->label_17->setText("Bonus già ricevuto");
            ui->label_18->setEnabled(false);
        }
    } else {
        ui->label_9->setVisible(false);                                 // Nascondo il bonus
        ui->label_11->setVisible(false);                                // Nascondo il bonus
        ui->label_6->setText("Basic");                                  // Tipo conto
        ui->tabWidget->removeTab(1);                                    // Rimuovo la tabella per richiedere il bonus
    }
    this->setTable(cu, true);
}

void UserInfo::setTable (const User& u, const bool& f) {        // Riempie la tabella in caso vi siano messaggi per l'utente loggato
    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex;
        mex = message->countMessage(u.getUsername());
        if (0 < mex) {

            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);             // Rende le celle non editabili

            QString s = QString::number(mex);
            ui->label_25->setText("Sono presenti " + s + " messaggi da leggere");

            if (f) {    // Appare solo se faccio l'accesso e no anche se elimino un messaggio
                QMessageBox::information(
                    this,
                    tr("BankQ - Messagi"),
                    tr("Ci sono nuovi messaggi da leggere")
                );
            }

            ui->tableView->setColumnWidth(0, 70);                                           // Fisso la larghezza della colonna #0
            ui->tableView->setColumnWidth(1, 419);                                          // Fisso la larghezza della colonna #1
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);    // Rendo non ridimensionabile le colonna

            Container<Message> app;
            app = message->getMessageByUser(u.getUsername());
            Container<Message>::Iteratore it = app.begin();
            for (int row = 0; row < mex; ++row) {
                for (int col = 0; col < 2; ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());

                    switch (col) {
                        case 0:
                            model->setData(index, QString::fromStdString(app[it]->getSender()));// Visualizzo il mittente
                        break;

                        case 1:
                            model->setData(index, QString::fromStdString(app[it]->getText()));  // Visualizzo il contenuto
                        break;
                    }
                }
                it++;
            }


        } else {
            ui->label_25->setText("Non sono presenti nuovi messaggi da leggere");
            ui->toolButton_5->setEnabled(false);

            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            ui->tableView->setColumnWidth(0, 70);                                               // Fisso la larghezza della colonna #0
            ui->tableView->setColumnWidth(1, 419);                                              // Fisso la larghezza della colonna #1
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);        // Rendo non ridimensionabile le colonna
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
        ui->label_18->setEnabled(false);

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
}

void UserInfo::on_toolButton_4_clicked() {  // Ricarica un altro utente
    // Creo il messaggio (ligua inglese)
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Proseguire?"),
                QMessageBox::Yes | QMessageBox::No);

    // Cambio le risposte in italiano
    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        QString a = ui->lineEdit_2->text(); // Cifra da caricare
        QString b = ui->lineEdit_3->text(); // Numero di conto da ricaricare
        QString c = ui->label_78->text();   // Username dell'utente loggato
        QString sal = ui->label_12->text(); // Saldo
        QString nc = ui->label_24->text();  // Numero di conto dell'utente loggato

        double cifra = a.toDouble();
        int conto = b.toInt();
        string username = c.toUtf8().constData();
        int saldo = sal.toInt();

        if (cifra > 0) {
            if (0 <= saldo - cifra) {
                if (nc != b) {                                              // Numero di conti diverso (loggato != ricevente)
                    DataBase d;
                    if (d.load()) {
                        if (d.charge (username, cifra, conto)) {
                                //saldo = saldo - cifra;
                                // Aggiorno la "grafica" del saldo
                                ui->label_12->setText(QString::number(saldo));  // Saldo info utente
                                ui->label_22->setText(QString::number(saldo));  // Saldo ricarica

                                if (100000 < saldo && (saldo - cifra)< 100000) {  // È passato da pro a basic
                                    ui->tabWidget->removeTab(1);                // Rimuovo la tabella per richiedere il bonus
                                    ui->label_6->setText("Basic");              // Cambio il tipo di conto
                                    QMessageBox::information(
                                        this,
                                        tr("BankQ - Avviso"),
                                        tr("Con l'ultimo ricarica il tipo di conto è diventanto Basic")
                                    );
                                }

                                ui->lineEdit_2->setText("");                    // Cifra da caricare
                                ui->lineEdit_3->setText("");                    // Numero di conto

                                QMessageBox::information(
                                    this,
                                    tr("BankQ - Ricarica"),
                                    tr("Ricarica avvenuta correttamenta")
                                );

                        } else {
                                QMessageBox::warning(
                                    this,
                                    tr("BankQ - Ricarica"),
                                    tr("Errore")
                                );
                            }
                    } else {
                        QMessageBox::warning(
                            this,
                            tr("BankQ - Errore"),
                            tr("Errore di caricamento del DB")
                        );
                    }
                }else {
                    QMessageBox::warning(
                        this,
                        tr("BankQ - Ricarica"),
                        tr("Non è possibile inserire il proprio conto")
                    );
                }
            } else {
                QMessageBox::warning(
                    this,
                    tr("BankQ - Ricarica"),
                    tr("Saldo insufficiente")
                );
            }
        } else {
            QMessageBox::warning(
                this,
                tr("BankQ - Ricarica"),
                tr("Importo errato")
            );
        }
    }
}

void UserInfo::on_toolButton_13_clicked() {     // Invio messaggio all'amministratore

    QString s = ui->textEdit->toPlainText();
    string mex = s.toUtf8().constData();        // Messaggio

    QString c = ui->label_78->text();
    string username = c.toUtf8().constData();   // Username dell'utente loggato

    if (mex != "" && mex != " ") {
        MessagesDataBase m;
        if (m.loadMessages()) {
            m.addMessage(*new Message("BankQ", username, mex));
            QMessageBox::information(
                this,
                tr("BankQ - Invio"),
                tr("Messaggio inviato correttamente")
            );
            ui->textEdit->setText("");
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
                tr("Messaggio vuoto")
        );
    }
}

void UserInfo::on_toolButton_clicked() {        // Logout
    MainWindow* w = new MainWindow();           // Dichiaro una nuova MainWindow
    w->show();
    this->close();                              // Chiudo la finestra corrente
}

void UserInfo::on_toolButton_2_clicked() {      // Chiusura conto
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Eliminare il messaggio?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        QString u = ui->label_78->text();
        string username = u.toUtf8().constData();
        MessagesDataBase m;

        if (m.loadMessages()) {
            m.deleteMessages(username);             // Elimino i messaggi dell'utente

            QMessageBox::information(
                this,
                tr("BankQ - Chiusura"),
                tr("La sua richiesta è stata presa in carico, arrivederci")
            );
            this->on_toolButton_clicked();
            m.addMessage(*new Message ("BankQ", username, "L'utente desidera chiudere il proprio conto"));
        } else {
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Errore di caricamento (messaggi)")
            );
        }
    }

}

void UserInfo::on_toolButton_5_clicked() {  // Messaggi spuntati come "visualizzati"
    MessagesDataBase* mdb = new MessagesDataBase();
    if (mdb->loadMessages()) {
        DataBase d;
        if (d.load()) {
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

void UserInfo::on_tableView_clicked (const QModelIndex &index) {    // Elimino la riga selezionata della tabella

    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Eliminare il messaggio?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {

        //int riga = ui->tableView->selectionModel()->currentIndex().row();
        int riga = index.row();
        QString qstr_u = ui->tableView->model()->data(ui->tableView->model()->index(riga, 0)).toString();
        QString qstr_m = ui->tableView->model()->data(ui->tableView->model()->index(riga, 1)).toString();

        string mit = qstr_u.toUtf8().constData();   // Username del mittente
        string mex = qstr_m.toUtf8().constData();   // Testo del messaggio

        QString c = ui->label_78->text();
        string username = c.toUtf8().constData();   // Username dell'utente loggato

        MessagesDataBase m;
        if (m.loadMessages()) {
            if (m.deleteOneMessage(*new Message(username, mit, mex))) {
                DataBase d;
                if (d.load()) {
                    this->setTable(*d.getUser(username), false);
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
}
