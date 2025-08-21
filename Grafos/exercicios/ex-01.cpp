#include <bits\stdc++.h>
using namespace std;

bool isSimetrica(int **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] != matriz[j][i]) return false;//mat[i][j] != mat[j][i] logo nao e simetrica
        }
    }
    return true;
}

void imprimeMatriz(int **matriz, int n){
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

int main(){
    int numVertices = 0;
    cout << "digite a quantidade vertices que contem no grafo: ";
    do {
        cin >> numVertices;
        if (numVertices < 1) {
            cout << "Numero de vertices invalido!" << endl;
        }
    }while (numVertices < 1);


    int **matAdj = new int*[numVertices];//alocando linhas da matriz
    for (int i = 0; i < numVertices; i++) {
        matAdj[i] = new int[numVertices];//alocando colunas da matriz
    }



    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            do{
                cout << "digite se o vertice tem ligacao na posicao ["<< i+1 <<"]["<< j+1 <<"]" << endl;
                cout << "use (1) para sim ou (0) para nao: ";
                cin >> matAdj[i][j];
                if (matAdj[i][j] != 1 && matAdj[i][j] != 0) {
                    cout << "numero invalido!" << endl;
                }
            }while (matAdj[i][j] != 1 && matAdj[i][j] != 0); 
        }
    }
    
    if(isSimetrica(matAdj, numVertices)){//matriz esta correta
        imprimeMatriz(matAdj, numVertices);
        for (int i = 0; i < numVertices; i++) {
            int grauVertice = 0;
            for (int j = 0; j < numVertices; j++) {
                grauVertice += matAdj[i][j];
            }
            cout << "grau do vertice "<< i + 1 << ": " << grauVertice << endl;
        }
    }else {//matriz nao representa um grafo
        imprimeMatriz(matAdj, numVertices);
        cout << "a matriz nao e simetrica. logo nao representa um grafo nao direcionado" << endl;
    }
}