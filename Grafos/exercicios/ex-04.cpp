#include <bits\stdc++.h>
using namespace std;

int quantidadeAresta(vector<vector<int> > & grafo, int n) {
    int arestas = 0;
    for (int i = 0; i < n; i++) {
        arestas += grafo[i].size();
    }
    return arestas;
}

bool temMesmosGraus(vector<int> &graus1, vector<int> &graus2) {
    for (int i = 0; i < graus1.size(); i++) {
        if (graus1[i] != graus2[i]) return false;
    }
    return true;
}

int main() {
    vector<vector<int> > grafo1;
    vector<vector<int> > grafo2;
    int quantidadeVerticesGrafo1 = 0;
    int quantidadeVerticesGrafo2 = 0;
    //lendo quantidade de vertices do grafo 1
    do {
        cout << "digite a quantidade de vertices do grafo 1: ";
        cin >> quantidadeVerticesGrafo1;
        if (quantidadeVerticesGrafo1 < 1) {
            cout << "quantidade de vertices deve ser maior que 1" << endl;
        }
    }while (quantidadeVerticesGrafo1 < 1);
    //lendo quandidade de vertices do grafo 2
    do {
        cout << "digite a quantidade de vertices do grafo 2: ";
        cin >> quantidadeVerticesGrafo2;
        if (quantidadeVerticesGrafo2 < 1) {
            cout << "quantidade de vertices deve ser maior que 1" << endl;
        }
    }while (quantidadeVerticesGrafo2 < 1);

    if (quantidadeVerticesGrafo1 == quantidadeVerticesGrafo2) {
        //criando matriz de vertices do grafo 1 (cada linha eh uma lista de vertices adjacentes)
        for (int i = 0; i < quantidadeVerticesGrafo1; i++) {
            grafo1.push_back(vector<int>());
        }

        //criando matriz de vertices do grafo 2 (cada linha eh uma lista de vertices adjacentes)
        for (int i = 0; i < quantidadeVerticesGrafo2; i++) {
            grafo2.push_back(vector<int>());
        }

        //alocacao da matriz de adjacencia grafo 1
        int **matAdjGrafo1 = new int*[quantidadeVerticesGrafo1];//alocando linhas
        for (int i = 0; i < quantidadeVerticesGrafo1; i++) {
            matAdjGrafo1[i] = new int[quantidadeVerticesGrafo1]();//alocando colunas
        }

        //alocacao da matriz de adjacencia grafo 2
        int **matAdjGrafo2 = new int*[quantidadeVerticesGrafo2];//alocando linhas
        for (int i = 0; i < quantidadeVerticesGrafo2; i++) {
            matAdjGrafo2[i] = new int[quantidadeVerticesGrafo2]();//alocando colunas
        }

        //lendo as listas de adjacencias do grafo 1
        cout << "Grafo 1: " << endl;
        for (int i = 0; i < quantidadeVerticesGrafo1; i++) {
            int adjacente = 1;
            while (adjacente != -1) {
                bool jacontem = false;
                cout << "digite o vertice adjacente a (-1 para parar) " << i+1 << " : ";
                cin >> adjacente;
                if (adjacente == -1) {
                    break;
                }
                if ((adjacente < 1 || adjacente > quantidadeVerticesGrafo1)) {
                    cout << "vertice adjacente invalido!" << endl;
                    continue;
                }
                for (int j = 0; j < grafo1[i].size(); j++) {
                    if (adjacente == grafo1[i][j]) {jacontem = true;}
                }
                if (jacontem) {
                    cout << "vertice adjacente invalido (ja esta na lista)!" << endl;
                    continue;
                }
                if (!jacontem) grafo1[i].push_back(adjacente);
            }
        }

        //lendo as listas de adjacencias do grafo 2
        cout << "Grafo 2: " << endl;
        for (int i = 0; i < quantidadeVerticesGrafo2; i++) {
            int adjacente = 1;
            while (adjacente != -1) {
                bool jacontem = false;
                cout << "digite o vertice adjacente a (-1 para parar) " << i+1 << " : ";
                cin >> adjacente;
                if (adjacente == -1) {
                    break;
                }
                if ((adjacente < 1 || adjacente > quantidadeVerticesGrafo2)) {
                    cout << "vertice adjacente invalido!" << endl;
                    continue;
                }
                for (int j = 0; j < grafo2[i].size(); j++) {
                    if (adjacente == grafo2[i][j]) {jacontem = true;}
                }
                if (jacontem) {
                    cout << "vertice adjacente invalido (ja esta na lista)!" << endl;
                    continue;
                }
                if (!jacontem) grafo2[i].push_back(adjacente);
            }
        }


        int quantidadeArestasGrafo1 = quantidadeAresta(grafo1, quantidadeVerticesGrafo1);
        int quantidadeArestasGrafo2 = quantidadeAresta(grafo2, quantidadeVerticesGrafo2);

        vector<int>grausGrafo1;
        for (int i = 0; i < quantidadeVerticesGrafo1; i++) {
            grausGrafo1.push_back(grafo1[i].size());
        }
        vector<int>grausGrafo2;
        for (int i = 0; i < quantidadeVerticesGrafo2; i++) {
            grausGrafo2.push_back(grafo2[i].size());
        }
        sort(grausGrafo1.begin(), grausGrafo1.end());
        sort(grausGrafo2.begin(), grausGrafo2.end());

        if (quantidadeVerticesGrafo1 == quantidadeVerticesGrafo2 && temMesmosGraus(grausGrafo1, grausGrafo2)) {
            cout << "os grafos podem isomorfos!" << endl;
        }else {
            cout << "os grafos nao podem ser isomorfos";
        }

    }else {
        cout << "os grafos nao podem ser isomorfos, pois tem quantidade de vertices diferentes" << endl;
    }

}
