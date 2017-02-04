#include <iostream>
#include <random>
#include <ctime>
#include <cstring>

#include "templatefunction.h"

using namespace std;

int Sum(const int& x, const int& y)
{
     return  x + y;
}

bool MoreThenTwo(const int& x)
{//value more then two return 1
    if(x > 2)
    {
        return 1;
    }
    return 0;
}


int AddForech(const int& x)
{
    return x + 1;
}

//---------------------------------------------------------------------------
int main()
{
    srand(time(0));// рандома к времини ОС

    const int size = 10;
    int x[size];

    InitMas(x, size);

    PrintMas(x, size);
    cout << endl;

    Map(x, size, AddForech);

    PrintMas(x, size);

    cout << endl;

    int newSize;

    Filter(x, size, newSize, MoreThenTwo);

    PrintMas(x,newSize);
    cout << endl;

    cout << Redus(x, newSize, Sum) << endl;
    return 0;
}
