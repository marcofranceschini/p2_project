/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPreleva;
    QAction *actionCarica;
    QAction *actionInfo;
    QAction *actionPromuovi;
    QAction *actionChiudi;
    QAction *actionRichieste;
    QAction *actionRiconoscimenti;
    QAction *actionLogout;
    QAction *actionLogout_2;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(574, 362);
        actionPreleva = new QAction(MainWindow);
        actionPreleva->setObjectName(QString::fromUtf8("actionPreleva"));
        actionCarica = new QAction(MainWindow);
        actionCarica->setObjectName(QString::fromUtf8("actionCarica"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionInfo->setChecked(false);
        actionPromuovi = new QAction(MainWindow);
        actionPromuovi->setObjectName(QString::fromUtf8("actionPromuovi"));
        actionChiudi = new QAction(MainWindow);
        actionChiudi->setObjectName(QString::fromUtf8("actionChiudi"));
        actionRichieste = new QAction(MainWindow);
        actionRichieste->setObjectName(QString::fromUtf8("actionRichieste"));
        actionRiconoscimenti = new QAction(MainWindow);
        actionRiconoscimenti->setObjectName(QString::fromUtf8("actionRiconoscimenti"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionLogout_2 = new QAction(MainWindow);
        actionLogout_2->setObjectName(QString::fromUtf8("actionLogout_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 160, 71, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 230, 31, 17));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(240, 300, 81, 25));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 160, 113, 27));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 230, 113, 27));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 121, 51));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 100, 341, 17));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BankQ - Login", 0, QApplication::UnicodeUTF8));
        actionPreleva->setText(QApplication::translate("MainWindow", "Preleva", 0, QApplication::UnicodeUTF8));
        actionCarica->setText(QApplication::translate("MainWindow", "Carica", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        actionPromuovi->setText(QApplication::translate("MainWindow", "Promuovi", 0, QApplication::UnicodeUTF8));
        actionChiudi->setText(QApplication::translate("MainWindow", "Chiudi conto", 0, QApplication::UnicodeUTF8));
        actionRichieste->setText(QApplication::translate("MainWindow", "Richieste", 0, QApplication::UnicodeUTF8));
        actionRiconoscimenti->setText(QApplication::translate("MainWindow", "Riconoscimenti", 0, QApplication::UnicodeUTF8));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        actionLogout_2->setText(QApplication::translate("MainWindow", "Logout", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "PIN", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "Accedi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">BankQ</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Benvenuto, accedi per avere accesso al tuo conto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
