#include "romenumber.h"


RomeNumber::RomeNumber()
    : m_romeString("")
    , m_arabNumber(-1)
{
//--------------------------------------------------
}
RomeNumber::RomeNumber(const char* romeChar)
    : m_romeString(romeChar)
    , m_arabNumber(m_romeCharMap[romeChar[0]])
{
    ConvertFrRomeToArab();
}
//----------------------------------------------------------------
RomeNumber::RomeNumber(int arabNumber)
    : m_arabNumber(arabNumber)
    , m_romeString("")
{
    ConvertFrArabToRome();
}

string RomeNumber::GetRomeString() const
{
    return m_romeString;
}

int RomeNumber::GetArabNumber() const
{
    return m_arabNumber;
}
//----------------------------------------------------------------
const int& RomeNumber::ConvertFrRomeToArab()
{
    for(int i = 1; i < m_romeString.length(); i++)
    {
        if(m_romeCharMap[m_romeString[i]] <= m_romeCharMap[m_romeString[i-1]])
        {
            m_arabNumber += m_romeCharMap[m_romeString[i]];
        }
        else
        {
            m_arabNumber += m_romeCharMap[m_romeString[i]] - 2 * m_romeCharMap[m_romeString[i-1]];
        }
    }
    return m_arabNumber;
}
//----------------------------------------------------------------
const string& RomeNumber::ConvertFrArabToRome()
{
    if(m_arabNumber <= 0)
    {
        exit(1);
    }
    m_romeString = "";
    int arabNumber = m_arabNumber;
    if(arabNumber / 10 > 0)//if we have more then 2 numerals
    {
        int fraction = 10;
        while( arabNumber != 0)
        {
            int y = arabNumber % fraction;

            //cout << y << endl;
            for(size_t i = 0; i < m_romeCharMap.GetSize() - 1; ++i)
            {
                if((m_romeCharMap[i] * 3) < y && y < m_romeCharMap[ i + 1 ])//if number 4 , 9 , 40....
                {
                    string temp = m_romeString;//save string for add to begin of string
                    m_romeString = "";

                    m_romeString += m_romeCharMap[m_romeCharMap[i]];
                    m_romeString += m_romeCharMap[m_romeCharMap[i + 1]];

                    m_romeString += temp;
                    break;
                }
                else if((m_romeCharMap[i]) <= y && y < (m_romeCharMap[i + 1]))//if number 1,2,3..5 ...
                {
                    //cout << "if 2" << endl;
                    string temp = m_romeString;
                    m_romeString = "";

                    int x = y;
                    while (x >= m_romeCharMap[i])
                    {
                        m_romeString += m_romeCharMap[m_romeCharMap[i]];
                        x -= m_romeCharMap[i];
                    }

                    while (x != 0)//if we have fraction
                    {
                        m_romeString += m_romeCharMap[m_romeCharMap[i - 1]];
                        x -= m_romeCharMap[i - 1];
                    }
                    m_romeString += temp;
                    break;
                }
            }
            if(y >= 1000)
            {
                string temp = m_romeString;
                m_romeString ="";
                int x = y / 1000;
                for(int i = 0; i < x; i++)
                {
                    m_romeString += m_romeCharMap[1000];
                }
                m_romeString += temp;
            }
            arabNumber -= y;
            fraction *= 10;
        }
    }
    return m_romeString;
}
//----------------------------------------------------------------
int RomeNumber::operator + (const int& rhs)
{
    int arabNumber = m_arabNumber + rhs;

    return arabNumber;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator + (const RomeNumber& rhs)
{
    RomeNumber temp;
    temp.m_arabNumber = m_arabNumber + rhs.m_arabNumber;

    temp.ConvertFrArabToRome();

    return temp;
}
//-------------------------------------------------------
int RomeNumber::operator - (const int& rhs)
{
    int arabNumber = m_arabNumber - rhs;

    return arabNumber;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator - (const RomeNumber& rhs)
{
    RomeNumber temp;
    temp.m_arabNumber = m_arabNumber - rhs.m_arabNumber;
    temp.ConvertFrArabToRome();

    return temp;
}
//-------------------------------------------------------
int RomeNumber::operator * (const int& rhs)
{
    int arabNumber = m_arabNumber * rhs;

    return arabNumber;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator * (const RomeNumber& rhs)
{
    RomeNumber temp;
    temp.m_arabNumber = m_arabNumber * rhs.m_arabNumber;
    temp.ConvertFrArabToRome();

    return temp;
}
//-------------------------------------------------------
int RomeNumber::operator / (const int& rhs)
{
    int arabNumber = m_arabNumber / rhs;

    return arabNumber;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator / (const RomeNumber& rhs)
{
    RomeNumber temp;
    temp.m_arabNumber = m_arabNumber / rhs.m_arabNumber;
    temp.ConvertFrArabToRome();

    return temp;
}
//-------------------------------------------------------
const int& RomeNumber::operator += (const int& rhs)
{
    m_arabNumber += rhs;
    ConvertFrArabToRome();

    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator += (const RomeNumber& rhs)
{
    m_arabNumber += rhs.m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator -= (const int& rhs)
{
    m_arabNumber -= rhs;
    ConvertFrArabToRome();

    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator -= (const RomeNumber& rhs)
{
    m_arabNumber -= rhs.m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator *=(const int& rhs)
{
    m_arabNumber *= rhs;
    ConvertFrArabToRome();

    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator *= (const RomeNumber& rhs)
{
    m_arabNumber *= rhs.m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator /= (const int& rhs)
{
    m_arabNumber /= rhs;
    ConvertFrArabToRome();

    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator /= (const RomeNumber& rhs)
{
    m_arabNumber /= rhs.m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}
//-------------------------------------------------------
const bool RomeNumber::operator == (const int& rhs)const
{
    if(m_arabNumber == rhs)
    {
        return 1;
    }
    return 0;
}
//-------------------------------------------------------
const bool RomeNumber::operator != (const int& rhs)const
{
    return !(*this == rhs);
}
//-------------------------------------------------------
const bool RomeNumber::operator < (const int& rhs)const
{
    if(m_arabNumber < rhs)
    {
        return 1;
    }
    return 0;
}
//-------------------------------------------------------
const bool RomeNumber::operator <= (const int& rhs)const
{
    return (*this < rhs || *this == rhs);
}
//-------------------------------------------------------
const bool RomeNumber::operator > (const int& rhs)const
{
    return !(*this < rhs);
}
//-------------------------------------------------------
const bool RomeNumber::operator >= (const int& rhs)const
{
    return !(*this <= rhs);
}
//------------------------------------------------------------
const bool RomeNumber::operator == (const RomeNumber& rhs)const
{
    return (*this == rhs.m_arabNumber);
}
const bool RomeNumber::operator != (const RomeNumber& rhs)const
{
    return !(*this != rhs.m_arabNumber);
}
const bool RomeNumber::operator < (const RomeNumber& rhs)const
{
    return (*this < rhs.m_arabNumber);
}
const bool RomeNumber::operator <= (const RomeNumber& rhs)const
{
    return (*this <= rhs.m_arabNumber);
}
const bool RomeNumber::operator > (const RomeNumber& rhs)const
{
    return (*this > rhs.m_arabNumber);
}
const bool RomeNumber::operator >= (const RomeNumber& rhs)const
{
    return (*this >= rhs.m_arabNumber);
}
//- инкремент, декремент (postfix&infix): ++, --
const RomeNumber& RomeNumber::operator ++()
{
    ++m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}
RomeNumber RomeNumber::operator ++(const int)
{
    RomeNumber tmp(*this);
    ++m_arabNumber;
    ConvertFrArabToRome();

    return tmp;
}

RomeNumber RomeNumber::operator --(const int)
{
    RomeNumber tmp(*this);
    --m_arabNumber;
    ConvertFrArabToRome();

    return tmp;
}

RomeNumber RomeNumber::operator --()
{
    --m_arabNumber;
    ConvertFrArabToRome();

    return *this;
}

ostream& operator << (ostream& os, const RomeNumber& obj)
{
    os << "arab number - " << obj.m_arabNumber << endl;
    os << "rome number - " << obj.m_romeString << endl;

    return os;
}

RomeNumber::operator int()const
{
    return m_arabNumber;
}
