#include <iostream>
using namespace std;

int main()
{

    int arr[3][3] = { 0 };
    int arr1[3][3] = { 0 };
    int arr2[3][3] = { 0 };


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++) {
            cout << "Matrix 1st [" << i << "][" << j << "]:\n";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Matrix 2nd [" << i << "][" << j << "]:\n";
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int n = 0; n < 3; n++) {
                arr2[i][j] += arr[i][n] * arr1[n][j];
            }
        }
    }
    cout << "Multiply of both matrix:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
