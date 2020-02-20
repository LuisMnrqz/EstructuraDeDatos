//A01242473 Luis Alberto Manriquez Valle
//Tarea 1, Girar la matriz
#include <iostream>

using namespace std;

void leeMatriz(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void despliegaMatriz(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << mat[i][3] << endl;
    }
}

int main() {
    int vueltas;
    int mat[4][4];
    cin >> vueltas;
    leeMatriz(mat);


    //proceso
    for (int i = 0; i < 4 ; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (vueltas % 4 == 0)
            {
                cout << mat[i][j];
            }

            else if (vueltas % 4 == 1|| vueltas % 4 == -3)
            {
                cout << mat[(4 - 1) - j][i];
            }

            else if (vueltas % 4 == 2|| vueltas % 4 == -2)
            {
                cout << mat[(4 - 1) - i][(4 - 1) - j];
            }

            else if (vueltas % 4 == 3 || vueltas % 4 == -1)
            {
                cout << mat[j][(4 - 1) - i];
            }

            if (j < (4 - 1))
            {
                cout << " ";
            }
        }
        cout << endl;
        if (i == 4)
        {
            break;
        }
    } 

    //despliegaMatriz(mat);
    return 0;
}