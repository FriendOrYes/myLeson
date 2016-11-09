#include <iostream>
#include <stdio.h>
using namespace std;

char* CS_init(char *s,int size){
    s = new char[size];
    memset(s,0,(size)*sizeof(char));//обнуляем строку
    return s;
}
char* cat(char *s1 ,const char *s2){
    char *s3 = s1;//создаём указатель s3
    while(*s3)s3++;//пробегаем  строку s1 и ищем конец её
    while(*s3++ = *s2++);//берём с начала строки 2 и начинаем добовлять к строке 1 пока не найдём конец строки 1
    return s1;//возвращаем указатель на s1
}
int main(int argc, char *argv[])
{
    /*Инициализация строк */
    const int size = 100;
    char* s1 , *s2;
    s1 = new char[size];
    memset(s1,0,(size)*sizeof(char));//обнуляем строку
    s2 = new char[size];
    memset(s2,0,(size)*sizeof(char));//обнуляем строку
    /*запонение строк */
    gets_s(s1,size);
    gets_s(s2,size);
    /*Конкетинирование*/
    cat(s1,s2);
    printf(s1);
    /*Очистка памяти*/
    delete[]s1;
    delete[]s2;
    /*Конец*/
    return 0;
}
