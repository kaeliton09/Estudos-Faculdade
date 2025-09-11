#include <bits/stdc++.h>

using namespace std;

//funcao para verificar se o grafi é simples
bool isSimples(vector<vector<int> > & grafo, int numeroVertices) {
    for (int i = 0; i < numeroVertices; i++) {
        for (int j = 0; j < grafo[i].size(); j++) {//verificando se o grafo possui laco
            if (grafo[i][j] == i + 1) return false;
        }
    }
    return true;
}

//funcao para verficar se o grafo é um ciclo
bool isCiclo(vector<vector<int> > & grafo, int numeroVertices) {
    if (numeroVertices < 3) return false;
    for (int i = 0; i < numeroVertices; i++) {
        if (grafo[i].size() != 2) return false;
    }
    return true;
}

//funcao para verificar se o grafo é completo
bool isCompleto(vector<vector<int> > & grafo, int numeroVertices) {
    int grauEsperado = numeroVertices -1;
    for (int i = 0; i < grauEsperado; i++) {
        if (grafo[i].size() != grauEsperado) return false;
    }
    return true;
}

//funcao para verificar se o grafo é roda
bool isRoda(vector<vector<int> > & grafo, int numeroVertices) {
    if (numeroVertices < 4) return false;
    int numeroVerticesGrauMinino = numeroVertices - 1;
    int numeroVerticesGraumaximo = 0;
    for (int i = 0; i < numeroVertices; i++) {
        if (grafo[i].size() == 3) numeroVerticesGrauMinino--;
        if (grafo[i].size() == numeroVertices-1) numeroVerticesGraumaximo++;
    }
    if (numeroVerticesGraumaximo == 1 && numeroVerticesGrauMinino == 0) return true;
    return false;
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
        if (isCiclo(grafo, numeroVertices)) cout << "o grafo eh um ciclo." << endl;
        else if (isCompleto(grafo, numeroVertices)) cout << "o grafo eh um completo." << endl;
        else if (isRoda(grafo, numeroVertices)) cout << "o grafo eh uma roda." << endl;
        else cout << "o grafo nao eh um ciclo, completo e nem roda." << endl;
    }else cout << "o grafo nao eh simples." << endl;



    return 0;
}