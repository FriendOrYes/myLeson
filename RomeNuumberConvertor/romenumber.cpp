#include "romenumber.h"

RomeNumber::RomeNumber()
    : m_romeString("")
    , m_arabNumber(-1)
{

}
//--------------------------------------------------
RomeNumber::RomeNumber(const RomeNumber& obj)
    : m_arabNumber(obj.m_arabNumber)
    , m_romeString(obj.m_romeString)
{

}
//--------------------------------------------------
RomeNumber::RomeNumber(const char* romeChar)
    : m_romeString(romeChar)
    , m_arabNumber(m_romeCharMap[romeChar[0]])
{
    ConvertFrRomeToArab();

}
//----------------------------------------------------------------
RomeNumber::RomeNumber(const int& arabNumber)
    : m_arabNumber(arabNumber)
    , m_romeString("")
{
}
//----------------------------------------------------------------
const string& RomeNumber::GetRomeString()
{
    ConvertFrArabToRome();
    return m_romeString;
}

const int& RomeNumber::GetArabNumber() const
{
    return m_arabNumber;
}
//----------------------------------------------------------------
RomeNumber::~RomeNumber()
{
    cout << __FUNCTION__ << endl;
}
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
    m_romeString = "";
    int arabNumber = m_arabNumber;
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
            else if(arabNumber == 9)
            {
                string temp = m_romeString;//save string for add to begin of string

                m_romeString = "";
                m_romeString += m_romeCharMap[m_romeCharMap[i]];
                m_romeString += m_romeCharMap[m_romeCharMap[i + 2]];

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
            m_romeString = "";
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
    return m_romeString;
}
const RomeNumber& RomeNumber::operator = (const RomeNumber& obj)
{
    if(this != &obj)
    {
        RomeNumber tmp(obj);
        tmp.m_arabNumber = obj.m_arabNumber;

        Swap(tmp);
    }
    return *this;
}
//---------------------------------------------------------------
void RomeNumber::Swap(RomeNumber& obj)
{
    std::swap(obj.m_arabNumber, this->m_arabNumber);
    std::swap(obj.m_romeString, this->m_romeString);
}
//----------------------------------------------------------------
int RomeNumber::operator + (const int& rhs)
{
    return  RomeNumber(*this) += rhs;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator + (const RomeNumber& rhs)
{
    return RomeNumber(*this) += rhs;
}
//-------------------------------------------------------
int RomeNumber::operator - (const int& rhs)
{
    return RomeNumber(*this) -= rhs;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator - (const RomeNumber& rhs)
{
    return RomeNumber(*this) -= rhs;
}
//-------------------------------------------------------
int RomeNumber::operator * (const int& rhs)
{
    return RomeNumber(*this) *= rhs;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator * (const RomeNumber& rhs)
{
    return RomeNumber(*this) *= rhs;
}
//-------------------------------------------------------
int RomeNumber::operator / (const int& rhs)
{
    return RomeNumber(*this) /= rhs;
}
//-------------------------------------------------------
RomeNumber RomeNumber::operator / (const RomeNumber& rhs)
{
    return RomeNumber(*this) /= rhs;
}
//-------------------------------------------------------
const int& RomeNumber::operator += (const int& rhs)
{
    m_arabNumber += rhs;


    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator += (const RomeNumber& rhs)
{
    m_arabNumber += rhs.m_arabNumber;
    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator -= (const int& rhs)
{
    m_arabNumber -= rhs;
    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator -= (const RomeNumber& rhs)
{
    m_arabNumber -= rhs.m_arabNumber;

    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator *=(const int& rhs)
{
    m_arabNumber *= rhs;
    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator *= (const RomeNumber& rhs)
{
    m_arabNumber *= rhs.m_arabNumber;

    return *this;
}
//-------------------------------------------------------
const int& RomeNumber::operator /= (const int& rhs)
{
    m_arabNumber /= rhs;

    return m_arabNumber;
}
//-------------------------------------------------------
const RomeNumber& RomeNumber::operator /= (const RomeNumber& rhs)
{
    m_arabNumber /= rhs.m_arabNumber;

    return *this;
}
//-------------------------------------------------------
const bool RomeNumber::operator == (const int& rhs)const
{
    return (m_arabNumber == rhs);
}
//-------------------------------------------------------
const bool RomeNumber::operator != (const int& rhs)const
{
    return !(*this == rhs);
}
//-------------------------------------------------------
const bool RomeNumber::operator < (const int& rhs)const
{
    return (m_arabNumber < rhs);
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
//--
const bool RomeNumber::operator != (const RomeNumber& rhs)const
{
    return !(*this == rhs);
}
//--
const bool RomeNumber::operator < (const RomeNumber& rhs)const
{
    return (*this < rhs.m_arabNumber);
}
//--
const bool RomeNumber::operator <= (const RomeNumber& rhs)const
{
    return (*this <= rhs.m_arabNumber);
}
//--
const bool RomeNumber::operator > (const RomeNumber& rhs)const
{
    return (*this > rhs.m_arabNumber);
}
//--
const bool RomeNumber::operator >= (const RomeNumber& rhs)const
{
    return (*this >= rhs.m_arabNumber);
}

//- инкремент, декремент (postfix&infix): ++, --
const RomeNumber& RomeNumber::operator ++()
{
    return *this += RomeNumber(1);
}
RomeNumber RomeNumber::operator ++(const int)
{
    RomeNumber tmp(*this);
    ++m_arabNumber;

    return tmp;
}

RomeNumber RomeNumber::operator --(const int)
{
    RomeNumber tmp(*this);
    --m_arabNumber;

    return tmp;
}

RomeNumber RomeNumber::operator --()
{
    return *this -= RomeNumber(1);
}

ostream& operator << (ostream& os, RomeNumber& obj)
{
    os << "arab number - " << obj.GetArabNumber() << endl;
    os << "rome number - " << obj.ConvertFrArabToRome() << endl;

    return os;
}
istream& operator >> (istream& is, RomeNumber& obj)
{
    is >> obj.m_arabNumber;
    return is;
}

RomeNumber::operator int()const
{
    return m_arabNumber;
}
