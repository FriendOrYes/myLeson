#include <iostream>
#include <stdio.h>


using namespace std;
struct Professors;
struct Student
{
    char *name;
    unsigned age;
    float gpa;//средний бал
    Professors* supervisor;
    //Конструктор по умолчанию
    Student(){
        name = new char[20];
        age  = 0;
        gpa  = 0;
        supervisor = NULL;
    }
    //псевдо деструктор для очистки памяти
    void Clear(){
        cout<<__FUNCTION__<<endl;
        delete []name;
        supervisor = NULL;
        delete supervisor;
        age  = 0;
        gpa  = 0;
    }
};
struct Professors
{
    char *name;
    unsigned age;
    unsigned salary;//зарплата
    Professors(){
        name = new char[20];
        age = 0;
        salary = 0;
    }
    void Clear(){
        cout<<__FUNCTION__<<endl;
        delete []name;
        age  = 0;
        salary  = 0;
    }
};
/*прототипы функций*/
/*-----------------------------------------------------------------------------------------------------------------*/

float average_mark(Student*,int );//поиск среднего балла групы
Student *GoodStudent(Student*, int);//поиск студента с лучшим средним баллом
Student *BadStudent(Student*, int);//поиск студента с хучшим средним баллом
bool Show_data(Student* ,int );//вывести информацию всех студентов групы
bool Show_data(Student* );//вывести информацию студента
bool Show_data(Professors* );//вывести информацию о профессоре
bool Show_data(Professors*, int);//вывести информацию о всех профессорах
bool Clear_List(Student* ,int);//очистить пямять выделинною под структуру Student и её переменные
bool Clear_List(Professors *, int );//очистить пямять выделинною под структуру Professors и её переменные
bool Init_Data(Student* ,int);//заполенение даных о групе студентов
bool Init_Data(Professors* ,int);//заполнение даных Профессоров
bool Find_Supervisor(Professors*,Student*  ,int , int );//найти супервайзеров для студентов
bool ShowStudVs50oldSupervisopr(Student* , int );//определить и показать студентов у которых супервайзерам за 50 лет

/*-----------------------------------------------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
    int size,size_professors;
    printf("Input size of group  - ");
    cin >> size;
    //создание обьектов структур)
    Student *group_student  = new Student[size];
    Professors *professors ;
    //инициализация заполнение данных
    !Init_Data(group_student,size)?cout<<"Error we have list \n":cout<<"Create new List of student \n";
    Show_data(group_student,size);//показ даных

    /*Найти студента с лучшим/худшим баллом */
    printf("Best Student :\n");
    Show_data(GoodStudent(group_student,size));
    printf("Bad Student :\n");
    Show_data(BadStudent(group_student,size));

    /*поиск среднего бала у групы */
    cout << "GPA of group  = " << average_mark(group_student,size) << endl;

    /* Заполнение информации о профессорах */
    printf("Input number of Professors  - ");
    cin >> size_professors;
    professors = new Professors[size_professors];
    !Init_Data(professors,size_professors)?cout<<"Error we have list \n":cout<<"Create new List of supervisers \n";

    /*поиск супервайзеров(научных руководителей для студентов)*/
    Find_Supervisor(professors,group_student,size,size_professors);
    //Show_data(group_student,size);

    /*вывод студентов у которых научным руководителяям за 50 лет*/
    printf("Stud Vs 50 old Supervisopr\n");
    ShowStudVs50oldSupervisopr(group_student,size);

    /*Очистка памяти выделеной под структуры и её поля*/
    Clear_List(professors,size_professors);
    Clear_List(group_student,size);
    delete[]group_student;
    delete[]professors;
    return 0;
}
bool Find_Supervisor(Professors* prof , Student* group_stud ,int SizeGroup , int SizeProf)
{
    if(prof == NULL || group_stud == NULL)return 0;
    Show_data(prof,SizeProf);
    for(int i = 0 ; i < SizeGroup ;i++)
    {
        int x;
        printf("Enter the number of the head of the list for the assignment of the supervisor of the student %s - " , group_stud[i].name);
        cin >> x;
        if(0 < x &&  x < SizeProf+1)
            group_stud[i].supervisor = &prof[x-1];
        else
            cout << "Error profesors - " << x << " : does not exist";
    }
    return 1;
}
bool ShowStudVs50oldSupervisopr(Student* group_stud, int SizeGroup){
    if(group_stud == NULL)return 0;
    for(int i = 0 ; i < SizeGroup ;i++)
    {
       // cout << " Number operasion - " << i << endl;
        if(group_stud[i].supervisor == NULL ) return 0;
        if(group_stud[i].supervisor->age > 50){Show_data(&group_stud[i]);printf("Age supervisera = %i \n",group_stud[i].supervisor->age);}
    }
    cout << __FUNCTION__ << " - Exit" << endl;
    return 1;
}
float average_mark(Student* group_stud, int SizeGroup){
    if(group_stud == NULL || SizeGroup == 0)return -1;
    float S = 0;
    float Sred;
    for(int i = 0 ; i < SizeGroup; i++ )
    {
        S+=group_stud[i].gpa;
        printf("group_stud[%i].gpa = %0.2f\n",i+1,group_stud[i].gpa);
    }
    Sred = S / SizeGroup;
    return Sred;
}
Student *BadStudent(Student* group_stud, int SizeGroup){
    if(group_stud == NULL || SizeGroup == 0)return 0;
    Student *bad = group_stud;
    for(int i = 0 ; i < SizeGroup;i++)
    {
       if(group_stud[i].gpa < bad->gpa)
           bad = &(group_stud[i]);
    }
    return bad;
}
Student *GoodStudent(Student* group_stud , int SizeGroup){
    if(group_stud == NULL || SizeGroup == 0)return 0;//если не был создан список студентов то вернуть 0
    Student *good = group_stud;
    for(int i = 0 ; i < SizeGroup;i++)
    {
       if(group_stud[i].gpa > good->gpa)
           good = &(group_stud[i]);
    }
    return good;
}
bool Init_Data(Student* group_stud,int SizeGroup){

    if( group_stud != NULL && group_stud->age != 0 )return false;

    for(int i = 0 ; i < SizeGroup ; i++){
        printf("Input name of student\n");
        scanf("%s",group_stud[i].name);
        printf("Input age of student\n");
        scanf("%i",&group_stud[i].age);
        printf("Input gpa of student\n");
        scanf("%f",&group_stud[i].gpa);
        printf("/*********************/\n");
    }
    return true;
}
bool Init_Data(Professors* prof,int SizeProf){

    if( prof != NULL && prof->age != 0 )return false;//если уже есть список студентов то вернуть false

    for(int i = 0 ; i < SizeProf ; i++){
        printf("Input name of professor\n");
        scanf("%s",prof[i].name);
        printf("Input age of professor\n");
        scanf("%i",&prof[i].age);
        printf("Input salary of professor\n");
        scanf("%u",&prof[i].salary);
        printf("/*********************/\n");
    }

    return true;
}
bool Show_data(Student* group_stud)
{
    if(group_stud == NULL)return 0;
    printf("Name of student - %s\n",group_stud->name);
    printf("He is %i years old\n",group_stud->age);
    printf("gpa of student - %0.2f\n",group_stud->gpa);
    if(group_stud->supervisor != NULL){printf("Superviser of student - %s\n",group_stud->supervisor->name);}
    printf("/*********************/\n");
    return 1;
}
bool Show_data(Student* group_stud ,int SizeGroup)
{
    if(group_stud == NULL || SizeGroup == 0)return 0;
    printf("/****Data of students ***/\n");
    for(int i = 0 ; i < SizeGroup ; i++){
        printf("Name of student - %s\n",group_stud[i].name);
        printf("He is %i years old\n",group_stud[i].age);
        printf("gpa of student - %0.2f\n",group_stud[i].gpa);
        if(group_stud[i].supervisor != NULL)printf("Superviser of student - %s\n",group_stud[i].supervisor->name);
        printf("/*********************/\n");
    }
    return 1;
}
bool Show_data(Professors* prof)
{
    if(prof == NULL)return 0;
    printf("Name of professor - %s\n",prof->name);
    printf("He is %i years old\n",prof->age);
    printf("Salary of professor - %u\n",prof->salary);
    printf("/*********************/\n");
    return 1;
}
bool Show_data(Professors* prof ,int SizeProf)
{
    if(prof == NULL ||  SizeProf == 0)return 0;
    printf("/****Data of students ***/\n");
    for(int i = 0 ; i < SizeProf ; i++){
        printf("%i:  " , i+1);
        printf("Name of professor - %s\n",prof[i].name);
        printf("He is %i years old\n",prof[i].age);
        printf("Salary of professor - %u\n",prof[i].salary);
        printf("/*********************/\n");
    }
    return 1;
}
bool Clear_List(Student* group_stud,int SizeGroup)
{
    if(group_stud == NULL || SizeGroup == 0)return 0;
    for(int i = 0 ; i < SizeGroup  ; i++)
    {
        group_stud[i].Clear();
    }
    return 1;
}
bool Clear_List(Professors* prof,int SizeProf)
{
    if(prof == NULL || SizeProf == 0)return 0;
    for(int i = 0 ; i < SizeProf  ; i++)
    {
        prof[i].Clear();
    }
    return 1;
}
