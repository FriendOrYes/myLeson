#include <iostream>
#include <random>

using namespace std;
void RandomArr(int *arr, const int size)
{
    cout << __FUNCTION__ << endl;
    for(int i = 0; i < size; i++)
    {
        int j = rand() % size;
        swap(arr[i], arr[j]);
    }
}
void InitArr(int *arr, const int size)
{
    int x = 1, i = 0;
    while(x < 100)
    {
       arr[i] = x;
       x+=2;
       i++;
    }
}
void PrintArr(int *arr, const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main(int argc, char *argv[])
{
    time_t(NULL);
    const int size = 50;
    int arr[size];

    InitArr(arr,size);

    RandomArr(arr,size);

    PrintArr(arr,size);

    return 0;
}
