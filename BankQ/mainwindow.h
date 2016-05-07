#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMessageBox>
using namespace std;
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void boom() {
        QMessageBox::warning(
            this,
            tr("BOOM"),
            tr("BOOM")
        );
    }

private slots:
    void on_centralWidget_windowTitleChanged(const QString &title);

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
