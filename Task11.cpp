#include <iostream>

using namespace std;

void CharDel(char* const s)
{
  int j = 0;

  for(int i = 1; i < strlen(s); i++)
  {
       s[j++] = s[i];

       if(s[i] == ' ')
       {
           i++;
       }
  }
  s[j] = '\0';
}

int main()
{
    const int size = 100 ;
    char s[size] = {};

    gets_s(s, size);
    CharDel(s);

    cout << s << endl;
    return 0;
}
