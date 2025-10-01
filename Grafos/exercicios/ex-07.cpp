#include <bits/stdc++.h>

using namespace std;

//funcao para verificar se o grafo é simples
bool isSimples(vector<vector<int> > & grafo, int numeroVertices) {
    for (int i = 0; i < numeroVertices; i++) {
        for (int j = 0; j < grafo[i].size(); j++) {//verificando se o grafo possui laco
            if (grafo[i][j] == i + 1) return false;
        }
    }

    return true;
}

bool elementoExiste(vector<int> jaVisitados, int elemento) {
    for (int i = 0; i < jaVisitados.size(); i++) {
        if (jaVisitados[i] == elemento) return true;
    }
    return false;
}

bool dfs(vector<vector<int>> &grafo, int inicio) {
    int n = grafo.size();
    vector<bool> visitados(n, false);
    stack<int> adjacentes;

    adjacentes.push(inicio);

    while (!adjacentes.empty())
    {
        int v = (adjacentes.top())-1;
        adjacentes.pop();
            for (int adj : grafo[v]) {
                visitados[v] = true;
                if (!visitados[adj-1]) {
                    adjacentes.push(adj);
                }else if (visitados[adj-1] && adj == inicio) {
                    return true;
                }
            }
    }
    return false;
}

int main() {
    vector<vector<int>> grafo = {
        {2},
        {3},
        {4, 6},
        {5},
        {2},
        {7},
        {}
    };


    int numeroVertices = 7;
    /*
    do {
        cout << "digite a quantidade de vertices: ";
        cin >> numeroVertices;
        if (numeroVertices < 1) {
            cout << "quantidade de vertices negativos invalida!" << endl;
        }
    } while (numeroVertices < 1);

    //criando matriz de vertices (cada linha eh uma lista de vertices adjacentes)
    for (int i = 0; i < numeroVertices; i++) {
        grafo.push_back(vector<int>());
    }

    //leitura do grafo
    for (int i = 0; i < numeroVertices; i++) {
        int adjacente = 0;
        while (adjacente != -1) {
            bool jacontem = false;
            cout << "digite o vertice adjacente a (-1 para parar) " << i+1 << " : ";
            cin >> adjacente;
            if (adjacente == -1) {
                break;
            }
            if ((adjacente < 1 || adjacente > numeroVertices)) {
                cout << "vertice adjacente invalido!" << endl;
                continue;
            }
            for (int j = 0; j < grafo[i].size(); j++) {
                if (adjacente == grafo[i][j]) {jacontem = true;}
            }
            if (jacontem) {
                cout << "vertice adjacente invalido (ja esta na lista)!" << endl;
                continue;
            }
            if (!jacontem) grafo[i].push_back(adjacente);
        }
    }
    */
    if (isSimples(grafo, numeroVertices)) {
        for (int i = 1; i <= numeroVertices; i++) {
            if (dfs(grafo, i)) {
                cout << i << ": tem ciclo!" << endl;
            } else {
                cout << i << ": nao tem ciclo!" << endl;
            }
        }
    }

    return 0;
}