#include "admininfo.h"
#include "ui_admininfo.h"
#include "mainwindow.h"
#include "database.h"
#include "messagesdatabase.h"
#include "QStandardItemModel"

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

    ui->label_5->setText(QString::fromStdString(cu.getName()));      // Nome amministratore
    ui->label_8->setText(QString::fromStdString(cu.getSurname()));   // Cognome amministratore
    ui->label_7->setText("Amministratore");                             // Tipo account -> "amministratore" rimmarrà fisso
    ui->label_19->setText(QString::fromStdString(cu.getAddress()));  // Indirizzo amministratore
    ui->label_75->setText(QString::fromStdString(cu.getCode()));     // Codice fiscale amministratore
    ui->label_77->setText(QString::number(cu.getTelephone()));       // Numero di telefono amministratore
    ui->label_78->setText(QString::fromStdString(cu.getUsername())); // Username amministratore

    //ui->label_21->setText("Ci sono 3 richieste di chiudere il conto"); // Username amministratore
    this->setTable(*a);     // Riempie la tabella con i messaggi

    this->setComboBox();    // Riempi la combo box con gli utenti
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

void AdminInfo::setTable (const Admin& u) {   // Riempie la tabella in caso vi siano messaggi per l'utente loggato
    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex;
        mex = message->countMessage("BankQ");
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
            ui->label_21->setText("Sono presenti " + s + " messaggi da leggere");
            QMessageBox::warning(
                this,
                tr("BankQ - Messagi"),
                tr("Ci sono nuovi messaggi da leggere")
            );

            //int num = 0;
            Container<Message> app;
            app = message->getMessageByUser("BankQ");
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
            ui->label_21->setText("Non sono presenti nuovi messaggi da leggere");
            ui->toolButton_4->setEnabled(false);
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento (messaggi)")
        );
    }
}

void AdminInfo::setComboBox () {    // Riempie la combo box
    DataBase d;
    if (d.load()) {
        Container<BasicUser> l = d.getUserNoAdmin();

        for (Container<BasicUser>::Iteratore it = l.begin(); it != l.end(); ++it) {
            ui->comboBox->addItem(QString::fromStdString(l[it]->getUsername()) + " - " + QString::number(l[it]->getCountNumber()));
        }
        Container<ProUser> r = d.getUserNoRequest();
        for (Container<ProUser>::Iteratore it = r.begin(); it != r.end(); ++it) {
            ui->comboBox_2->addItem(QString::fromStdString(r[it]->getUsername()) + " - " + QString::number(r[it]->getCountNumber()));
        }
    }

}

void AdminInfo::on_toolButton_clicked () {   // Logout
    MainWindow* w = new MainWindow();   // Creo una nuova MainWindow
    w->show();
    this->close();  // Chiudo la finestra corrente
}

void AdminInfo::on_toolButton_3_clicked() {     // Elimina un utente
    QString qstr = ui->comboBox->itemText(ui->comboBox->currentIndex());  // Elemento selezionato
    //QString qstr = qv.toString();
    string str = qstr.toUtf8().constData(); // "Username - #conto"

    string delimiter = " - ";
    string user = str.substr(0, str.find(delimiter));   // Ottengo solo lo username

    DataBase d;
    if (d.load()) {
        d.remove(*d.getUser(user));    // Rimuovo l'utente dal DB

        QMessageBox::information(
            this,
            tr("BankQ - Rimozione Utente"),
            tr("Rimozione avvenuta correttamente")
        );
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }
    this->setComboBox();
}

void AdminInfo::on_toolButton_4_clicked() {     // Messaggi spuntati come "visualizzati"
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
            ui->label_21->setText("Non sono presenti messaggi da leggere");

            QString c = ui->label_78->text();
            string username = c.toUtf8().constData();
            User* user = d.getUser(username);

            mdb->deleteMessages(user->getUsername());
            ui->toolButton_4->setEnabled(false);
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

void AdminInfo::on_toolButton_5_clicked() {     // Assegna il bonus (utente selezionato)
    QString qstr = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());  // Elemento selezionato
    //QString qstr = qv.toString();
    string str = qstr.toUtf8().constData(); // "Username - #conto"

    string delimiter = " - ";
    string user = str.substr(0, str.find(delimiter));   // Ottengo solo lo username

    DataBase d;
    if (d.load()) {
        d.giveBonus(*d.getUser(user));    // Assegno il bonus all'utente passato
        this->setComboBox();

        QMessageBox::information(
            this,
            tr("BankQ - Assengnazione bonus"),
            tr("Bonus assegnato")
        );
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }
}

void AdminInfo::on_toolButton_6_clicked() { // Assegna il bonus (a "tutti")
    DataBase d;
    if (d.load()) {
        d.giveBonusToAll();    // Assegna il bonus agli utenti che non lo hanno ancora ricevuto
        this->setComboBox();

        QMessageBox::information(
            this,
            tr("BankQ - Assengnazione bonus"),
            tr("Bonus assegnato")
        );
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }
}
