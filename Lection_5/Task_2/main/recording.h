#ifndef RECORDING_H
#define RECORDING_H

#include <QString>

class Recording
{
public:
    Recording(const QString &type, const QString &name, const QString &author, const QString &address, const QString &dateOfCreation);

    QString getType() const;
    QString getName() const;
    QString getAuthor() const;
    QString getAddress() const;
    QString getDateOfCreation() const;

private:
    QString type;
    QString name;
    QString author;
    QString address;
    QString dateOfCreation;
};

#endif
