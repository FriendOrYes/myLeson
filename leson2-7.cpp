#include <iostream>
#include <random>
#include <ctime>

using namespace std;
void func(int *x,int size)
{
    cout<<__FUNCTION__<<endl;
    for(int i = size ; i  > 0; i-- )
    {
        int j = rand()%i;
        cout << x[j] << endl ;
        for(int k = j;k < size - 1 ;k++)
        {
            x[k] = x[k+1];
        }
    }
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *a = new int[50];
    int x=1,i=0 , size ;
    while(x<100)
    {
       a[i]=x;
       cout<<a[i]<<endl;
       x+=2;
       i++;
    }
    size = i;
    func(a,size);
    delete []a
    return 0;
}
