#include "NodoSimples.h"



NodoSimples::NodoSimples(){
	prox = NULL;
}
NodoSimples::NodoSimples(Presente &p){
	item.copia(p);
	prox = NULL;
}

NodoSimples::~NodoSimples(){

}
Presente NodoSimples::getItem(){
	return item;
}
void NodoSimples::setProx(NodoSimples*p){
	prox = p;
}
void NodoSimples::setItem(Presente outro){
	item = outro;
}
NodoSimples* NodoSimples::getProx(){
	return prox;
}