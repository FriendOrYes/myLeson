﻿#include <iostream>
#include <random>
#include <ctime>

using namespace std;

/*
 *прототипы главных функций , аргументами которых является масив и его размеры , и
 указатель на функцию которая выполняет разные задачи над масивом
*/
int *map(int *x ,int &size , void (*)(int *,int& size));
int *filter(int *x ,int &size , void (*)(int *&,int& size));
int redus(int *x , int &size , void (*)(int *,int& size));

/*
 *указатели на функцию с аргументами <int *> и <int& >
 *структура создания указателя на функцию :
 *<возвращаемый тип даных функцией> (*имя указателя )(<аругменты>,...);
*/
void (*change)(int * , int &size );
void (*filt)(int *& , int &size );
void (*red)(int * ,  int &size);


/*прототипы функций */
void negative_mas(int * ,int &size );
void redus_mas(int * , int &size);
void filter_mas(int*& , int &size );


int main(int argc, char *argv[])
{
    srand(time(0));//привязка рандома к времини ОС
    int size = 10;
    int *x  = new int[size];//создание диномического мисива из 10 елементов
    cout << "Mas : \n";
    for(int i  = 0 ; i < size ; i++)
    {//заполнение масива рандомными елементами от 0 - 9
        x[i] = rand()%10;
        cout << x[i] <<" \t";
    }
    cout <<endl;

//первая функция map - изменение масива
//меняется лишь содержимое но не размер
    change = &negative_mas;//получение указателя на функцию
    x = map(x,size,change);
    cout << "Mas after change : \n";
    for(int i  = 0 ; i < size ; i++)
    {//вывод изменёного масива
        cout << x[i] <<" \t";
    }
    cout << endl;

    filt = &filter_mas;
//вторая функция filter - изменение масива и его размера
//возврат нового от фильтрованого масива
//предварительно следя за адресами
    cout << "main before finish function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;
    x = filter(x, size , filt);
    cout << "Mas after filter : \n";
    for(int i  = 0 ; i < size ; i++)
    {
        cout << x[i] <<" \t";
    }
    cout << "main after finish function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;

//тритья функция redus - выполняет “свертку” массива,
//последовательно применяя некоторое действие над 1м и 2м элементами и помещая результат на место 1-го элемента.
//Повторяет до тех пор пока в массиве не останется 1 элемент. Возвращает значение этого элемента.
    red = &redus_mas;
    cout <<"Mas after convolution : ";
    cout << redus(x,size,red) << endl ;
    delete []x;
    return 0;
}

int *map(int *x ,  int &size , void (*func)(int *,int& size))
{//функция возвращает указатель масива что изменился
    func(x,size);
    return x;
}
void negative_mas(int *x , int& size )
{//уменьшает каждый елемент масива в 2
    for(int i = 0 ; i < size ; ++i)
    {
        x[i] /= 2 ;
    }
}
int redus(int *x ,  int &size , void (*func)(int *, int &size))
{
    func(x,size);
    return x[0];
}

void redus_mas(int *x , int& size )
{//заносит в 0 елемент масива суму всего масива
    for(int i = 1 ; i < size ; ++i)
    {
        x[0] += x[i] ;
    }
}
int *filter(int *x , int& size , void (*func)(int*& ,int& size))
{
    cout << "filter function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;
    func(x,size);
    return x;
}
void filter_mas(int*& x ,int& size)
{//фильтрует масив , переберает и создаёт новый масив с елементами больше 2
    cout << "filter_mas function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;
    int *a  = new int [size];//создание временого масива
    int j = 0;
    for(int i = 0 ; i < size ; i ++)
    {
        if(x[i] > 2){//фильтруем
            a[j] = x[i];
            j++ ;
        }
    }
    delete []x;//очищаем старыйй масив
    size = j ;//меняем размер
    cout << size <<endl ;
    x = new int[size];//выделяем память под новый масив = количеству проходящих елементов
    for(int i = 0 ; i < size ; i ++)
    {//копирование в новый масив с временоого масива
        x[i] = a[i];
    }
    cout << "filter_mas finish function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;
    delete []a;//очищаем временый масив
    a = nullptr;
}