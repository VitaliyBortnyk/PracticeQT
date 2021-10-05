#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(ui->spinBox->value());
    ui->tableWidget->setColumnCount(ui->spinBox_2->value());
    CreateEmptyItems(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateEmptyItems(int I, int J)
{
    for(int i = I; i < ui->tableWidget->rowCount(); i++)
        for(int j = J; j < ui->tableWidget->columnCount(); j++)
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(""));
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(ui->spinBox->value());

    CreateEmptyItems(cell.RowCount, 0);
        cell.RowCount = ui->spinBox->value();


}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->tableWidget->setColumnCount(ui->spinBox_2->value());

    CreateEmptyItems(0, cell.ColumnCount);
        cell.ColumnCount = ui->spinBox_2->value();
}

//Random
void MainWindow::on_pushButton_2_clicked()
{
    int rows, columns;

    rows = ui->tableWidget->rowCount();
    columns = ui->tableWidget->columnCount();

    int Arr[rows][columns];

    for (int i = 0; i < rows ; i++)
        for(int j = 0; j < columns; j++)
        {
                Arr[i][j] = rand() % 9 + 1;
                ui->tableWidget->setItem(i, j,
                                         new QTableWidgetItem(QString::number(Arr[i][j])));
        }
}

//Sidlo
void MainWindow::on_pushButton_3_clicked()
{
    int rows, columns;

    rows = ui->tableWidget->rowCount();
    columns = ui->tableWidget->columnCount();

    int Arr[rows][columns];
    int minInRow[rows];
    int maxInRow[rows];
    int minInColumn[columns];
    int maxInColumn[columns];

    bool empty = false;

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            if(ui->tableWidget->item(i, j)->text().isEmpty())
                empty = true;

    if(!empty)
    {
    //Init Array
    for (int i = 0; i < rows ; i++)
        for(int j = 0; j < columns; j++)
        {
                Arr[i][j] = ui->tableWidget->item(i, j)->text().toInt();
                ui->tableWidget->item(i, j)->setBackground(QColor::fromRgb(255, 255, 255));
        }

    //Writting

    QFile file("D:\\PracticeQT\\Task3\\out.txt");
    QTextStream out(&file);

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        for (int i = 0; i < rows ; i++)
        {
            for(int j = 0; j < columns; j++)
                out << Arr[i][j]<<"    ";
            out<<endl;
        }
    }

    //Alorithm

    bool MinMax = false;
    bool MaxMin = false;
    out<<"Sidlovi tochky: ";

    for (int i = 0; i < rows; i++)
        {
            minInRow[i] = INT_MAX;
            for (int j = 0; j < columns; j++)
            {
                if (Arr[i][j] < minInRow[i])
                {
                    minInRow[i] = Arr[i][j];
                }
            }
        }
        for (int j = 0; j < columns; j++)
        {
            maxInColumn[j] = INT_MIN;
            for (int i = 0; i < rows; i++)
            {
                if (Arr[i][j] > maxInColumn[j])
                {
                    maxInColumn[j] = Arr[i][j];
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (minInRow[i] == maxInColumn[j])
                {
                    out<<Arr[i][j]<<"["<<i+1<<"]"<<"["<<j+1<<"]"<<"  ";
                    ui->tableWidget->item(i, j)->setBackground(QColor::fromRgb(52, 235, 229));
                    MinMax = true;
                }
            }
        }

        if(!MinMax)
        {
            for (int i = 0; i < columns; i++)
                {
                    minInColumn[i] = INT_MAX;
                    for (int j = 0; j < rows; j++)
                    {
                        if (Arr[i][j] < minInColumn[i])
                        {
                            minInColumn[i] = Arr[i][j];
                        }
                    }
                }
                for (int j = 0; j < rows; j++)
                {
                    maxInRow[j] = INT_MIN;
                    for (int i = 0; i < columns; i++)
                    {
                        if (Arr[i][j] > maxInRow[j])
                        {
                            maxInRow[j] = Arr[i][j];
                        }
                    }
                }

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        if (minInRow[i] == maxInColumn[j])
                        {
                            out<<Arr[i][j]<<"["<<i+1<<"]"<<"["<<j+1<<"]"<<"  ";
                            ui->tableWidget->item(i, j)->setBackground(QColor::fromRgb(52, 235, 229));
                            MaxMin = true;
                        }
                    }
                }
        }
        if(!MinMax && !MaxMin)
        {
            QMessageBox::information(this, "Info    ", "Сідлових точок немає");
            out<<"nemae";
        }

        out<<"\n\n";
        file.close();
    }
    else
        QMessageBox::information(this, "Info    ", "Заповніть всі клітинки!");
}

//Clear
void MainWindow::on_pushButton_clicked()
{
   ui->tableWidget->clear();
   CreateEmptyItems(0, 0);
}

//Exit
void MainWindow::on_pushButton_4_clicked()
{
    close();
}
