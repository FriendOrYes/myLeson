#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int size = 8;
    char *pasw = new char[size+1];
    bool Up , low,numb;
    numb = Up = low = false;
    int ran = 3, k;
    for(int i  = 0 ; i < 8 ; i++)
    {
        if( i < 3){
            k = rand()%ran;
            if( k == 0 )
                if(numb)k = rand()%2 + 1;
                else numb = true;
            if(k == 1)
                if(numb){k = rand()%2; k == 1?k = 2:k = 0;}
                else low = true;
            if(k == 2)
                if(numb)k = rand()%2;
                else Up = true;
        }
        if( i > 2)ran = 4;
        k = rand()%ran;
        char c;
        switch(k)
        {
            case 0:{c = rand()%10 + 48; pasw[i] = c; cout<<pasw[i]<<" "<< k <<endl;}break;
            case 1:{c = rand()%26 + 97; pasw[i] = c; cout<<pasw[i]<<" "<< k <<endl;}break;
            case 2:{c = rand()%26 + 65; pasw[i] = c; cout<<pasw[i]<<" "<< k <<endl;}break;
            case 3:{pasw[i] = '_'; cout << pasw[i] << " "<< k<<endl;}break;
        }

    }
    pasw[8] = 0;
    printf("  String - %s \n",pasw);
    return 0;
}
