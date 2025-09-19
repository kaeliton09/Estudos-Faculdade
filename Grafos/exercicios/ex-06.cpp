#include <bits/stdc++.h>

using namespace std;

bool isAdjacente (vector<int> v1, int valor) {
    for (int i : v1) {
        if (i == valor) return true;
    }
    return false;
}

//funcao simetria
bool isSImetrico(vector<vector<int> > & grafo, int numeroVertices) {
    for (int i = 0; i < numeroVertices; i++) {
        for (int j : grafo[i]) {
            if (!isAdjacente(grafo[j], i)) return false;
        }
    }
    return true;
}

//funcao para verificar se o grafo é simples
bool isSimples(vector<vector<int> > & grafo, int numeroVertices) {
    for (int i = 0; i < numeroVertices; i++) {
        for (int j = 0; j < grafo[i].size(); j++) {//verificando se o grafo possui laco
            if (grafo[i][j] == i + 1) return false;
        }
    }

    return true;
}

//funcao para verificar se o grafo e um ciclo euleriano
bool isCicloEulerino(vector<vector<int> > & grafo, int numeroVertices) {
    for (int i = 0; i < numeroVertices; i++) {
        if (grafo[i].size() % 2 != 0) return false;
    }
    return true;
}

//funcao para verificar se o grafo e um caminho euleriano
bool isCaminhoEureliano(vector<vector<int> > & grafo, int numeroVertices) {
    int quantidadeDeGrausImpares = 0;
    for (int i = 0; i < numeroVertices; i++) {
        if (grafo[i].size() % 2 != 0) quantidadeDeGrausImpares++;
    }
    if (quantidadeDeGrausImpares != 2) return false;
    return true;
}

int main() {
    vector<vector<int> > grafo;
    int numeroVertices = 0;
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
    if (isSimples(grafo, numeroVertices)) {
        if (isCicloEulerino(grafo, numeroVertices)) cout << "Ciclo eulerino!" << endl;
        if (isCaminhoEureliano(grafo, numeroVertices)) cout << "Caminho eulerino!" << endl;
    }else cout << "o grafo nao eh simples." << endl;


    return 0;
}