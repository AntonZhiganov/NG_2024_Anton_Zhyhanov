#include <QCoreApplication>
#include <QString>
#include <iostream>
#include <vector>

class Car {
public:
    Car(const QString &companyName, double price, const QString &type )
        : m_companyName(companyName), m_price(price), m_type(type) {}

    QString getCompanyName() const {
        return m_companyName;
    }

    void setCompanyName(const QString &companyName) {
        m_companyName = companyName;
    }

    virtual void printInfo () const{
        std::cout << "Company Name: " << m_companyName.toStdString() << std::endl;
        std::cout << "Price: $" << m_price << std::endl;
        std::cout << "Type: " << m_type.toStdString() << std::endl;
    }

    double getPrice() const {
        return m_price;
    }

    QString getType() const {
        return m_type;
    }

private:
    QString m_companyName;

protected:
    double m_price;
    QString m_type;
};

class CarsInSchop : public Car {
public:
    CarsInSchop(const QString &companyName, double price, const QString &type, int numberOfSeats, const QString &modelRange, const QString &color)
        : Car(companyName, price, type), m_numberOfSeats(numberOfSeats), m_modelRange(modelRange), m_color(color) {}

    int getNumberOfSeats() const {
         return m_numberOfSeats;
    }

    void setNumberOfSeats(int numberOfSeats){
        m_numberOfSeats = numberOfSeats;
    }

    QString getModelRange() const {
        return m_modelRange;
    }

    void setModelRange(const QString &modelRange){
        m_modelRange = modelRange;
    }

    QString getColor() const {
        return m_color;
    }

    void setColor(const QString &color) {
        m_color = color;
    }

    void printInfo() const override {
        Car::printInfo();
        std::cout << "Car have seats: " << m_numberOfSeats << std::endl;
        std::cout << "Is a model: " << m_modelRange.toStdString() << std::endl;
        std::cout << "Car have color: " << m_color.toStdString() << std::endl;
        std::cout << " " << std::endl;
    }

private:
    int m_numberOfSeats;
    QString m_modelRange;
    QString m_color;

};

void filter (const std::vector<CarsInSchop> &cars, const QString &type, const QString &companyName, double maxPrice){
    for (const auto &car : cars){
        if ((type.isEmpty() || car.getType() == type) && (companyName.isEmpty() || car.getCompanyName() == companyName) && car.getPrice() <= maxPrice) {
            car.printInfo();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<CarsInSchop> cars = {
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

    std::cout << "Cars available in the shop:" << std::endl;
    std::cout << " " << std::endl;
    for (const auto &car : cars) {
        car.printInfo();
    }

    std::string typeInput, companyInput;
    double maxPrice;

    std::cout <<"Enter car type (or leave empty to skip): ";
    std::getline(std::cin, typeInput);
    std::cout << " " << std::endl;


    std::cout << "Enter car company (or leave empty to skip): ";
    std::getline(std::cin, companyInput);
    std::cout << " " << std::endl;

    std::cout << "Enter maximum price: ";
    std::cin >> maxPrice;
    std::cout << " " << std::endl;

    QString type = QString::fromStdString(typeInput);
    QString companyName = QString::fromStdString(companyInput);

    filter(cars, type, companyName, maxPrice);

    return 0;
}
