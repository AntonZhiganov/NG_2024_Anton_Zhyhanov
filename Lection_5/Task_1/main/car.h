#ifndef CAR_H
#define CAR_H

#include <QString>

class Car {
public:
    Car(const QString &companyName, double price, const QString &type);

    QString getCompanyName() const;
    void setCompanyName(const QString &companyName);

    virtual void printInfo() const;

    double getPrice() const;
    QString getType() const;

private:
    QString m_companyName;

protected:
    double m_price;
    QString m_type;
};

#endif // CAR_H
