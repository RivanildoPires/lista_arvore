#include <iostream>

using namespace std;

struct NoArvore{
    int key;
    NoArvore* esquerda;
    NoArvore* direita;
};
NoArvore* insercaoBST(NoArvore *&raiz,int key){
   

   if(raiz == NULL){
    
    NoArvore* novoNo = new NoArvore;
    novoNo->key = key;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    raiz = novoNo;
    return novoNo;
}
    if(key > raiz -> key){
        raiz -> direita = insercaoBST(raiz -> direita, key);
    }

    if(key < raiz -> key){
        raiz -> esquerda = insercaoBST(raiz -> esquerda, key);
    }

    return raiz;
}

int valorMax(NoArvore* raiz){   
    NoArvore* atual = raiz;
    while (atual->direita != NULL){
        atual = atual->direita;
     
    }
    return (atual->key);
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        cout <<"Numero da chave: "<< raiz -> key  << " \n";
        listar(raiz->direita);
    }
}

int main(){
    
    NoArvore* raiz = NULL;
    
    insercaoBST(raiz,20);
    insercaoBST(raiz,10);
    insercaoBST(raiz,23);
    insercaoBST(raiz,18);
    insercaoBST(raiz,22);
    listar(raiz);

    cout << "Valor maximo na BST: " << valorMax(raiz);

    return 0;
}