#include <iostream>
#include <stdio.h>
using namespace std;
bool isRepeated_char(char*,char*,int);
void map(char*,char*,int*);
int main()
{
    int *count ,size = 100;
    char *s = new char[size](),*s2 = new char[size]();
    count = new int [size];
    gets_s(s,size);
    map(s,s2,count);
    for (int j = 0; s2[j] != 0; j++){
        cout << s2[j] <<"\t"<<count[j]<<endl;
    }
    delete []s;
    delete []s2;
    delete []count;
    return 0;
}
void map(char *s ,char *s2, int *count){
    int kol = 0;
    for(int i = 0 ; s[i] != 0 ;i++){
        count[kol] = 0;
        s2[kol] = 0;
        if(isRepeated_char(s,s2,i)){
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
bool isRepeated_char(char *s,char *s2,int i){
    for(int j = 0 ; s2[j] != 0;j++){
        if(s[i] == s2[j]){ return false;}
    }
    return true;
}
