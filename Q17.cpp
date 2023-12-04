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
int somaSub(NoArvore *raiz, int &maiorValor){
    if (raiz == NULL){
        return 0;
    }

    int somaEsquerda = somaSub(raiz->esquerda, maiorValor);
    int somaDireita = somaSub(raiz->direita, maiorValor);

    int valorSoma = raiz->key + somaEsquerda + somaDireita;

    maiorValor = max(maiorValor, valorSoma);

    return max(raiz->key, raiz->key + max(somaEsquerda, somaDireita));
}

int maxSub(NoArvore *raiz){
    int maiorValor = -1;
    somaSub(raiz, maiorValor);
    return maiorValor;
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
    raiz -> esquerda = inserirNo(4);
    raiz->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(2);
    raiz->direita->direita = inserirNo(5);
    raiz->direita->direita->esquerda = inserirNo(4);
    raiz->direita->direita->direita = inserirNo(6);
    listar(raiz);
    cout << endl;

    int maxSoma = maxSub(raiz);
    cout << maxSoma;

    return 0;
}