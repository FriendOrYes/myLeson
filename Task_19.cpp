#include <iostream>
#include <random>
#include <ctime>

using namespace std;




/***typedef*******/
typedef int (*TMap)(int);
typedef int (*TRed)(int,int);
typedef bool (*TFilt)(int);

/*
 *прототипы главных функций , аргументами которых является масив и его размеры , и
 *указатель на функцию которая выполняет разные задачи над масивом
*/
int *Map(int *x ,int &size ,TMap);
int *Filter(int *x ,int &size , TFilt);
int Redus(int *x , int &size , TRed);

/*
 *указатели на функцию с аргументами <int *> и <int& >
 *структура создания указателя на функцию :
 *<возвращаемый тип даных функцией> (*имя указателя )(<аругменты>,...);
*/
/*
bool (*change)(int );
bool (*filt)(int );
int (*red)(int , int);
*/

/*прототипы функций */
int NegativeMas(int );
int RedusMas(int , int);
bool FilterMas(int );



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
    //change = *NegativeMas;//получение указателя на функцию
    x = Map(x,size, NegativeMas );
    cout << "Mas after change : \n";
    for(int i  = 0 ; i < size ; i++)
    {//вывод изменёного масива
        cout << x[i] <<" \t";
    }
    cout << endl;
//вторая функция filter - изменение масива и его размера
//возврат нового от фильтрованого масива
//предварительно следя за адресами
    cout << "main before finish function " << endl;
    cout << "adress x in stack : " << &x << endl;
    cout << "adress x heap : " << x << endl;
    cout << endl;
    x = Filter(x, size , FilterMas);
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

    cout <<"Mas after convolution : ";
    cout << Redus(x,size,RedusMas) << endl ;
    delete []x;
    return 0;
}

/**************************************/
int *Map(int *x ,  int &size , int (*TMap)(int))
{//функция возвращает указатель масива что изменился
    for(int i = 0 ; i < size ; ++i)
    {
        x[i]  = TMap(x[i]);
    }
    return x;
}

int NegativeMas(int x )
{
    return x+1;
}
/**************************************/
int Redus(int *x ,  int &size ,TRed redusing)
{
    int value = 0;
    for(int i = 0 ; i < size ; i+=2)
    {
        value += redusing(x[i],x[i+1]);
    }
    return value;
}

int RedusMas(int x , int y)
{
        return (x + y);
}

/**************************************/

int *Filter(int *x , int& size , TFilt filtering)
{
    cout << __FUNCTION__ << endl ;
    int j = 0;
    int *a  = new int [size];//создание временого масива
    for(int i = 0 ; i < size ; i ++)
    {
        //cout << filt(x[i]);
        if( filtering(x[i]))
        {//фильтруем
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
    delete []a;//очищаем временый масив
    return x;
}

bool FilterMas(int x)
{//фильтрует масив , переберает и создаёт новый масив с елементами больше 2
    if(x > 2)
    {
        return 1;
    }
    return 0;
}
/**************************************/
