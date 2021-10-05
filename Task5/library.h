#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include <QList>
#include <QTableWidget>
#include <QMessageBox>
#include <QValidator>
#include "book.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

const int columnCount = 5;

class Library : public QMainWindow
{
    Q_OBJECT

private:
    QList<Book> books;
public:
    Library(QWidget *parent = nullptr);
    ~Library();
    void TableStyle();
    bool isIndentical();
    Book CreateElement();
    void UpdateTable();
    int NumberOfBooks();
    void ClearLE();
    bool isEmptyLE();

private slots:
    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_getBtn_clicked();

    void on_searchBtn_clicked();

    void on_setBtn_clicked();

private:
    Ui::Library *ui;
};
#endif // LIBRARY_H
