#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void leeListaAdj(vector<vector<int>> &listaAdj, int m){
    int a, b; // adj, nodo asosiado

    for(int i = 1; i <= m; ++i){
        cin >> a >> b;
        listaAdj[a - 1].push_back(b - 1);
        listaAdj[b-1].push_back(a - 1);
    }

}

void printListAdj(vector<vector<int>> &listaAdj){
    for(int i = 0; i < listaAdj.size(); i++){
        cout << (i + 1) << " ";
        for(int j = 0; listaAdj.size(); j++){
            cout << "-" << (listaAdj[i][j] + 1);
        }
    }
}

int main () {

    int n, m; // nodos, arcos

    cin  >> n >> m;

    vector<vector<int>> listaAdj(n);
    leeListaAdj(listaAdj, m);
    printListAdj(listaAdj);

    return 0;
}