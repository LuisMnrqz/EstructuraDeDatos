//A01242473 Luis Alberto Manriquez Valle
//Tarea 3, ACMICP Score

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct datos{
	string nombreEquipo;
	int acc;
	int time;
	int wa[10];
};

bool compare(datos d1, datos d2)
{
	if (d1.acc == d2.acc)
	{
		return d1.time < d2.time;
	}

	else if (d1.acc != d2.acc)
	{
		return d1.acc > d2.acc;
	}
}

int main() {

    //SAMPLE INPUT
    //5 2......................Numero de equipos / Numero de problemas
    //UNO........
    //DOS........
    //TRES.....................Nombre de cada equipo
    //CUATRO.....
    //CINCO......
    //7.......................Numero de problemas resueltos
    //TRES A 15 A......
    //CUATRO A 18 W....
    //CINCO B 20 A.....
    //CUATRO A 20 A...........Nombre de equipo / problema / tiempo / estatus problema (A = aceptado, W =incorrecto (+20 tiempo por cada envio incorrecto))
    //CINCO A 25 A.....
    //TRES B 32 A......
    //DOS B 38 A.......

    //SAMPLE OUTPUT
    //1 - CINCO 2 45......
    //2 - TRES 2 47.......
    //3 - DOS 1 38................Lugar / - / Nombre del equipo / Numero de problemas totales aceptados / Tiempo total(Si no se acepto ningun problema imprimir '-')
    //4 - CUATRO 1 40.....
    //5 - UNO 0 -.........

    //Variables
    int numEquipos, numProblemas, numEnvios, tmpo;
	char prob, estatusProb;
    string nomEquipo;
	
	vector<datos> equipos(20);

	//Input: Numero de equipos / Numero de problemas
	cin >> numEquipos >> numProblemas;

	//Input: Nombre de los equipos y asignacion de 0 a los demas valores del struct
	for (int i = 0; i < numEquipos; i++)
	{
		//cin >> nomEquipo;
		cin >> equipos[i].nombreEquipo;
		equipos[i].acc = 0;
		equipos[i].time = 0;
		for (int j = 0; j < 10; j++)
		{
			equipos[i].wa[j] = 0;
		}
	}

	//Input: Numero de soluciones enviadas
	cin >> numEnvios;

	for (int i = 0; i < numEnvios; i++)
	{
		cin >> nomEquipo >> prob >> tmpo >> estatusProb;

		for (int j = 0; j < numEquipos; j++)
		{
			if(nomEquipo == equipos[j].nombreEquipo)
			{
				if (estatusProb == 'W')
				{
					equipos[j].wa[prob-'A']++; 
				}
				else
				{
					equipos[j].acc++;
					equipos[j].time += (tmpo + equipos[j].wa[prob - 'A'] * 20);
				}
			}
		}
	}

	//Sort
	sort (equipos.begin(), equipos.begin()+numEquipos, compare);

    //Imrpimir tabla final de resultados
	for (int i = 0; i < numEquipos; i++)
	{
		cout << i + 1 << " - " << equipos[i].nombreEquipo << " ";
		cout << equipos[i].acc << " ";

		if (equipos[i].time == 0)
		{
			cout << "-" << endl;
		}

		else 
		{
			cout << equipos[i].time << endl;
		}
	}
	return 0;
}