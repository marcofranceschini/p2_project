/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *tab_2;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit;
    QToolButton *toolButton_3;
    QWidget *tab_3;
    QLabel *label_15;
    QWidget *tab_4;
    QLabel *label_16;

    void setupUi(QDialog *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->resize(574, 362);
        tabWidget = new QTabWidget(UserInfo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 581, 371));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 67, 17));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 80, 71, 17));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 240, 67, 17));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 40, 111, 17));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 80, 101, 17));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 120, 111, 17));
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(200, 280, 61, 25));
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(310, 280, 111, 25));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 120, 91, 17));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 160, 91, 17));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 200, 91, 17));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(180, 160, 131, 17));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 200, 131, 17));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(180, 240, 141, 17));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 10, 67, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 10, 67, 21));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 70, 101, 17));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 110, 131, 17));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(210, 70, 141, 17));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 100, 141, 27));
        toolButton_3 = new QToolButton(tab_2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(190, 180, 71, 25));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 10, 67, 21));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 10, 67, 21));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(UserInfo);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QDialog *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "Dialog", 0));
        label->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Nome</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Cognome</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Saldo</span></p></body></html>", 0));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        toolButton->setText(QApplication::translate("UserInfo", "Esci", 0));
        toolButton_2->setText(QApplication::translate("UserInfo", "Chiudi conto", 0));
        label_7->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Tipo utente</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Tasse/anno</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Bonus/anno</span></p></body></html>", 0));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">BankQ</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserInfo", "Info", 0));
        label_14->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">BankQ</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Saldo attuale</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-weight:600;\">Cifra da prelevare</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("UserInfo", "TextLabel", 0));
        toolButton_3->setText(QApplication::translate("UserInfo", "Preleva", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserInfo", "Preleva", 0));
        label_15->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">BankQ</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UserInfo", "Carica", 0));
        label_16->setText(QApplication::translate("UserInfo", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">BankQ</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("UserInfo", "Upgrade", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
