#include <iostream>
#include <stdio.h>
using namespace std;
bool func2(char*,char*,int);
void func(char*,char*,int*);
int main()
{
    int *count ,size = 100;
    char *s = new char[size],*s2 = new char[size];
    count = new int [size];
    memset(s2,0,size*sizeof(char));
    gets_s(s,size);
    func(s,s2,count);
    for (int j = 0; s2[j] != 0; j++){
        cout << s2[j] <<"\t"<<count[j]<<endl;
    }
    delete []s;
    delete []s2;
    delete []count;
    return 0;
}
void func(char *s ,char *s2, int *count){
    int kol = 0;
    for(int i = 0 ; s[i] != 0 ;i++){
        count[kol] = 0;
        s2[kol] = 0;
        if(func2(s,s2,i)){
            for (int j = 0 ; s[j] != 0;j++){
                if(s[i] == s[j]){
                    count[kol]++;
                    s2[kol] = s[i];
                }
            }
            kol++;
        }
    }
}
bool func2(char *s,char *s2,int i){
    for(int j = 0 ; s2[j] != 0;j++){
        if(s[i] == s2[j]){ return false;}
    }
    return true;
}