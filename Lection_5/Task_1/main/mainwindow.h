#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "CarsInSchop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_filterButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<CarsInSchop> cars;

    void populateCars();
    void displayCars(const std::vector<CarsInSchop> &filteredCars);
};

#endif // MAINWINDOW_H
