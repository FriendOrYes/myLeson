#include <iostream>

using namespace std;

void InitMatrix(int** const firstMatrix, const int rows ,const int columns)
{
    for(int i = 0; i < rows; i++)
    {
        cout << "Row - " << i + 1 <<endl;
        
        firstMatrix[i] = new int[columns];
        
        for(int j = 0; j < columns; j++)
        {
            cin >> firstMatrix[i][j];
        }
    }
}
//-----------------------------------------------------------------------------------------------------
void TurnMatrix90Degrees(int** const firstMatrix,int **& secondMatrix,const int rows,const int columns )
{
    for(int i = 0; i < columns; i++)
    {
        secondMatrix[i] = new int[rows];
        for(int j = 0; j < rows; ++j)
        {
            secondMatrix[i][j] = firstMatrix[rows-j-1][i];
        }
    }
}
/// 111 321
/// 222 321
/// 333 321
//--------------------------------------------------------------------------------------------------------
void PrintMatrix(int **const x , const int rows,const int columns )
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout  << x[i][j] << " ";
        }
        cout << endl;
    }
}
//------------------------------------------------------------------
void FreeMemory(int**& x ,const int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete[]x[i];
    }

    x = nullptr;
}
//-----------------------------------------------------------------------
int main(int argc, char *argv[])
{
    int rows , columns;
    cin >> rows >> columns;
    int **firstMatrix = new int*[rows];
    int **secondMatrix = new int*[columns];

    InitMatrix(firstMatrix,rows,columns);
    TurnMatrix90Degrees(firstMatrix,secondMatrix,rows,columns);

    cout << "Matrix :" << endl;
    PrintMatrix(firstMatrix,rows,columns);

    cout << "New Matrix :" << endl;
    PrintMatrix(secondMatrix,rows,columns);

    FreeMemory(firstMatrix,rows);
    FreeMemory(secondMatrix,columns);

    return 0;
}
