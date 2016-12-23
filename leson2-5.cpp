#include <iostream>

using namespace std;

void CharDel(char*const s){
  int j = 0;
 
  for(int i = 1; i < strlen(s); i++){
       if(s[i] == ' ')
       {
           s[j++] = s[i++];
       }
       else
       {
           j++;
       }
  }
  s[j] = '\0';
}

int main(int argc, char *argv[])
{
    const int size = 100 ;
    char s[size] = {};
    gets_s(s,size);
    char_del(s);
    printf(s);
    return 0;
}
