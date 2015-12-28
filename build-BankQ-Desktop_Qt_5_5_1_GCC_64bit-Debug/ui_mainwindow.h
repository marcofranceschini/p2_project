/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(574, 362);
        actionPreleva = new QAction(MainWindow);
        actionPreleva->setObjectName(QStringLiteral("actionPreleva"));
        actionCarica = new QAction(MainWindow);
        actionCarica->setObjectName(QStringLiteral("actionCarica"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionInfo->setChecked(false);
        actionPromuovi = new QAction(MainWindow);
        actionPromuovi->setObjectName(QStringLiteral("actionPromuovi"));
        actionChiudi = new QAction(MainWindow);
        actionChiudi->setObjectName(QStringLiteral("actionChiudi"));
        actionRichieste = new QAction(MainWindow);
        actionRichieste->setObjectName(QStringLiteral("actionRichieste"));
        actionRiconoscimenti = new QAction(MainWindow);
        actionRiconoscimenti->setObjectName(QStringLiteral("actionRiconoscimenti"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionLogout_2 = new QAction(MainWindow);
        actionLogout_2->setObjectName(QStringLiteral("actionLogout_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 70, 71, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 130, 31, 17));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(240, 200, 81, 25));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(230, 70, 113, 27));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(230, 130, 113, 27));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, -10, 111, 51));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionPreleva->setText(QApplication::translate("MainWindow", "Preleva", 0));
        actionCarica->setText(QApplication::translate("MainWindow", "Carica", 0));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0));
        actionPromuovi->setText(QApplication::translate("MainWindow", "Promuovi", 0));
        actionChiudi->setText(QApplication::translate("MainWindow", "Chiudi conto", 0));
        actionRichieste->setText(QApplication::translate("MainWindow", "Richieste", 0));
        actionRiconoscimenti->setText(QApplication::translate("MainWindow", "Riconoscimenti", 0));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0));
        actionLogout_2->setText(QApplication::translate("MainWindow", "Logout", 0));
        label->setText(QApplication::translate("MainWindow", "Username", 0));
        label_2->setText(QApplication::translate("MainWindow", "PIN", 0));
        toolButton->setText(QApplication::translate("MainWindow", "Accedi", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600;\">BankQ</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
