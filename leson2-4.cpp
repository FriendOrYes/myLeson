#include <iostream>
#include <stdio.h>

using namespace std;
#define znak (s[i] == ' ' || s[i]== '\t' || s[i] == '.' || s[i]== ',' || s[i] == '!' || s[i] == '?')
void string_up(char *s){
    for(int i = 0 ; s[i] != 0 ; i++)
    {
        if(i == 0){s[i] = toupper(s[i]);cout<< i << "-"<<s[i]<<endl;}
        if(znak){
            while(!isalpha(s[i]) && s[i]!=0 ){
                cout<< i << "-"<<s[i]<<endl;
                i++;
            }
            s[i] = toupper(s[i]);
        }
    }
}
int main(int argc, char *argv[])
{
    int size = 100 ;
    char *s ;
    s = new char[size];
    gets_s(s,size);
    string_up(s);
    printf(s);
    delete []s;
    return 0;
}
