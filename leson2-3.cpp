#include <iostream>
#include <stdio.h>

using namespace std;
void coding_string(const char* s, char *s2 ,const char *call_number){
    int size_shifr = strlen(call_number);
    for(int i = 0;s[i] != 0 ; i++)
    {
        s2[i] = s[i];
        for(int j = 0 ; call_number[j] != 0 ; j++){
            if(s[i] == call_number[j]){
                if(j+5 > size_shifr){
                    j = j+5 - size_shifr;
                }
                j+5 > size_shifr?j = j+5 - size_shifr:j+=5;
                s2[i] = call_number[j];
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int size = 100;
    char *s , *s2;
    s = new char[size];
    s2 = new char[size];
    memset(s2,0,size*sizeof(char));
    const char call_number[] = "abcdfg123456-0";
    gets_s(s,size);
    coding_string(s,s2,call_number);
    printf("Original string %s\n",s);
    printf("Coded string%s\n",s2);
    delete[]s;
    delete[]s2;
    return 0;
}
