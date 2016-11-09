#include <iostream>

using namespace std;
void char_del(char *s){
       for(int i = 0 ; s[i] != 0 ; i++){
           if( i == 0 && isalpha(s[i])){
               for(int j = i ;s[j] != 0 ; j++ )
                   s[j] = s[j+1];
           }
           if(s[i] == ' '){
               for(int j = i+1 ;s[j] != 0 ; j++ )
               {
                   s[j] = s[j+1];
                   cout << j << "-" << s[j] << endl;
               }
           }
       }
}
int main(int argc, char *argv[])
{
    int size = 100 ;
    char *s ;
    s = new char[size];
    gets_s(s,size);
    char_del(s);
    printf("Строка после преобразования");
    printf(s);
    return 0;
}
