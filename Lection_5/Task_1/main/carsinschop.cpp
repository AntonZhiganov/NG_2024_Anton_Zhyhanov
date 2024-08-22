#include "CarsInSchop.h"
#include <iostream>

CarsInSchop::CarsInSchop(const QString &companyName, double price, const QString &type, int numberOfSeats, const QString &modelRange, const QString &color)
    : Car(companyName, price, type), m_numberOfSeats(numberOfSeats), m_modelRange(modelRange), m_color(color) {}

int CarsInSchop::getNumberOfSeats() const {
    return m_numberOfSeats;
}

void CarsInSchop::setNumberOfSeats(int numberOfSeats) {
    m_numberOfSeats = numberOfSeats;
}

QString CarsInSchop::getModelRange() const {
    return m_modelRange;
}

void CarsInSchop::setModelRange(const QString &modelRange) {
    m_modelRange = modelRange;
}

QString CarsInSchop::getColor() const {
    return m_color;
}

void CarsInSchop::setColor(const QString &color) {
    m_color = color;
}

void CarsInSchop::printInfo() const {
    Car::printInfo();
    std::cout << "Car have seats: " << m_numberOfSeats << std::endl;
    std::cout << "Is a model: " << m_modelRange.toStdString() << std::endl;
    std::cout << "Car have color: " << m_color.toStdString() << std::endl;
    std::cout << " " << std::endl;
}
