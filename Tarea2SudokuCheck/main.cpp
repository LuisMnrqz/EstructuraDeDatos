//A01242473 Luis Alberto Manriquez Valle
//Tarea 2, Sudoku Check
#include <iostream>

using namespace std;

//i = n columna
//j = n comp
//k = n linea
bool checkColumna(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (sudoku[j][i] == sudoku[k][i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//i = n linea
//j = n comp
//k = n columna
bool checkLinea(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = j + 1; k < 9; k++)
            {
                if (sudoku[i][j] == sudoku[i][k])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//i = indice linea
//j = indice columna

//3 x 3
// 1 2 3
// 4 5 6 -> Sumatoria de submatriz (1+2+3+4+5+6+7+8+9) = 45
// 7 8 9
bool checkSubMat(int sudoku[9][9])
{
    int mat;
    for (int i = 0; i <= 6; i += 3)
    {
        for (int j = 0; j <= 6; j += 3)
        {
            mat = 0;
            for (int c = i; c < i + 3; c++)
            {
                for (int k = j; k < j + 3; k++)
                {
                    mat += sudoku[c][k];
                }
            }
            if (mat != 45)
            {
                return false;
            }
        }
    }
    return true;
}

int main (){

    int sudoku[9][9];
    int n;

    //ingresar nums sudoku
    //i = linea 
    //j = columna
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> n;
            sudoku[i][j] = n; 
        }
    }

    if (checkLinea(sudoku) == true && checkColumna(sudoku) == true && checkSubMat(sudoku) == true)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}