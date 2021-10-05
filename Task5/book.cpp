#include "book.h"

Book::Book()
{
    udkNumber = 0;
    author = "";
    name = "";
    year = 0;
    number = 0;
}
Book::~Book(){}

void Book::Initialization(int udkNumber, QString author, QString name, int year, int number)
{
    this->udkNumber = udkNumber;
    this->author = author;
    this->name = name;
    this->year = year;
    this->number = number;
}

int Book::GetUdk() { return udkNumber; };
int Book::GetNumber() { return number; };
int Book::GetYear() { return year; };
QString Book::GetName() { return name; };
QString Book::GetAuthor() { return author; };

QList<QString> Book::GetData()
{
    QList<QString> data;

    data.append(name);
    data.append(author);
    data.append(QString::number(year));
    data.append(QString::number(number));
    data.append(QString::number(udkNumber));

    return data;
}

void Book::GetBook()
{
    number -=1;
}

void Book::SetBook()
{
    number += 1;
}




