#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define N 10

void iniMatAdj(bool matAdj[N][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			matAdj[i][j] = false;
		}
	}
}

void BFS(bool matAdj[N][N], int n){
    queue<int> fila;
    int arranque;
    cin >> arranque;
    fila.push(arranque - 1);
    vector<bool> status(n, false);
    status[arranque - 1] = true;
    int dato;
    while (!fila.empty()){
        dato = fila.front();
        cout << (dato + 1) << " ";
        fila.pop();
        // checar en el renglón dato de la matAdj que col tiene True
        // y luego checar el status de esa columna par ver si no ha sido procesada
        for (int j = 0; j < n; j++){
            if (matAdj[dato][j] && !status[j]){
                fila.push(j);
                status[j] = true;
            }
        }
    }
    cout << endl;
}

void leeMatAdj(bool matAdj[N][N], int m){
	int a, b;
	for (int i = 1; i <= m; i++){
		cin >> a >> b;
		matAdj[a - 1][b - 1] = matAdj[b - 1][a - 1] = true;
	}
}

void printMatAdj(bool matAdj[N][N], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << (matAdj[i][j]) << " ";
		}
		cout << endl;
	}
}
int main(){
	bool matAdj[N][N];
	int n, m;
	// n = cantidad de Nodos
	// m = cantidad de Arcos
	cin >> n >> m;
	iniMatAdj(matAdj);
	leeMatAdj(matAdj, m);
	printMatAdj(matAdj, n);
    //	BFS(matAdj, n);
	return 0;
}

/*
7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7


7 6
1 2
2 3  
2 5
3 4
4 6
5 7
*/