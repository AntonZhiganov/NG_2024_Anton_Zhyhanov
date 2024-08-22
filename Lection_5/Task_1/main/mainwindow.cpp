#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populateCars();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateCars() {
    cars = {
        CarsInSchop("Audi", 120000, "Coupe", 4, "A5 Sportback", "Black"),
        CarsInSchop("Audi", 90000, "Coupe", 4, "A6 allroad quattro", "Yellow"),
        CarsInSchop("BMW", 80000, "SUV", 4, "BMWx7", "Green"),
        CarsInSchop("BMW", 80000, "SUV", 4, "BMWx7", "Black"),
        CarsInSchop("BMW", 80000, "SUV", 4, "BMWx7", "Grey"),
        CarsInSchop("BMW", 100000, "Sport", 4, "BMWm5Competition", "Grey"),
        CarsInSchop("BMW", 100000, "Sport", 4, "BMWm5Competition", "Black"),
        CarsInSchop("Mazda", 70000, "SUV", 4, "MAZDA CX-50", "Black"),
        CarsInSchop("Mazda", 70000, "SUV", 4, "MAZDA CX-50", "Green"),
        CarsInSchop("Subaru", 130000, "SUV", 4, "Solterra", "White")
    };

    displayCars(cars);
}

void MainWindow::displayCars(const std::vector<CarsInSchop> &filteredCars) {
    ui->listWidget->clear();
    for (const auto &car : filteredCars) {
        QString carDetails = car.getCompanyName() + " " +
                             car.getModelRange() + " " +
                             car.getColor() + " " +
                             QString::number(car.getPrice());

        ui->listWidget->addItem(carDetails);
    }
}

void MainWindow::on_filterButton_clicked() {
    QString type = ui->typeLineEdit->text();
    QString companyName = ui->companyLineEdit->text();
    double maxPrice = ui->priceSpinBox->value();

    std::vector<CarsInSchop> filteredCars;
    for (const auto &car : cars) {
        if ((type.isEmpty() || car.getType() == type) &&
            (companyName.isEmpty() || car.getCompanyName() == companyName) &&
            car.getPrice() <= maxPrice) {
            filteredCars.push_back(car);
        }
    }

    displayCars(filteredCars);
}
