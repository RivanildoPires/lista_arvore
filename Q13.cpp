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
bool verificar(NoArvore *&raiz){
    if(raiz == NULL){
        return false;
    }

    int soma = 0;

    if(raiz->esquerda != NULL){
        soma += raiz->esquerda->key;
    }

    if(raiz->direita != NULL){
        soma += raiz->direita->key;
    }
    return soma == raiz->key;
}


void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->key << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}

int main(){
	
	NoArvore* raiz = inserirNo (10);
    raiz->esquerda = inserirNo(4);
    raiz->direita = inserirNo(6);
    listar(raiz);
    cout << endl;

    if(verificar(raiz)){
        cout << "True" << endl;
    }
    else{
        cout<< "False" << endl;
    }

    return 0;
}