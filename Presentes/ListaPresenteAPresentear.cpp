#include "ListaPresenteAPresentear.h"
#include <iostream>
using namespace std;



ListaPresenteAPresentear::ListaPresenteAPresentear(){
	quant = 0;
	head = NULL;
}


ListaPresenteAPresentear::~ListaPresenteAPresentear()
{
}
NodoSimples* ListaPresenteAPresentear::getElemento(int n){
	NodoSimples* p = head;
	int j = 1;

	while (j < n && p->getProx() != NULL) {
		p = p->getProx();
		j++;
	}

	if (j == n)
		return p;
	else
		return NULL;

}
void ListaPresenteAPresentear::insert(Presente &p){
	NodoSimples *novo;
	novo = new NodoSimples(p);
	novo->setProx(head);
	head = novo;
	quant++;
}
void ListaPresenteAPresentear::remove(){
	head = head->getProx();
	quant--;
}
NodoSimples* ListaPresenteAPresentear::buscar(int idPresente){
	for (NodoSimples*p = head; p != NULL; p = p->getProx()){
		if (p->getItem().getId() == idPresente)
			return p;
	}

	return NULL;
}
void ListaPresenteAPresentear::remove(int idp){
	int contador = 1;
	for (NodoSimples*p = head; p != NULL; p = p->getProx()){
		if (p->getItem().getId() == idp){
			if (contador == 1)
				head = p->getProx();
			else{
			NodoSimples *ant = getElemento(contador - 1);
			ant->setProx(p->getProx());
		    }
		}
		contador++;
	}
}
void ListaPresenteAPresentear::imprimirlpp(){
	cout << "\t-------------- Lista de presentes a presentear  --------------\n";
	if (isEmpty()) {
		cout << "\tLista vazia\n";
	}
	else {
		NodoSimples* p = head;
		while (p != NULL){
			p->getItem().imprimir();
			p = p->getProx();
		}

	}
	cout << "\n\t------------------------------------------------------------\n";
}
bool ListaPresenteAPresentear::isEmpty(){
	if (quant == 0)
		return true;
	else
		return false;
}
void ListaPresenteAPresentear::imprimirIds(){
	if (isEmpty()) {
		cout << "\tLista vazia\n";
	}
	else {
		cout << "\tID dos presentes :" << endl;
		NodoSimples* p = head;
		while (p != NULL){
			cout << "ID : " << p->getItem().getId()<< endl;
			p = p->getProx();
		}

	}
}
NodoSimples* ListaPresenteAPresentear::getHead(){
	return head;
}
