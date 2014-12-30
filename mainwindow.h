#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void readyReadOutput();
    void readyReadError();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *q;
};

#endif // MAINWINDOW_H
