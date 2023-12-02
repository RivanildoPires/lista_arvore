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

int altura(NoArvore *raiz){
    if(raiz == NULL){
        return 0;
    }
    
	return 1+max(altura(raiz->esquerda), altura(raiz->direita));
	
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

    cout << endl << altura(raiz);
}
