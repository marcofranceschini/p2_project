#include "admininfo.h"

AdminInfo::AdminInfo(QWidget *parent):QDialog(parent), ui(new Ui::AdminInfo) {
    ui->setupUi(this);
}

AdminInfo::~AdminInfo() {
    delete ui;
}

void AdminInfo::setAdmin (const User& cu) {

    ui->label_5->setText(QString::fromStdString(cu.getName()));      // Nome amministratore
    ui->label_8->setText(QString::fromStdString(cu.getSurname()));   // Cognome amministratore
    ui->label_7->setText("Amministratore");                          // Tipo account -> "amministratore" rimmarrà fisso
    ui->label_19->setText(QString::fromStdString(cu.getAddress()));  // Indirizzo amministratore
    ui->label_75->setText(QString::fromStdString(cu.getCode()));     // Codice fiscale amministratore
    ui->label_77->setText(QString::fromStdString(cu.getTelephone()));// Numero di telefono amministratore
    ui->label_78->setText(QString::fromStdString(cu.getUsername())); // Username amministratore

    this->setTable("BankQ", true);  // Riempie la tabella con i messaggi per l'utente
    this->setComboBox();            // Riempi la comboBox con gli utenti da eliminare
    this->setComboBox_2();          // Riempi la comboBox con gli utenti a cui assegnare il bonus
    this->setComboBox_5();          // Riempi la comboBox con gli utenti che possono essere modificati

    ui->lineEdit_35->setReadOnly(true); // Nella modifica non è possibile cambiare il saldo
}

void AdminInfo::on_toolButton_2_clicked() {     // Inserisce un nuovo utente
    string nom = (ui->lineEdit->text()).toUtf8().constData();     // Nome
    string cog = (ui->lineEdit_2->text()).toUtf8().constData();   // Cognome
    string ind = (ui->lineEdit_3->text()).toUtf8().constData();   // Indirizzo
    string tel = (ui->lineEdit_4->text()).toUtf8().constData();   // Telefono
    string cod = (ui->lineEdit_5->text()).toUtf8().constData();   // Codice fiscale
    string usr = (ui->lineEdit_6->text()).toUtf8().constData();   // Username
    string pin = (ui->lineEdit_7->text()).toUtf8().constData();   // PIN
    string sal = (ui->lineEdit_8->text()).toUtf8().constData();   // Saldo
    string num = (ui->lineEdit_9->text()).toUtf8().constData();   // Numero conto

    DataBase* d = new DataBase();
    if (d->load()) {
        if (atoi(pin.c_str()) && atoi(tel.c_str()) && atoi(sal.c_str()) && atoi(num.c_str())) {    // Verifico che il PIN, telefono, saldo e #conto siano numerici
            int int_sal = atoi(sal.c_str());
            int int_num = atoi(num.c_str());
            if (5 == pin.length()) {    // Verifico che il PIN abbia 5 cifre
                if (nom != "" && cog != "" && ind != "" && cod != "" && usr != "") {
                    if (!d->verifyExistingUsername(usr) && !d->verifyExistingCountNumber(int_num)) {  // Controllo che username e #conto siano univoci

                        d->addUser(*new BasicUser(nom, cog, ind, tel, cod, usr, pin, int_num, int_sal));

                        ui->lineEdit->setText("");    // Nome
                        ui->lineEdit_2->setText("");  // Cognome
                        ui->lineEdit_3->setText("");  // Indirizzo
                        ui->lineEdit_4->setText("");  // Telefono
                        ui->lineEdit_5->setText("");  // Codice fiscale
                        ui->lineEdit_6->setText("");  // Username
                        ui->lineEdit_7->setText("");  // PIN
                        ui->lineEdit_8->setText("");  // Saldo
                        ui->lineEdit_9->setText("");  // Numero conto

                        this->empty_ComboBox();       // Svuoto la combo box
                        this->setComboBox();          // Aggiorno la combo box (per rimuovere) con l'utente aggiunto

                        this->empty_ComboBox_2();     // Svuoto la combo box
                        this->setComboBox_2();        // Aggiorno la combo box (per assegnare il bonus) con l'utente aggiunto

                        this->empty_ComboBox_5();     // Svuoto la combo box
                        this->setComboBox_5();        // Aggiorno la combo box (per modificare) con l'utente aggiunto

                        QMessageBox::information(
                            this,
                            tr("BankQ - Nuovo Utente"),
                            tr("Aggiunta avvenuta correttamente")
                        );
                    } else {
                        if (d->verifyExistingUsername(usr)) {
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
                    tr("Il PIN deve avere 5 cifre")
                );
            }
        } else {
            QMessageBox::warning(
                this,
                tr("1- BankQ - Errore"),
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
}

void AdminInfo::setTable (const string& u,  const bool& f) {   // Riempie la tabella in caso vi siano messaggi per l'utente loggato
    MessagesDataBase* message = new MessagesDataBase();
    if (message->loadMessages()) {
        int mex;
        mex = message->countMessage(u);
        if (0 < mex) {

            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);    // Rende le celle non editabili

            QString s = QString::number(mex);
            ui->label_21->setText("Sono presenti " + s + " messaggi da leggere");

            if (f) {    // Appare solo se faccio l'accesso e no anche se elimino un messaggio
                QMessageBox::information(
                    this,
                    tr("BankQ - Messagi"),
                    tr("Ci sono nuovi messaggi da leggere")
                );
            }

            ui->tableView->setColumnWidth(0, 70);   // Fisso la larghezza della colonna #0
            ui->tableView->setColumnWidth(1, 409);  // Fisso la larghezza della colonna #1
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);    // Rendo non ridimensionabile le colonne

            Container<Message> app;
            app = message->getMessageByUser(u);
            Container<Message>::Iteratore it = app.begin();
            for (int row = 0; row < mex; ++row) {
                for (int col = 0; col < 2; ++col) {
                    QModelIndex index = model->index(row, col, QModelIndex());  // 0 for all data

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
        } else {    // Tabella senza messaggi
            ui->label_21->setText("Non sono presenti nuovi messaggi da leggere");
            ui->toolButton_4->setEnabled(false);

            QStandardItemModel *model = new QStandardItemModel (mex, 2, this);
            QStringList columnName;
            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");
            model->setHorizontalHeaderLabels(columnName);
            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);

            ui->tableView->setColumnWidth(0, 70);   // Fisso la larghezza della colonna #0
            ui->tableView->setColumnWidth(1, 409);  // Fisso la larghezza della colonna #1
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);    // Rendo non ridimensionabile le colonne
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB messaggi")
        );
    }
}

void AdminInfo::setComboBox () {    // Riempie la comboBox
    DataBase* d = new DataBase();
    if (d->load()) {
        Container<BasicUser> l = d->getUserNoAdmin();
        if (0 < l.getSize()) {
            for (Container<BasicUser>::Iteratore it = l.begin(); it != l.end(); ++it) {
                ui->comboBox->addItem(QString::fromStdString(l[it]->getUsername()) + " - " + QString::number(l[it]->getCountNumber()));
            }
            ui->toolButton_3->setEnabled(true);
        } else {    // Non ho utenti da eliminare
            ui->comboBox->addItem("Nessun utente");
            ui->toolButton_3->setEnabled(false);
        }
    }
}

void AdminInfo::empty_ComboBox () {     // Svuota la combo box
    int size = ui->comboBox->count();   // Numero di elementi nella comboBox

    while (0 <= size) {                 // "Azzero" la comboBox
        ui->comboBox->removeItem(size);
        size--;
    }
}

void AdminInfo::setComboBox_2 () {    // Riempie la comboBox_2
    DataBase* d = new DataBase();
    if (d->load()) {
        Container<BasicUser> u = d->getUserNoAdmin();

        if (0 < u.getSize() || d->verifyPro()) {    // Se ho utenti o utenti pro nel DB
            Container<ProUser> r = d->getUserNoRequest();

            if (0 < r.getSize()) {                  // Se non ho utenti pro

                for (Container<ProUser>::Iteratore it = r.begin(); it != r.end(); ++it) {
                    ui->comboBox_2->addItem(QString::fromStdString(r[it]->getUsername()) + " - " + QString::number(r[it]->getCountNumber()));
                }

                ui->toolButton_5->setEnabled(true);
                ui->toolButton_6->setEnabled(true);

                if (d->verifyRequest()) // Se ho utenti pro che hanno già ricevuto il bonus
                    ui->toolButton_7->setEnabled(true);
                else
                    ui->toolButton_7->setEnabled(false);

            } else {    // Non ho utenti a cui assegnare il bonus
                ui->comboBox_2->addItem("Nessun utente");
                ui->toolButton_5->setEnabled(false);
                ui->toolButton_6->setEnabled(false);
            }
        } else {
            ui->comboBox_2->addItem("Nessun utente");
            ui->toolButton_5->setEnabled(false);
            ui->toolButton_6->setEnabled(false);
            ui->toolButton_7->setEnabled(false);
        }
    }
}

void AdminInfo::empty_ComboBox_2 () {       // Svuota la combo box
    int size = ui->comboBox_2->count();     // Numero di elementi nella comboBox

    while (0 <= size) {                     // "Azzero" la comboBox
        ui->comboBox_2->removeItem(size);
        size--;
    }
}

void AdminInfo::setComboBox_5 () {    // Riempie la comboBox_5
    DataBase* d = new DataBase();
    if (d->load()) {
        Container<BasicUser> l = d->getUserNoAdmin();
        if (0 < l.getSize()) {
            for (Container<BasicUser>::Iteratore it = l.begin(); it != l.end(); ++it) {
                ui->comboBox_5->addItem(QString::fromStdString(l[it]->getUsername()) + " - " + QString::number(l[it]->getCountNumber()));
            }
            ui->toolButton_8->setEnabled(true);

            ui->lineEdit_28->setEnabled(true);   // Nome
            ui->lineEdit_29->setEnabled(true);   // Cognome
            ui->lineEdit_30->setEnabled(true);   // Indirizzo
            ui->lineEdit_31->setEnabled(true);   // Telefono
            ui->lineEdit_32->setEnabled(true);   // Codice fiscale
            ui->lineEdit_33->setEnabled(true);   // Username
            ui->lineEdit_34->setEnabled(true);   // PIN
            ui->lineEdit_35->setEnabled(true);   // Saldo
            ui->lineEdit_36->setEnabled(true);   // Numero di conto

        } else {    // Non ho utenti da modificare

            ui->comboBox_5->addItem("Nessun utente");
            ui->toolButton_8->setEnabled(false);

            ui->lineEdit_28->setText("");   // Nome
            ui->lineEdit_29->setText("");   // Cognome
            ui->lineEdit_30->setText("");   // Indirizzo
            ui->lineEdit_31->setText("");   // Telefono
            ui->lineEdit_32->setText("");   // Codice fiscale
            ui->lineEdit_33->setText("");   // Username
            ui->lineEdit_34->setText("");   // PIN
            ui->lineEdit_35->setText("");   // Saldo
            ui->lineEdit_36->setText("");   // Numero di conto

            ui->lineEdit_28->setEnabled(false);   // Nome
            ui->lineEdit_29->setEnabled(false);   // Cognome
            ui->lineEdit_30->setEnabled(false);   // Indirizzo
            ui->lineEdit_31->setEnabled(false);   // Telefono
            ui->lineEdit_32->setEnabled(false);   // Codice fiscale
            ui->lineEdit_33->setEnabled(false);   // Username
            ui->lineEdit_34->setEnabled(false);   // PIN
            ui->lineEdit_35->setEnabled(false);   // Saldo
            ui->lineEdit_36->setEnabled(false);   // Numero di conto
        }
    }
}

void AdminInfo::empty_ComboBox_5 () {       // Svuota la combo box 5
    int size = ui->comboBox_5->count();     // Numero di elementi nella comboBox

    while (0 <= size) {                     // "Azzero" la comboBox
        ui->comboBox_5->removeItem(size);
        size--;
    }
}

void AdminInfo::on_toolButton_clicked () {  // Logout
    MainWindow* w = new MainWindow();       // Creo una nuova MainWindow
    w->show();
    this->close();                          // Chiudo la finestra corrente
}

void AdminInfo::on_toolButton_3_clicked() { // Elimina un utente
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Proseguire?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        QString qstr = ui->comboBox->itemText(ui->comboBox->currentIndex());  // Elemento selezionato

        string str = qstr.toUtf8().constData();                     // "Username - #conto"
        string delimiter = " - ";
        string user = str.substr(0, str.find(delimiter));           // Ottengo solo lo username

        DataBase* d = new DataBase();
        if (d->load()) {
            d->remove(*d->getUser(user));                           // Rimuovo l'utente dal DB

            ui->comboBox->removeItem(ui->comboBox->currentIndex()); // Rimuove l'utente dalla combo box

            if(ui->comboBox->count() == 0) {// La combo box è vuota

                this->setComboBox();        // Per scrivere il messaggio "nessun utente"
                this->setComboBox_2();      // Così disattiva il pulsante per sbloccare il bonus
                this->setComboBox_5();      // Così azzerra le text edit
            }

            this->empty_ComboBox_2();       // Svuoto la combo box
            this->setComboBox_2();          // Aggiorno la combo box (per assegnare il bonus) senza l'utente rimosso

            this->empty_ComboBox_5();       // Svuoto la combo box
            this->setComboBox_5();          // Aggiorno la combo box (per modificare) senza l'utente rimosso

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
    }
}

void AdminInfo::on_toolButton_4_clicked() {     // Messaggi spuntati come "visualizzati"
    MessagesDataBase* mdb = new MessagesDataBase();

    if (mdb->loadMessages()) {
        DataBase* d = new DataBase();
        if (d->load()) {

            QStandardItemModel *model = new QStandardItemModel (0, 2, this);
            QStringList columnName;

            columnName.push_back("Mittente");
            columnName.push_back("Messaggio");

            model->setHorizontalHeaderLabels(columnName);

            ui->tableView->verticalHeader()->setVisible(false);
            ui->tableView->setModel(model);
            ui->label_21->setText("Non sono presenti messaggi da leggere");

            mdb->deleteMessages("BankQ");
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
            tr("Errore di caricamento del DB messaggi")
        );
    }
}

void AdminInfo::on_toolButton_5_clicked() {     // Assegna il bonus (utente selezionato)
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Proseguire?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        QString qstr = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());  // Elemento selezionato

        string str = qstr.toUtf8().constData();             // Stringa "username - #conto"
        string delimiter = " - ";
        string user = str.substr(0, str.find(delimiter));   // Ottengo solo lo username

        DataBase* d = new DataBase();
        if (d->load()) {
            d->giveBonus(*d->getUser(user));                // Assegno il bonus all'utente passato

            ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex()); // Rimuovo l'utente dalla combo box

            ui->toolButton_7->setEnabled(true);

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
}

void AdminInfo::on_toolButton_6_clicked() {     // Assegna il bonus (a "tutti")
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Proseguire?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        DataBase* d = new DataBase();
        if (d->load()) {
            d->giveBonusToAll();                // Assegna il bonus agli utenti che non lo hanno ancora ricevuto

            this->empty_ComboBox_2();           // Svuoto la combo box
            this->setComboBox_2();              // Inserisco gli utenti che non hanno già ricevuto il bonus

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
}

void AdminInfo::on_tableView_clicked (const QModelIndex &index) {   // Elimino la riga selezionata della tabella
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Eliminare il messaggio?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        int riga = index.row();
        QString qstr_u = ui->tableView->model()->data(ui->tableView->model()->index(riga, 0)).toString();
        QString qstr_m = ui->tableView->model()->data(ui->tableView->model()->index(riga, 1)).toString();

        string mit = qstr_u.toUtf8().constData();   // Username del mittente
        string mex = qstr_m.toUtf8().constData();   // Testo del messaggio

        MessagesDataBase* m = new MessagesDataBase();
        if (m->loadMessages()) {

            if (m->deleteOneMessage(*new Message("BankQ", mit, mex))) {
                DataBase* d = new DataBase();

                if (d->load()) {
                    this->setTable("BankQ", false);
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
                tr("Errore di caricamento del DB messaggi")
            );
        }
    }
}

void AdminInfo::on_toolButton_7_clicked() { // "Sblocca" tutti gli utenti, così da poter riassegnargli il bonus
    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("Attenzione"),
                trUtf8("Proseguire?"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Si"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("No"));

    if (msgBox.exec() == QMessageBox::Yes) {
        DataBase* d = new DataBase();
        if (d->load()) {
            d->unlockAll();                 // Setta a false la request degli utenti che hanno ricevuto il bonus

            this->empty_ComboBox_2();       // Svuoto la combo box
            this->setComboBox_2();          // Inserisco gli utenti che non hanno già ricevuto il bonus

            ui->toolButton_5->setEnabled(true);
            ui->toolButton_6->setEnabled(true);
            QMessageBox::information(
                this,
                tr("BankQ - Sblocco bonus"),
                tr("Utenti \"sbloccati\"")
            );
        } else {
            QMessageBox::warning(
                this,
                tr("BankQ - Errore"),
                tr("Errore di caricamento del DB")
            );
        }
    }
}

void AdminInfo::on_comboBox_5_currentIndexChanged (int index) {

    QString qstr = ui->comboBox_5->itemText(ui->comboBox_5->currentIndex());     // Elemento selezionato
    string str = qstr.toUtf8().constData();             // Stringa "username - #conto"

    string delimiter = " - ";
    string user = str.substr(0, str.find(delimiter));   // Ottengo solo lo username

    DataBase* d = new DataBase();
    if (d->load()) {

        User* u = d->getUser(user);
        if (dynamic_cast<BasicUser*> (u)) {   // "u" sicuramente sarà un utente e non un amministratore

            BasicUser* b = dynamic_cast<BasicUser*> (u);

            ui->lineEdit_28->setText(QString::fromStdString(b->getName()));     // Nome
            ui->lineEdit_29->setText(QString::fromStdString(b->getSurname()));  // Cognome
            ui->lineEdit_30->setText(QString::fromStdString(b->getAddress()));  // Indirizzo
            ui->lineEdit_31->setText(QString::fromStdString(b->getTelephone()));// Telefono
            ui->lineEdit_32->setText(QString::fromStdString(b->getCode()));     // Codice fiscale
            ui->lineEdit_33->setText(QString::fromStdString(b->getUsername())); // Username
            ui->lineEdit_34->setText(QString::fromStdString(b->getPin()));      // PIN
            ui->lineEdit_35->setText(QString::number(b->getCount()));           // Saldo
            ui->lineEdit_36->setText(QString::number(b->getCountNumber()));     // Numero di conto
        }
    } else {
        QMessageBox::warning(
            this,
            tr("BankQ - Errore"),
            tr("Errore di caricamento del DB")
        );
    }
}

void AdminInfo::on_toolButton_8_clicked() {     // Modifica un utente
    QString qstr = ui->comboBox_5->itemText(ui->comboBox_5->currentIndex());     // Elemento selezionato

    string str = qstr.toUtf8().constData();             // Stringa "username - #conto"
    string delimiter = " - ";
    string user = str.substr(0, str.find(delimiter));   // Ottengo solo lo username

    DataBase* d = new DataBase();
    if (d->load()) {
        string nom = (ui->lineEdit_28->text()).toUtf8().constData();   // Nome
        string cog = (ui->lineEdit_29->text()).toUtf8().constData();   // Cognome
        string ind = (ui->lineEdit_30->text()).toUtf8().constData();   // Indirizzo
        string tel = (ui->lineEdit_31->text()).toUtf8().constData();   // Telefono
        string cod = (ui->lineEdit_32->text()).toUtf8().constData();   // Codice fiscale
        string usr = (ui->lineEdit_33->text()).toUtf8().constData();   // Username
        string pin = (ui->lineEdit_34->text()).toUtf8().constData();   // PIN
        string sal = (ui->lineEdit_35->text()).toUtf8().constData();   // Saldo
        string num = (ui->lineEdit_36->text()).toUtf8().constData();   // Numero conto

        if (atoi(pin.c_str()) && atoi(tel.c_str()) && atoi(num.c_str())) {    // Verifico che il PIN, telefono, saldo e #conto siano numerici
            int int_sal = atoi(sal.c_str());
            int int_num = atoi(num.c_str());
            if (5 == pin.length()) {    // Verifico che il PIN abbia 5 cifre
                if (nom != "" && cog != "" && ind != "" && cod != "" && usr != "") {

                    User* u = d->getUser(user);  // Per verificare se ha già richiesto il bonus, il numero di conto
                    BasicUser* b_old = dynamic_cast<BasicUser*> (u);

                    if (!d->verifyExistingUsernameException(user, usr) && !d->verifyExistingCountNumberException(b_old->getCountNumber(), int_num)) {  // Controllo che username e #conto siano univoci

                        bool flag = false;
                        if (int_sal < 100000) {
                            BasicUser* b = new BasicUser(nom, cog, ind, tel, cod, usr, pin, int_num, int_sal);
                            flag = d->replace(*u, *b);

                        } else {

                            ProUser* old = dynamic_cast<ProUser*> (u);
                            ProUser* p = new ProUser(nom, cog, ind, tel, cod, usr, pin, int_num, int_sal, old->getRequest());
                            flag = d->replace(*u, *p);
                        }

                        if (flag) {   // Sostituisco il vecchio utente con quello nuovo
                            QMessageBox::warning(
                                this,
                                tr("BankQ - Modifica"),
                                tr("Utente modificato correttamente")
                            );
                            this->empty_ComboBox();         // Svuoto la combo box
                            this->setComboBox();            // Aggiorno la combo box (per rimuovere) con l'utente modificato

                            this->empty_ComboBox_2();       // Svuoto la combo box
                            this->setComboBox_2();          // Aggiorno la combo box (per assegnare il bonus) con l'utente modificato

                            this->empty_ComboBox_5();       // Svuoto la combo box
                            this->setComboBox_5();          // Aggiorno la combo box (per modificare) con l'utente modificato

                            ui->lineEdit_28->setText("");   // Nome
                            ui->lineEdit_29->setText("");   // Cognome
                            ui->lineEdit_30->setText("");   // Indirizzo
                            ui->lineEdit_31->setText("");   // Telefono
                            ui->lineEdit_32->setText("");   // Codice fiscale
                            ui->lineEdit_33->setText("");   // Username
                            ui->lineEdit_34->setText("");   // PIN
                            ui->lineEdit_35->setText("");   // Saldo
                            ui->lineEdit_36->setText("");   // Numero di conto
                        } else {
                            QMessageBox::warning(
                                this,
                                tr("BankQ - Errore"),
                                tr("Errore di caricamento del DB")
                            );
                        }
                    } else {
                        if (d->verifyExistingUsername(usr)) {
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
                    tr("Il PIN deve avere 5 cifre")
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
}

void AdminInfo::on_pushButton_clicked() {   // Info dell'inserimento
    QMessageBox::information(
        this,
        tr("BankQ - Info"),
        tr("PIN, telefono, saldo e numero di conto devono essere numerici.\nUsername e numero di conto devono essere univoci in tutto il sistema.\nIl PIN deve avere esattamente 5 cifre.")
    );
}

void AdminInfo::on_pushButton_2_clicked() { // Info della modifica
    this->on_pushButton_clicked();
}
