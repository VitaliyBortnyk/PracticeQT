#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AddItem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItem()
{
    QPixmap px(15,15);
    px.fill(QColor(50, 107, 168));
    QIcon icon(px);
    ui->comboBox->addItem(icon,"Синій");

    px.fill(QColor(237, 19, 44));
    icon.addPixmap(px);
    ui->comboBox->addItem(icon,"Червоний");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QBrush Brushes[4] = {QBrush(QColor(50, 107, 168, 45)),
                         QBrush(QColor(237, 19, 44, 45)),
                         QBrush(Qt::BDiagPattern),
                         QBrush(Qt::FDiagPattern)};

    for(int i = 0; i < 4; i++)
    {
        painter.setBrush(Brushes[i]);
        painter.drawRect(rect[i].x, rect[i].y, rect[i].width, rect[i].height);
    }
}

void MainWindow::allUpdate()
{
    ui->xLb->setText(QString::number(rect[ui->comboBox->currentIndex()].x));
    ui->yLb->setText(QString::number(rect[ui->comboBox->currentIndex()].y));
    ui->widthLb->setText(QString::number(rect[ui->comboBox->currentIndex()].width));
    ui->heightLb->setText(QString::number(rect[ui->comboBox->currentIndex()].height));
    ui->squareLb->setText(QString::number(rect[ui->comboBox->currentIndex()].Square()));

    rect[2].SetData(0, 0, 0, 0);
    rect[3].SetData(0, 0, 0, 0);

    update();
}

void MainWindow::on_comboBox_activated()
{
    allUpdate();
}

void MainWindow::on_okBtn_clicked()
{
    if(ui->widthLE->text().isEmpty()
            || ui->heightLE->text().isEmpty()
            || ui->widthLE->text().toDouble() <= 0
            || ui->heightLE->text().toDouble() <= 0)
        QMessageBox::information(this, "Підказка", "Заповніть всі поля значеннями більше нуля."
                                       " Для виділення дробової частини використовуйте крапку");
    else
    {
        rect[ui->comboBox->currentIndex()].Resize(
                    ui->widthLE->text().toDouble(),
                    ui->heightLE->text().toDouble());

        ui->widthLE->setText(0);
        ui->heightLE->setText(0);
        allUpdate();
    }
}

void MainWindow::on_oneBtn_clicked()
{
    rect[3] = Rectangle::IntersectionRectangle(rect[0], rect[1]);
    update();
}

void MainWindow::on_twoBtn_clicked()
{
    rect[2] = Rectangle::MinRectangle(rect[0], rect[1]);
    update();
}

void MainWindow::on_rightBtn_clicked()
{
    rect[ui->comboBox->currentIndex()].Move('r', ui->distanceLb->text().toDouble());
    allUpdate();
}

void MainWindow::on_leftBtn_clicked()
{
    rect[ui->comboBox->currentIndex()].Move('l', ui->distanceLb->text().toDouble());
    allUpdate();
}

void MainWindow::on_upBtn_clicked()
{
    rect[ui->comboBox->currentIndex()].Move('u', ui->distanceLb->text().toDouble());
    allUpdate();
}

void MainWindow::on_downBtn_clicked()
{
    rect[ui->comboBox->currentIndex()].Move('d', ui->distanceLb->text().toDouble());
    allUpdate();
}
