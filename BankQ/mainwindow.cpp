#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_centralWidget_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_toolButton_clicked() {
    QString usr = ui->lineEdit->text();
    QString pass = ui->lineEdit->text();
    if(usr.compare("admin") && pass.compare("admin")) {

    }else{

    }
}
