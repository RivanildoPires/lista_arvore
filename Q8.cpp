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

bool verificarBalanceada(NoArvore *raiz){ 
    if (raiz == NULL)
        return 1;
 

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
 
    if (alturaEsquerda - alturaDireita <= 1 && verificarBalanceada(raiz->esquerda)&& verificarBalanceada(raiz->direita)){
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
    
    NoArvore* raiz = inserirNo (1);
    raiz -> esquerda = inserirNo(5);
    raiz->direita = inserirNo(3);
    raiz->direita->esquerda = inserirNo(2);
    raiz->direita->direita = inserirNo(4);
    raiz->esquerda -> esquerda = inserirNo(7);
    raiz->esquerda -> esquerda -> esquerda = inserirNo(9);
    raiz->esquerda -> esquerda -> esquerda -> esquerda = inserirNo(10);
    listar(raiz);

    if(verificarBalanceada(raiz)){
    	
    	cout << "E balanceada\n";
	}else{
	
        cout << "Nao e balanceada!\n";
    }
}
