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

bool arvoresIguais(NoArvore* raiz1, NoArvore* raiz2){

    if(raiz1 == NULL && raiz2 == NULL){
        return true;
    }

    if(raiz1 != NULL && raiz2 != NULL){
        (raiz1 -> key == raiz2 -> key && arvoresIguais(raiz1 -> esquerda, raiz2 -> esquerda) && arvoresIguais(raiz1 -> direita, raiz2 -> direita));
        return 1;
    }

    return 0;
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){

    NoArvore* raiz1 = NULL;
    NoArvore* raiz2 = NULL;

    raiz1 = inserirNo(1);
    raiz1 -> esquerda = inserirNo(2);
    raiz1 -> direita = inserirNo(3);

    raiz2 = inserirNo(1);
    raiz2 -> esquerda = inserirNo(2);
    raiz2 -> direita = inserirNo(3);

    listar(raiz1);
    listar(raiz2);

    bool resultado = arvoresIguais(raiz1, raiz2); 

    cout << endl << resultado;

    return 0;
}