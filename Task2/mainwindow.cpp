#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(1, 7, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int number = ui->lineEdit->text().toInt();

        switch (number) {
        case 1:
        {
            ui->label_3->setText("Понеділок");
            break;
        }
        case 2:
        {
            ui->label_3->setText("Вівторок");
            break;
        }
        case 3:
        {
            ui->label_3->setText("Середа");
            break;
        }
        case 4:
        {
            ui->label_3->setText("Четвер");
            break;
        }
        case 5:
        {
            ui->label_3->setText("П'ятниця");
            break;
        }
        case 6:
        {
            ui->label_3->setText("Субота");
            break;
        }
        case 7:
        {
            ui->label_3->setText("Неділя");
            break;
        }
        default: ui->label_3->setText("Немає такого дня тижня");
        }

}
