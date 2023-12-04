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

void inverterArvore(NoArvore *raiz){
    if(raiz == NULL){
        return;
    }
    NoArvore *aux = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = aux;

    inverterArvore(raiz->esquerda);
    inverterArvore(raiz->direita);
}


void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){
	
	NoArvore* raiz = inserirNo (4);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(7);
    raiz->esquerda->esquerda = inserirNo(1);
    raiz->esquerda->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(6);
    raiz->direita->direita = inserirNo(9);
    listar(raiz);
    cout << endl;
    inverterArvore(raiz);
    listar(raiz);

    return 0;
}