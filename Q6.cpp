#include <iostream>

using namespace std;

struct NoArvore{
    int key;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* inserirNo(int value) {
    NoArvore* novoNo = new NoArvore;
    novoNo->key = value;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

int profudindade(NoArvore* raiz){
    if (raiz == NULL){
        return 0;
    }
    else{
        int esquerdaProfundidade = profudindade(raiz -> esquerda);
        int direitaProfundidade = profudindade(raiz -> direita);
        
        if(esquerdaProfundidade > direitaProfundidade){
            return(esquerdaProfundidade + 1);
            }
        else{
            return (direitaProfundidade + 1);
        }
    }
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){
    
    NoArvore* raiz = inserirNo (1);
    raiz -> esquerda = inserirNo(5);
    raiz->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(2);
    listar(raiz);

    cout << endl << profudindade(raiz);

    return 0;
}
