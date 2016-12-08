#include <iostream>
#include <stdio.h>
using namespace std;
void foo_map(int* symbols ,char * s,int size);
int main()
{
    int size = 5;

    int *symbols = new int[256]() ;

    char s[5] = "dsda";
    foo_map(symbols,s,size);
    delete []symbols;
    return 0;
}
void foo_map(int* symbols ,char * s,int size){
    for(int i = 0 ; i <size;++i)
    {
        symbols[s[i]] +=1;
    }
    for(int i = 0 ; i < 256 ;++i)
    {
            char c = i;
            cout << c << ": " << symbols[i] << endl;

    }
}
