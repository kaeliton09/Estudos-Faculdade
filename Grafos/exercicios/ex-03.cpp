#include <bits\stdc++.h>
using namespace std;

int main() {
    vector<vector<int> > vertices;
    int quantidadeVertices = 0;
    do {
        cout << "digite a quantidade de vertices: ";
        cin >> quantidadeVertices;
        if (quantidadeVertices < 1) {
            cout << "quantidade de vertices deve ser maior que 1" << endl;
        }
    }while (quantidadeVertices < 1);

    //criando matriz de vertices (cada linha eh uma lista de vertices adjacentes)
    for (int i = 0; i < quantidadeVertices; i++) {
        vertices.push_back(vector<int>());
    }

    //alocacao da matriz de adjacencia
    int **matAdj = new int*[quantidadeVertices];//alocando linhas
    for (int i = 0; i < quantidadeVertices; i++) {
        matAdj[i] = new int[quantidadeVertices]();//alocando colunas
    }

    for (int i = 0; i < quantidadeVertices; i++) {
        int adjacente = 1;
        while (adjacente != -1) {
            bool jacontem = false;
            cout << "digite o vertice adjacente a (-1 para parar) " << i+1 << " : ";
            cin >> adjacente;
            if (adjacente == -1) {
                break;
            }
            if ((adjacente < 1 || adjacente > quantidadeVertices)) {
                cout << "vertice adjacente invalido!" << endl;
                continue;
            }
            for (int j = 0; j < vertices[i].size(); j++) {
                if (adjacente == vertices[i][j]) {jacontem = true;}
            }
            if (jacontem) {
                cout << "vertice adjacente invalido (ja esta na lista)!" << endl;
                continue;
            }
            if (!jacontem) vertices[i].push_back(adjacente);
        }
    }

    cout << "- - - LISTAS DE ADJACENCIAS - - -" << endl;
    for (int i = 0; i < quantidadeVertices; i++) {
        cout << i+1 << "| ";
        sort(vertices[i].begin(), vertices[i].end());
        for (int j = 0; j < vertices[i].size(); j++) {
            cout << vertices[i][j] << " ";
            matAdj[i][--vertices[i][j]] = 1;
        }
        cout << endl;
    }

    cout << "- - - MATRIZ DE ADJACENCIA - - -" << endl;
    for (int i = -1; i < quantidadeVertices; i++) {
        if (i != -1)cout << "v"<<i+1 << "|";
        else cout << "  |";
        for(int j = 0; j < quantidadeVertices; j++) {
            if (i == -1) cout << "v" << j+1<< " ";
            else {
                cout<< " " << matAdj[i][j] <<" ";
            }
        }
        cout<<endl;
    }

}