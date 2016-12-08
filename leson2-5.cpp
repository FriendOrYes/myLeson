#include <iostream>

using namespace std;

void char_del(char*& s){
  int j = 0;
  char *s2 = new char[strlen(s)];
  for(int i = 0 ; s[i] != 0 ;i++){
       if( i == 0 && isalpha(s[i])){
           cout << s[i] << " - " << i <<endl;
           continue;
       }
       if(s[i] == ' '){
           cout << s[i]<< " - " << i  << endl;
           s2[j] = s[i];
           i++;
           j++;
       }else{
           cout << s[i]<< " - " << i << endl;
           s2[j] = s[i];
           j++;
       }

    }
  s2[j] = '\0';
  delete []s;
  s = s2;
}

int main(int argc, char *argv[])
{
    int size = 100 ;
    char *s = new char[size]();
    gets_s(s,size);
    char_del(s);
    printf(s);
    delete []s;
    return 0;
}
