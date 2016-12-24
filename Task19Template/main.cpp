#include <iostream>
#include <random>
#include <ctime>
#include <cstring>
#include "templatefunction.h"

using namespace std;


template<typename TRedus>
TRedus Sum(TRedus x,TRedus y)
{
     return  x + y;
}

template<typename TFilter>
bool MoreThenTwo(TFilter x)
{//value more then two return 1
    if(x > 2)
    {
        return 1;
    }
    return 0;
}

template<>
bool MoreThenTwo<bool>(bool x)
{//value more then two return 1
    if(x == 1)
    {
        return 1;
    }
    return 0;
}
template<>
bool MoreThenTwo<char>(char x)
{//value more then two return 1
    if(toupper(x))
    {
        return 1;
    }
    return 0;
}
template<typename TMap>
TMap AddForech(TMap x )
{
    return x + 1;
}

template<>
bool AddForech<bool>(bool x )
{
    return !x;
}


//---------------------------------------------------------------------------
int main()
{
    srand(time(0));// рандома к времини ОС

    const int size = 10;
    char x[size];

    InitMas<char>(x,size);

    PrintMas<char>(x,size);
    cout << endl;

    Map<char>(x, size, AddForech<char>);

    PrintMas<char>(x,size);

    cout << endl;

    int newSize;

    Filter<char>(x, size, newSize, MoreThenTwo<char>);

    PrintMas<char>(x,newSize);
    cout << endl;

    cout << Redus<char>(x, newSize, Sum<char>) << endl;
    return 0;
}
