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

NoArvore *merge(NoArvore *raiz1, NoArvore *raiz2){
    if (raiz1 == NULL){
        return raiz2;
    }
    if (raiz2 == NULL){
        return raiz1;
    }

    NoArvore *novoNo = inserirNo(raiz1->key + raiz2->key);

    novoNo->esquerda = merge(raiz1->esquerda, raiz2->esquerda);
    novoNo->direita = merge(raiz1->direita, raiz2->direita);

    return novoNo;
}


void listar(NoArvore *&raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){
	
	NoArvore *raiz1 = inserirNo (1);
    raiz1->esquerda = inserirNo(5);
    raiz1->direita = inserirNo(3);
    raiz1->esquerda->esquerda = inserirNo(2);
    listar(raiz1);  
    cout << endl;

    NoArvore *raiz2 = inserirNo (4);
    raiz2->esquerda = inserirNo(7);
    raiz2->direita = inserirNo(9);
    raiz2->esquerda->direita = inserirNo(1);
    raiz2->direita->direita = inserirNo(8);
    listar(raiz2);  
    cout << endl;

    NoArvore *mergeArvore = merge(raiz1,raiz2);
    listar(mergeArvore);

    return 0;
}