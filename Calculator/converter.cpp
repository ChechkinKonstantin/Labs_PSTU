#include "converter.h"
#include <cmath>
#include <string>
#include <QString>

Converter::Converter()
{
    this->data = "";
    this->OriginNumberSystem = 16;
    this->DerivNumberSystem = 16;
}

void Converter::operator+=(QString key)
{
    this->data += key;
}

void Converter::convertFromDecimalToBase(int base)
{

    int digit = this->data.toInt();
    QString result = "";
    while (digit != 0)
    {
        if (digit % base < 10)
            result += QString::number(digit % base);
        else
        {
            switch(digit % base)
            {
                case 10:
                    result += "A";
                    break;
                case 11:
                    result += "B";
                    break;
                case 12:
                    result += "C";
                case 13:
                    result += "D";
                case 14:
                    result += "E";
                case 15:
                    result += "F";
            }
        }
        digit /= base;
    }
    std::reverse(result.begin(), result.end());
    this->data = result;
}

void Converter::convertToDecimalFromBase(int base)
{
    int result = 0;
    int k = 0;
    std::string alpha = "ABCDEF";
    for(int i = this->data.size() - 1; i >= 0; i--)
    {
        int symb;
        if (QString(this->data[i]) == "A"){
            symb = 10;
        }
        else if (QString(this->data[i]) == "B"){
            symb = 11;
        }
        else if (QString(this->data[i]) == "C"){
            symb = 12;
        }
        else if (QString(this->data[i]) == "D"){
            symb = 13;
        }
        else if (QString(this->data[i]) == "E"){
            symb = 14;
        }
        else if (QString(this->data[i]) == "F"){
            symb = 15;
        }
        else{
            symb = QString(this->data[i]).toInt();
        }
        result += symb * pow(base, k);
        k++;
    }
    this->data = QString::number(result);
}

void Converter::operator()()
{
    if (this->OriginNumberSystem == 10)
    {
        this->convertFromDecimalToBase(this->DerivNumberSystem);
    }
    else if(this->DerivNumberSystem == 10)
    {
        this->convertToDecimalFromBase(this->OriginNumberSystem);
    }
    else
    {
        this->convertToDecimalFromBase(this->OriginNumberSystem);
        this->convertFromDecimalToBase(this->DerivNumberSystem);
    }
}


QString Converter::getData()
{
    return this->data;
}

void Converter::setDerivNumberSystem(int number)
{
    this->DerivNumberSystem = number;
}

void Converter::setOriginNumberSystem(int number)
{
    this->OriginNumberSystem = number;
}

int Converter::getOriginNumberSystem()
{
    return this->OriginNumberSystem;
}

int Converter::getDerivNumberSystem()
{
    return this->DerivNumberSystem;
}

void Converter::clear()
{
    this->data = "";
}
