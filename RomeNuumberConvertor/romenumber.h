#ifndef ROMENUMBER_H
#define ROMENUMBER_H

#include <cstring>
#include <iostream>
#include <string>

#include "romestringmap.h"

using namespace std;

class RomeNumber
{
     RomeStringMap m_romeCharMap;

     string m_romeString;
     int m_arabNumber;

public:

    RomeNumber();
    RomeNumber(const char *);
    RomeNumber(const int &);
    RomeNumber(const RomeNumber&);
    ~RomeNumber();

    const string& GetRomeString();
    const int& GetArabNumber() const;
    const int& ConvertFrRomeToArab();
    const string &ConvertFrArabToRome();
    void Swap(RomeNumber&);
    int operator + (const int&);
    RomeNumber operator + (const RomeNumber&);
    int operator - (const int&);
    RomeNumber operator - (const RomeNumber&);
    int operator * (const int&);
    RomeNumber operator * (const RomeNumber&);
    int operator /(const int&);
    RomeNumber operator / (const RomeNumber&);
//TODO исправить перегрузки , добавить статический метод , подправить всё и перепроверить
    const RomeNumber& operator = (const RomeNumber&);
    const int& operator += (const int&);
    const RomeNumber& operator += (const RomeNumber&);
    const int& operator -= (const int&);
    const RomeNumber& operator -= (const RomeNumber&);
    const int& operator *= (const int&);
    const RomeNumber& operator *= (const RomeNumber&);
    const int& operator /= (const int&);
    const RomeNumber& operator /= (const RomeNumber&);

    const bool operator == (const int& rhs)const;
    const bool operator != (const int& rhs)const;
    const bool operator < (const int& rhs)const;
    const bool operator <= (const int& rhs)const;
    const bool operator > (const int& rhs)const;
    const bool operator >= (const int& rhs)const;

    const bool operator == (const RomeNumber& rhs)const;
    const bool operator != (const RomeNumber& rhs)const;
    const bool operator < (const RomeNumber& rhs)const;
    const bool operator <= (const RomeNumber& rhs)const;
    const bool operator > (const RomeNumber& rhs)const;
    const bool operator >= (const RomeNumber& rhs)const;

    RomeNumber RomeNumber::operator ++(const int);
    const RomeNumber& RomeNumber::operator ++();

    RomeNumber RomeNumber::operator --(const int);
    RomeNumber RomeNumber::operator --();

    friend ostream& operator << (ostream& os, RomeNumber&);
    friend istream& operator >> (istream& is, RomeNumber&);
    explicit operator int()const;

//+    - арифметические операции и производные от них (для операндов типа int и RomanNumber): +, -, *, /, +=, -=, *=, /=
//+    - операции сравнения (для операндов типа int и RomanNumber): ==, !=, <, <=, >, >=
//+    - инкремент, декремент (postfix&infix): ++, --
//+    - операции ввод/вывода в поток
//+    - операции приведения к int (explicit)

};

#endif // ROMENUMBER_H
