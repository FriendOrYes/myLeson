#include <iostream>
#include <random>
#include <ctime>

using namespace std;


#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))


void CreatPassword(char *password)
{
    int limits[] = {3, 2, 2, 1};
    int sum = 0, i = 0;

    auto sumFunc = [&]()
    {
        for (int i = 0; i < ARRAY_SIZE(limits); ++i)
        {
            sum += limits[i];
        }
    };
    sumFunc();

    while(i < sum)
    {
        int j = rand()%4;
        if(limits[j])
        {
            switch (j) {
            case 0:
                password[i] = rand()%10 + '0';
                break;
            case 1:
                password[i] = rand()%26 + 'a';
                break;
            case 2:
                password[i] = rand()%26 + 'A';
                break;
            default:
                password[i] = '_';
                break;
            }
            i++;
            limits[j]--;
        }
    }
    password[i - 1] = '\0';
}
//-----------------------------------------------------------
int main(int argc, char *argv[])
{
    srand(time(NULL));

    const int size = 8;
    char password[size] = {};

    CreatPassword(password);

    printf(" Encrypted String - %s \n",password);

    return 0;
}
