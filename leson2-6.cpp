#include <iostream>

using namespace std;
void func(int *x ,int size)
{
    cout<< __FUNCTION__ << endl;
    int temp;
    for(int i = 0 ; i < size ; i+=2)
    {
        temp = x[i];
        x[i] = x[i+1];
        x[i+1] = temp;
    }
}

int main(int argc, char *argv[])
{
    int size = 12;
    int *x = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin >> x[i];
    }
    func(x,size);
    for(int i = 0 ; i < size ; i++){
        cout << x[i];
    }
    delete[]x;
    return 0;
}
