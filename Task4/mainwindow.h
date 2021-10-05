#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QMessageBox>
#include "rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Rectangle rect[4];
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void AddItem();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void allUpdate();

    void on_comboBox_activated();

    void on_okBtn_clicked();

    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_rightBtn_clicked();

    void on_leftBtn_clicked();

    void on_upBtn_clicked();

    void on_downBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
