#include <iostream>
#include <stdio.h>

using namespace std;

void FooMap(int* symbols ,char * s , int size);

//---------------------------------------------------------------
int main()
{
    const int size = 5;
    const int sizeMap = 256; 
    
    int symbols[sizeMap] = {};
    char s[size] = "dsda";
    
    foo_map(symbols, s ,size , sizeMap);
   
    return 0;
}
//---------------------------------------------------------------

void FooMap(int* const  symbols , char* const  s , const int size , const int sizeMap){
   
    for(int i = 0; i < size; ++i)
    {
        symbols[s[i]]+=1;
    }
    
    for(int i = 0; i < sizeMap; ++i)
    {
        if(symbols[i] > 0)
        {
            char c = i;
            cout << c << ": " << symbols[i] << endl;
        }
    }
}
