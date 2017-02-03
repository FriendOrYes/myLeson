#ifndef TEMPLATEFUNCTION_H
#define TEMPLATEFUNCTION_H
#include <random>
//int *Map(int *const  x, const int size, int (*Map_ptr_f)(int));
//int *Filter(int* x, const int, int&, bool (*Filt_ptr_f)(int));
//int Redus(int *const x, const int size,int (*Red_ptr_f)(int,int));

////---------------------------------------------------------------------------

//int AddForech(int );
//int Sum(int, int);
//bool MoreThenTwo(int);
template<typename TInit>
void InitMas(TInit x[], const int size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%10;
    }
}
template<>
void InitMas<char>(char x[], const int size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%('z'-'a'+1) + 'a';
    }
}

template<>
void InitMas<bool>(bool x[], const int size)
{
    for(int i = 0; i < size; ++i)
    {
        x[i] = rand()%2;
    }
}
template<typename TInit>
void PrintMas(TInit x[], const int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << x[i] << " ";
    }
}
//---------------------------------------------
template<typename TMap>
TMap *Map(TMap x[], const int size, TMap (*pMapFunc)(TMap))
{
    cout << __FUNCTION__ << endl;
    for(int i = 0; i < size; ++i)
    {
        x[i] = pMapFunc(x[i]);//change value for each element
    }
    return x;
}
//---------------------------------------------
template<typename TRedus>
TRedus Redus(TRedus *const x, const int size, TRedus (*pRedFunc)(TRedus,TRedus))
{
    cout << __FUNCTION__ << endl;
    TRedus value = 0;
    for(int i = 0; i < size; ++i)
    {
      value = pRedFunc(value, x[i]);
    }
    return value;
}

//---------------------------------------------
template<typename TFilter>
TFilter *Filter(TFilter x[], const int size, int& newSize, bool (*Filt_ptr_f)(TFilter))
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
