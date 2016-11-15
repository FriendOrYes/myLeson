#include <iostream>
#include <stdio.h>

using namespace std;
void coding_string(const char* s, char *s2 ,const char *call_number){
    int size_shifr = strlen(call_number);
    for(int i = 0;s[i]; i++)
    {
        s2[i] = s[i];
        cout<< s2[i]<<endl;
        for(int j = 0 ; call_number[j] ; j++){
            int k = j;
            cout <<"call_number[ "<< k <<"] = "<< call_number[k] << endl;
            if(s[i] == call_number[k]){//если нашли подходящий елемент из шифр таблицы
               //проверяем выходит ли он за придел масива при кодировке
               //cout <<"j + 5 ="<< j + 5 << endl 
               //если да то делаем кольцо и начинаем с начала
               //если нет то переходим на 5 элементов вперёд и шифруем
                k = j;
                j+5 > size_shifr? k = j+5 - size_shifr:k+=5;//
                s2[i] = call_number[k];
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
    printf("Coded %s\n",s2);
    delete[]s;
    delete[]s2;
    return 0;
}
