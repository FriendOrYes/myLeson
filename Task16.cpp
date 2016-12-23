#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void InitMas(int matrix[][3],const int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
             matrix[i][j] = rand()%10;
        }
    }
}

void PrintMas(int matrix[][3],const int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<< matrix[i][j] <<"\t";
        }
        cout << endl;
    }
}

int Determenant(int matrix[][3])
{
    int determenant = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + \
        matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - \
        matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];

    return determenant;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    const int size = 3;
    int mas[size][size];

    InitMas(mas, size);

    PrintMas(mas, size);
    cout << Determenant(mas);
    return 0;
}
