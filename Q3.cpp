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


void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        listar(raiz->direita);
        cout << raiz->key << " " ;
    }
}

int main(){
	
	NoArvore* raiz = inserirNo (1);
    raiz -> esquerda = NULL;
    raiz->direita = inserirNo(2);
    raiz->direita->esquerda = inserirNo(3);
    listar(raiz);

    return 0;
}