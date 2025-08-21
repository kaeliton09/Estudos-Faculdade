#include <bits\stdc++.h>
using namespace std;

bool validacaoMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < colunas; i++) {
        int quantidadeDeMenosUM = 0;
        int quantidadeDeUm = 0;
        int quantidadeDeDois = 0;
        for (int j = 0; j < linhas; j++) {
            if (matriz[j][i] == 1) {quantidadeDeUm++;}
            if (matriz[j][i] == -1) {quantidadeDeMenosUM++;}
            if (matriz[j][i] == 2) {quantidadeDeDois++;}
        }
        if (quantidadeDeUm != 1 && quantidadeDeMenosUM != 1 && quantidadeDeDois != 1) {return false;}
    }
    return true;
}

void imprimeMatrizAdjacencia(int **matriz, int n){
    cout<<"- - - Matriz de Adjacencia - - -"<<endl;
    for(int i = -1; i < n; i++) {
        if (i != -1)cout << "v"<<i+1 << "|";
        else cout << "  |";
        for(int j = 0; j < n; j++) {
            if (i == -1) cout << "v" << j+1<< " ";
            else {
                    cout<< " " << matriz[i][j] <<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void imprimeMatrizIncidencia(int **matriz, int linhas, int colunas){
    cout<<"- - - Matriz de Incidencia - - -"<<endl;
    for(int i = -1; i < linhas; i++) {
        if (i != -1)cout << "v"<<i+1 << "|";
        else cout << "  |";
        for(int j = 0; j < colunas; j++) {
            if (i == -1) cout << "e" << j+1<< " ";
            else {
                if(matriz[i][j] != -1) {
                    cout<< " " << matriz[i][j]<<" ";
                }else {
                    cout<<matriz[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void tranformacaoMatriz(int **matrizInc, int **matrizAdj, int linhas, int colunas) {
    for(int i = 0; i < colunas; i++) {
        int indiceLinha = 0;
        int indiceColuna = 0;
        for(int j = 0; j < linhas; j++) {
            if (matrizInc[j][i] == 1) {indiceLinha = j;}
            if (matrizInc[j][i] == -1) {indiceColuna = j;}
            if (matrizInc[j][i] == 2) {indiceLinha = j; indiceColuna = j;}
        }
        matrizAdj[indiceLinha][indiceColuna] = 1;
    }
}

void imprimeGrausEntradaSaida(int ** matriz, int linhas, int colunas) {
    cout<<endl;
    cout << "- - - Graus de Entrada e Saida - - - "<<endl;
    for(int i = 0; i < linhas; i++) {
        int grauEntrada = 0;
        int grauSaida = 0;
        for(int j = 0; j < colunas; j++) {
            if (matriz[i][j] == -1) {grauEntrada++;}
            if (matriz[i][j] == 1) {grauSaida++;}
            if (matriz[i][j] == 2) {grauEntrada++; grauSaida++;}
        }
        cout << "v" << i+1 << " - Entrada: " << grauEntrada << " | Saida: " << grauSaida << endl;
    }
    cout<<endl;
}

int main() {
    int numVertices;
    int numArestas;
    cout << "Digite o numero de vertices: ";
    do {
        cin >> numVertices;
        if (numVertices < 1) {
            cout << "Numero de vertices invalido!" << endl;
        }
    }while (numVertices < 1);


    cout << "Digite o numero de aretas: ";
    do {
        cin >> numArestas;
        if (numArestas < 1) {
            cout << "Numero de arestas invalido!" << endl;
        }
    }while (numArestas < 1);

    //alocacao da matriz incidencia
    int **matInc = new int*[numVertices];//alocando linhas (vertices)
    for (int i = 0; i < numVertices; i++) {
        matInc[i] = new int[numArestas];//alocando colunas (arestas)
    }

    //alocacao da matriz de adjacencia
    int **matAdj = new int*[numVertices];//alocando linhas
    for (int i = 0; i < numVertices; i++) {
        matAdj[i] = new int[numVertices]();//alocando colunas
    }

    /*
    //zerando matriz de adjacencia
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matAdj[i][j] = 0;
        }
    }*/

    for (int i = 0; i < numArestas; i++) {
        for (int j = 0; j < numVertices; j++) {
            do {
                cout << "digite a na posicao [" << j+1 << "][" << i+1 <<"]" << endl;
                cout << "use (-1) para chegada da aresta no vertice, (1) para saida da aresta no vertice ou (2) para laco: ";
                cin >> matInc[j][i];
                if (matInc[j][i] != -1 && matInc[j][i] != 1 && matInc[j][i] != 0 && matInc[j][i] != 2) {
                    cout << "numero invalido!";
                }
            }while (matInc[j][i] != -1 && matInc[j][i] != 1 && matInc[j][i] != 0 && matInc[j][i] != 2);
        }
    }

    if (validacaoMatriz(matInc, numVertices, numArestas)) {
        imprimeMatrizIncidencia(matInc, numVertices, numArestas);
        imprimeGrausEntradaSaida(matInc, numVertices, numArestas);
        tranformacaoMatriz(matInc, matAdj, numVertices, numArestas);
        imprimeMatrizAdjacencia(matAdj,numVertices);
    }else {
        imprimeMatrizIncidencia(matInc, numVertices, numArestas);
        cout << "matriz invalida!";
    }

    return 0;
}
