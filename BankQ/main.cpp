#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


/* Progetto realizzato da Marco Franceschini come
 * progetto d'esame per il corso di Programmazione ad Ogetti
 * dell' anno accademico 2015/2016
*/
