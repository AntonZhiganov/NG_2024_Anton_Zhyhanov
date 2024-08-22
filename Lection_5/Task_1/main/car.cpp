#include "Car.h"
#include <iostream>

Car::Car(const QString &companyName, double price, const QString &type)
    : m_companyName(companyName), m_price(price), m_type(type) {}

QString Car::getCompanyName() const {
    return m_companyName;
}

void Car::setCompanyName(const QString &companyName) {
    m_companyName = companyName;
}

void Car::printInfo() const {
    std::cout << "Company Name: " << m_companyName.toStdString() << std::endl;
    std::cout << "Price: $" << m_price << std::endl;
    std::cout << "Type: " << m_type.toStdString() << std::endl;
}

double Car::getPrice() const {
    return m_price;
}

QString Car::getType() const {
    return m_type;
}
