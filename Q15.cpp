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

int somaNo(NoArvore *raiz){
    if (raiz == NULL){
        return 0;
    }

    if(raiz->esquerda == NULL && raiz->direita == NULL){
        return raiz->key;
    }

    return somaNo(raiz->esquerda) + somaNo(raiz->direita);
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
    raiz -> esquerda = NULL;
    raiz->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(2);
    listar(raiz);
    cout << endl;

    int soma = somaNo(raiz);
    cout << "Soma dos NOS: " << soma << endl;


    return 0;
}