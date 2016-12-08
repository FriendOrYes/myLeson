#include <iostream>
#include <stdio.h>

using namespace std;
void coding_string(const char* s, char *s2 ,const char *call_number){
    int size_shifr = strlen(call_number);
    int i = 0;
    for(;s[i]; i++)
    {
        s2[i] = s[i];
        cout<< s2[i]<<endl;
        for(int j = 0 ; call_number[j] ; j++){
            int k = j;
            cout <<"call_number[ "<< k <<"] = "<< call_number[k] << endl;
            if(s[i] == call_number[k]){
                s2[i] = call_number[(j+5)%size_shifr];
            }
        }
    }
    s2[i] = '\0'; 
}
int main(int argc, char *argv[])
{
    const int size = 100;
    char s[size] ,s2[size];
    const char call_number[] = "abcdfg123456-0";
    gets_s(s,size);
    coding_string(s,s2,call_number);
    printf("Original string %s\n",s);
    printf("Coded %s\n",s2);
    return 0;
}
