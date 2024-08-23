#include "recording.h"

Recording::Recording(const QString &type, const QString &name, const QString &author, const QString &address, const QString &dateOfCreation)
    : type(type), name(name), author(author), address(address), dateOfCreation(dateOfCreation)
{
}

QString Recording::getType() const { return type; }
QString Recording::getName() const { return name; }
QString Recording::getAuthor() const { return author; }
QString Recording::getAddress() const { return address; }
QString Recording::getDateOfCreation() const { return dateOfCreation; }
