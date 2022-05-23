#ifndef CONVERTER_H
#define CONVERTER_H
#include <QString>


class Converter
{
private:
    QString data;
    int OriginNumberSystem;
    int DerivNumberSystem;
public:
    Converter();

public:
    QString getData();
    void setOriginNumberSystem(int number);
    void setDerivNumberSystem(int number);
    void clear();

    int getOriginNumberSystem();
    int getDerivNumberSystem();
public:
    void operator+=(QString);
    void operator()();

private:
    void convertToDecimalFromBase(int);
    void convertFromDecimalToBase(int);
};

#endif // CONVERTER_H
