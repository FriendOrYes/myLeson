#include <iostream>

using namespace std;


//-----------------------------------
void SwapMas(int * const x , int size)
{
    for(int i = 0; i < size; i+=2)
    {
        swap(x[i],x[i + 1]);
    }
}
//-----------------------------------
void PrintMas(int *const x , const int size )
{
    for(int i = 0; i < size; i++)
    {
        cout << x[i];
    }
    cout << endl;
}
//-----------------------------------
void InitMas(int *const x , const int size)
{
    for(int i = 0; i < size; i++){
        cin >> x[i];
    }
}
//-----------------------------------

int main()
{
    const int size = 12;
    int x[size] = {};

    cout << "Init Mas: \n";
    InitMas(x,size);
    PrintMas(x,size);

    cout << "Swap Mas: \n";
    SwapMas(x,size);
    PrintMas(x,size);

    return 0;
}
