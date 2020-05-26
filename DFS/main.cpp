#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void leeListaAdj(vector<vector<int>> &listaAdj, int m){
    int a, b; // adj, nodo asosiado

    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        listaAdj[a - 1].push_back(b - 1);
        listaAdj[b - 1].push_back(a - 1);
    }

}

void printListAdj(vector<vector<int>> &listaAdj){
    for (int i = 0; i < listaAdj.size(); i++){
        cout << (i + 1) << " ";
        for (int j = 0; listaAdj.size() < j; j++){
            cout << "-" << (listaAdj[i][j] + 1);
        }
        cout << endl;
    }
}

void DFS(vector<vector<int>> &listaAdj){
    stack<int> stack;
    int nodoInicial;

    cout << "Nodo inicial: ";
    cin >> nodoInicial;

    stack.push(nodoInicial - 1);

    vector<bool> status(listaAdj.size(), false);
    int contadorVisitados = 0;
    int dato; // nodo a procesar

    while(!stack.empty() && contadorVisitados != listaAdj.size()){ 
        dato = stack.top();
        stack.pop();

        // Verificar que no este procesado
        if (!status[dato]){
            status[dato] = true; // Nodo visitado
            contadorVisitados++;
            cout << (dato + 1) << "";

            for (int i = listaAdj[dato].size() - 1; i >= 0; --i){
                if (!status[listaAdj[dato][i]]){
                    stack.push(listaAdj[dato][i]);
                }
            }
        }
    }
}

int main () {

    int n, m; // nodos, arcos

    cin >> n >> m;

    vector<vector<int>> listaAdj(n);
    leeListaAdj(listaAdj, m);
    printListAdj(listaAdj);
    DFS(listaAdj);

    return 0;
}