#include <iostream>
#include <random>
#include <ctime>

using namespace std;




/******* typedef *******/
typedef int (*map_t)(int);
typedef int (*red_t)(int, int);
typedef bool (*filt_t)(int);

/*prototype function*/

//---------------------------------------------------------------------------

int *Map(int *const  x, const int size, map_t);
int *Filter(int* x, const int, int&, filt_t);
int Redus(int *const x, const int size, red_t);

//---------------------------------------------------------------------------

int AddForech(int );
int Sum(int, int);
bool MoreThenTwo(int);

//---------------------------------------------------------------------------


int main()
{
    srand(time(0));// рандома к времини ОС

    const int size = 10;
    int x[size];

    cout << "Mas : \n";
    for(int i  = 0; i < size; i++)
    {//initialization mas random elements 0 to 9
        x[i] = rand()%10;
        cout << x[i] <<" \t";
    }
    cout << endl;

    Map(x, size, AddForech);
    cout << "Mas after change : \n";
    for(int i  = 0; i < size; i++)
    {//вывод изменёного масива
        cout << x[i] <<" \t";
    }
    cout << endl;

    int newSize;
    Filter(x, size, newSize, MoreThenTwo);
    cout << "Mas after filter : \n";
    for(int i  = 0; i < newSize; i++)
    {
        cout << x[i] <<" \t";
    }
    cout << endl;

    cout <<"Mas after convolution : ";
    cout << Redus(x, newSize, Sum) << endl;
    return 0;
}

//---------------------------------------------
int *Map(int *const x, const int size, map_t maping)
{
    for(int i = 0; i < size; ++i)
    {
        x[i]  = maping(x[i]);//change value for each element
    }
    return x;
}

int AddForech(int x )
{
    return x + 1;
}
//---------------------------------------------
int Redus(int *const x, const int size, red_t action)
{
    int value = 0;
    for(int i = 0; i < size; ++i)
    {
      value = action(value, x[i]);
    }
    return value;
}

int Sum(int x,int y)
{
     return  x + y;
}

//---------------------------------------------

int *Filter(int x[], const int size, int& newSize, filt_t filtering)
{
    cout << __FUNCTION__ << endl;
    int j = 0;
    for(int i = 0; i < size; i ++)
    {
        if(filtering(x[i]))
        {//filtering mas by user function
            x[j] = x[i];
            j++;
        }
    }
    newSize = j;//new size mas
    return x;
}

bool MoreThenTwo(int x)
{//value more then two return 1
    if(x > 2)
    {
        return 1;
    }
    return 0;
}
//---------------------------------------------
