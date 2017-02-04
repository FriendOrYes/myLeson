#ifndef TEMPLATEFUNCTION_H
#define TEMPLATEFUNCTION_H
#include <random>


////---------------------------------------------------------------------------

template<typename T>
void InitMas(T x[], const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%10;
    }
}
template<>
void InitMas<char>(char x[], const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%25 + 65;
    }
}

template<>
void InitMas<bool>(bool x[], const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%2;
    }
}
template<typename T>
void PrintMas(T x[], const int& size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << x[i] << " ";
    }
}
//---------------------------------------------
template<typename T>
T *Map(T x[], const int& size, T (*pMapFunc)(const T&))
{
    cout << __FUNCTION__ << endl;
    for(int i = 0; i < size; ++i)
    {
        x[i] = pMapFunc(x[i]);//change value for each element
    }
    return x;
}
//---------------------------------------------
template<typename T>
T Redus(T *const x, const int& size, T (*pRedFunc)(const T&, const T&))
{
    cout << __FUNCTION__ << endl;
    T value = 0;
    for(int i = 0; i < size; ++i)
    {
      value = pRedFunc(value, x[i]);
    }
    return value;
}

//---------------------------------------------
template<typename T>
T *Filter(T x[], const int& size, int& newSize, bool (*Filt_ptr_f)(const T&))
{
    cout << __FUNCTION__ << endl;
    int j = 0;
    for(int i = 0; i < size; i ++)
    {
        if(Filt_ptr_f(x[i]))
        {//filtering mas by user function
            x[j] = x[i];
            j++;
        }
    }
    newSize = j;//new size mas
    return x;
}
//---------------------------------------------


#endif // TEMPLATEFUNCTION_H
