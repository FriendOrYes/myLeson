#include <iostream>

using namespace std;
int** Matrix(int **x,int **x2, int n ,int m)
{
    for(int i = 0 ; i < n;i++)
    {
        x[i] = new int[m];
    }
    for(int i = 0 ; i < n;i++)
    {
        cout << "Row - " << i+1 <<endl;
        for(int j = 0 ; j < m;j++)
        {
            cin >> x[i][j];
        }
    }
    for(int i = 0 ; i < m;i++)
    {
        x2[i] = new int[n];
        for(int j = 0 ; j < n;j++)
        {
            x2[i][j] = x[j][i];
        }
    }
    return x2;
}
int main(int argc, char *argv[])
{
    int n , m;
    cin >> n >> m;
    int **x = new int*[m];
    int **x2 = new int*[n];
    x2 = Matrix(x,x2,n,m);
    cout << "Matrix :" << endl;
    for(int i = 0 ; i < n;i++)
    {
        for(int j = 0 ; j < m;j++)
        {
            cout  << x[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "New Matrix :" << endl;
    for(int i = 0 ; i < m;i++)
    {
        for(int j = 0 ; j < n;j++)
        {
            cout  << x2[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0 ; i < n;i++)
    {
        delete[]x[i];
    }
    for(int i = 0 ; i < m;i++)
    {
        delete[]x2[i];
    }
    cout << "Hello World!" << endl;
    return 0;
}
