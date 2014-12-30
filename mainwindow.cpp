#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include <QProcess>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    q = new QProcess;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString dlLink = ui->lineEdit->text();
    QString path   = ui->lineEdit_2->text();
    QString command = "aria2c -d "+ path + " " +dlLink ;
//    QString command = "wget -O "+ path +"/a.rar "+ " " +dlLink +" | grep %";
    Console::log(command);

    q->setProcessChannelMode(QProcess::MergedChannels);
    q->start(command);
    connect(q,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadOutput()));
    connect(q,SIGNAL(readyReadStandardError()),this,SLOT(readyReadError()));

}


void MainWindow::readyReadOutput(){
        ui->textEdit->append(q->readAllStandardOutput());
}

void MainWindow::readyReadError(){
    ui->textEdit->append(q->readAllStandardError());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getExistingDirectory();
    ui->lineEdit_2->setText(path);
}
