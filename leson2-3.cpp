#include <iostream>
#include <stdio.h>

using namespace std;
void CodingString(const char* s, char *s2 ,const char callNumber){
    const int sizeShifr = strlen(callNumber);
    int i = 0;
    for(; i < strlen(s); ++i)
    {
        s2[i] = s[i];
        cout << s2[i] << endl;
        for(int j = 0; j < sizeShifr ; j++){
            int k = j;
            cout <<" call_number[ " << k << "] = " << callNumber[k] << endl;
            if(s[i] == callNumber[k]){
                s2[i] = callNumber[(j+5)%sizeShifr];
            }
        }
    }
    s2[i] = '\0'; 
}
int main()
{
    const int size = 100;
    char s[size] ,s2[size];
    const char callNumber[] = "abcdfg123456-0";
    gets_s(s,size);
    CodingString(s,s2,callNumber);
    printf("Original string %s\n",s);
    printf("Coded %s\n",s2);
    return 0;
}
