#ifndef Priority_h
#define Priority_h

#include <iostream>
#include <vector>

using namespace std;

class Priority {
    public:
        Priority();
		Priority(bool p);
		void push(int dato);
		void pop();
		int top();
		bool empty();
		int size();
		void print();
    private:
        vector<int> datos;
		bool prioridad;
		bool compPadre(int pos);
		int compHijo(int pos);
};

Priority::Priority(){
	datos.push_back(0);
	prioridad = true;
}

Priority::Priority(bool p){
	datos.push_back(0);
	prioridad = p;
}

int Priority::size(){
	return datos.size() - 1;
}

int Priority::top(){
	return datos[1];
}

bool Priority::empty(){
	return datos.size() == 1;
}

// Regresa la posicion del hijo con el cual vas a intercambiar
// o -1 si no hay que hacer intercambio
// Comparar y regresar
int Priority::compHijo(int pos){
	// Si no hay hijo regresar -1
	if (datos[pos * 2] && datos[pos * 2 + 1] == 0){
		return -1;
	}

	// Tener cuidado si solo hay 1 hijo
	if (datos[pos * 2] != 0 && datos[pos * 2 + 1] == 0){
		return pos * 2;
	}

	else if (datos[pos * 2] == 0 && datos[pos * 2 + 1] != 0){
		return pos * 2 + 1;
	}

	// Si hay 2 hijos buscar el mayor o el menor
	if (prioridad){
		return (datos[pos * 2] > datos[pos * 2 + 1]) ? pos * 2 : pos * 2 + 1;
	}

	else
	{
		return (datos[pos * 2] < datos[pos * 2 + 1]) ? pos * 2 : pos * 2 + 1;
	}
}

void Priority::pop(){
	datos[1] = datos[datos.size() - 1];
	datos.pop_back();
	// REACOMODO HACIA ABAJO SEGUN LA PRIORIDAD
	// prioridad = mayor , !prioridad = menor
	int i = 1, hijos = i * 2;

	if (prioridad){
		while (compHijo(i) != -1 && hijos <= datos.size() - 1){
			int hijoMayor = compHijo(i);
			if (datos[hijoMayor] > datos[i]){
				int aux = datos[i];
				datos[i] = datos[hijoMayor];
				datos[hijoMayor] = aux;
			}
			i = hijoMayor;
			hijos = i * 2;
		}
	}

	else
	{
		while (compHijo(i) != -1 && hijos <= datos.size() - 1){
			int hijoMenor = compHijo(i);
			if (datos[hijoMenor] < datos[i]){
				int aux = datos[i];
				datos[i] = datos[hijoMenor];
				datos[hijoMenor] = aux;
			}
			i = hijoMenor;
			hijos = i * 2;
		}
	}
}

// True o False si hay que intercambiar
bool Priority::compPadre(int pos){
	if (pos == 1){
		return false;
	}

	if (prioridad){
		return datos[pos] > datos[pos / 2];
	}

	else
    {
		return datos[pos] < datos[pos / 2];
	}
}

void Priority::push(int dato){
	datos.push_back(dato);
	// REACOMODO HACIA ARRIBA SEGÃšN LA PRIORIDAD
	int idx = datos.size() - 1;
	while (compPadre(idx)){
		int temp = datos[idx];
		datos[idx] = datos[idx / 2];
		datos[idx / 2] = temp;
		idx /= 2;
	}
}

void Priority::print(){
	for (int i = 1; i < datos.size(); i++){
		cout << datos[i] << " ";
	}
	cout << endl;
}

#endif