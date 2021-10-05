#include "library.h"
#include "ui_library.h"
#include "book.h"

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    TableStyle();
    ui->yearLE->setValidator(new QIntValidator(this));
    ui->countLE->setValidator(new QIntValidator(this));
    ui->udkLE->setValidator(new QIntValidator(this));
    ui->udkNumLE->setValidator(new QIntValidator(this));
    ui->udkSearchLE->setValidator(new QIntValidator(this));
    ui->allLb->setText(QString::number(NumberOfBooks()));
}

Library::~Library()
{
    delete ui;
}

void Library::TableStyle()
{
    QString headerName[columnCount] = {"Назва", "Прізвище та ініціали автора", "Рік видачі", "Кількість екземплярів", "Номер УДК"};
    int headerItemWidth[5] = {175, 220, 105, 170, 125};

    ui->tableWidget->setEditTriggers(0);
    ui->tableWidget->setColumnCount(columnCount);

    for(int i = 0; i < columnCount; i++)
    {
        ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(headerName[i]));
        ui->tableWidget->horizontalHeader()->resizeSection(i, headerItemWidth[i]);
    }
}

void Library::UpdateTable()
{
    ui->tableWidget->setRowCount(books.length());

    for(int i = 0; i < books.length(); i++)
     for(int j = 0; j < columnCount; j++)
     {
         Book book = books.at(i);
         ui->tableWidget->setItem(i, j,
                                  new QTableWidgetItem(book.GetData().at(j)));
     }
    ui->allLb->setText(QString::number(NumberOfBooks()));
}

void Library::ClearLE()
{
    ui->udkLE->setText("");
    ui->authorLE->setText("");
    ui->nameLE->setText("");
    ui->yearLE->setText("");
    ui->countLE->setText("");
}

bool Library::isEmptyLE()
{
    if(ui->udkLE->text().isEmpty()
            || ui->authorLE->text().isEmpty()
            || ui->nameLE->text().isEmpty()
            || ui->yearLE->text().isEmpty()
            || ui->countLE->text().isEmpty())
        return true;

    return  false;;
}

bool Library::isIndentical()
{
    for(int i = 0; i < books.length(); i++)
        if(ui->tableWidget->item(i, 4)->text().toInt() == ui->udkLE->text().toInt())
            return true;

    return  false;
}

Book Library::CreateElement()
{
    Book book;

    book.Initialization(
                ui->udkLE->text().toInt(),
                ui->authorLE->text(),
                ui->nameLE->text(),
                ui->yearLE->text().toInt(),
                ui->countLE->text().toInt());

    return book;
}

void Library::on_addBtn_clicked()
{
    if(!isEmptyLE())
    {
        if(!isIndentical())
        {
            books.append(CreateElement());

            ClearLE();
            UpdateTable();
        }
        else
            QMessageBox::information(this, "Інформація", "Запис з даним номером УДК вже існує");
    }
    else
        QMessageBox::information(this, "Підказка", "Заповніть всі поля вводу");
}

void Library::on_delBtn_clicked()
{
    if(!isEmptyLE())
    {
    for(int i = 0; i < books.length(); i++)
        if(ui->tableWidget->item(i, 4)->text().toInt() == ui->udkLE->text().toInt())
        {
            books.removeAt(i);
            ClearLE();
            UpdateTable();
        }
    }
    else
        QMessageBox::information(this, "Підказка", "Заповніть всі поля вводу");

}

int Library::NumberOfBooks()
{
    int numberOfBooks = 0;

    for(Book book : books)
        numberOfBooks += book.GetNumber();

    return numberOfBooks;
}

void Library::on_getBtn_clicked()
{
    if(ui->udkNumLE->text().isEmpty())
        QMessageBox::information(this, "Інформація", "Введіть номер УДК");
    else
    {
    bool identUDK = false;
    bool availability = false;

    for(Book &book : books)
    {
       if(book.GetUdk() == ui->udkNumLE->text().toInt())
       {
           identUDK = true;

           if(book.GetNumber() > 0)
           {
               book.GetBook();
               availability = true;
           }
       }
    }

    if(identUDK)
    {
        if(availability)
        {
            QMessageBox::information(this, "Інформація", "Книга успішно отримана");
            ui->udkNumLE->setText("");
        }
        else
            QMessageBox::information(this, "Інформація", "Всі екземпляри книги на руках");
    }
    else
        QMessageBox::information(this, "Інформація", "Даної книги немає у бібліотеці");


    ui->allLb->setText(QString::number(NumberOfBooks()));
    }
}

void Library::on_searchBtn_clicked()
{
    ui->nameLb->setText("");
    ui->authorLb->setText("");
    ui->yearLb->setText("");
    ui->numberLb->setText("");

    bool availability = false;

    if(ui->udkSearchLE->text().isEmpty())
        QMessageBox::information(this, "Інформація", "Введіть номер УДК");
    else
    {
    for(Book book : books)
    {
        if(book.GetUdk() == ui->udkSearchLE->text().toInt())
        {
            ui->nameLb->setText(book.GetName());
            ui->authorLb->setText(book.GetAuthor());
            ui->yearLb->setText(QString::number(book.GetYear()));
            ui->numberLb->setText((QString::number(book.GetNumber())));
            availability = true;
        }
    }
    if(!availability)
        QMessageBox::information(this, "Інформація", "Даної книги немає у бібліотеці");
    else
        QMessageBox::information(this, "Інформація", "Книгу знайдено");
    }
}

void Library::on_setBtn_clicked()
{
    if(ui->udkNumLE->text().isEmpty())
        QMessageBox::information(this, "Інформація", "Введіть номер УДК");
    else
    {
    bool identUDK = false;
    bool availability = false;
    int index = 0;

    for(Book &book : books)
    {
       if(book.GetUdk() == ui->udkNumLE->text().toInt())
       {
           identUDK = true;

           if(book.GetNumber() < ui->tableWidget->item(index, 3)->text().toInt())
           {
               book.SetBook();
               availability = true;
               index ++;
           }
       }
    }

    if(identUDK)
    {
        if(availability)
        {
            QMessageBox::information(this, "Інформація", "Книга успішно повернена");
            ui->udkNumLE->setText("");
        }
        else
            QMessageBox::information(this, "Інформація", "Всі екземпляри книги знаходяться у бібліотеці");
    }
    else
        QMessageBox::information(this, "Інформація", "Даної книги немає у бібліотеці");

    ui->allLb->setText(QString::number(NumberOfBooks()));
    }
}
