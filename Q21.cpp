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

NoArvore* buscaBST(NoArvore *&raiz, int key) {
	if( raiz == NULL || raiz -> key == key) {
		return raiz;
	}
	
	if(key < raiz -> key) {
		return buscaBST(raiz -> esquerda, key);
	} else {
		return buscaBST(raiz -> direita, key);
	}
	
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        listar(raiz->esquerda);
        cout << raiz -> key  << " ";
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
    cout << endl;
    
    if(buscaBST(raiz, 10)==NULL){
        cout << "Chave nao encontrada" << endl;
    }else{
        cout << "Chave encontrada" << endl;
    }
    return 0;
}