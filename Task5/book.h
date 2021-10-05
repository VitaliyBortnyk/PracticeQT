#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QList>

class Book
{
private:
    int udkNumber;
    QString author;
    QString name;
    int year;
    int number;


public:
    Book();
    ~Book();
    void Initialization(int udkNumber, QString author, QString name, int year, int number);
    int GetUdk();
    int GetNumber();
    int GetYear();
    QString GetName();
    QString GetAuthor();
    void GetBook();
    void SetBook();
    QList<QString> GetData();
};

#endif // BOOK_H
