#ifndef CARSINSCHOP_H
#define CARSINSCHOP_H

#include "Car.h"

class CarsInSchop : public Car {
public:
    CarsInSchop(const QString &companyName, double price, const QString &type, int numberOfSeats, const QString &modelRange, const QString &color);

    int getNumberOfSeats() const;
    void setNumberOfSeats(int numberOfSeats);

    QString getModelRange() const;
    void setModelRange(const QString &modelRange);

    QString getColor() const;
    void setColor(const QString &color);

    void printInfo() const override;

private:
    int m_numberOfSeats;
    QString m_modelRange;
    QString m_color;
};

#endif // CARSINSCHOP_H
