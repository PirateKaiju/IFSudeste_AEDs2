#include "ListaPresentesRecebidos.h"



ListaPresentesRecebidos::ListaPresentesRecebidos(){
	quant = 0;
	tam = 100;
	lista = new Presente[tam];
}
ListaPresentesRecebidos::ListaPresentesRecebidos(ListaPresentesRecebidos &outra){
	quant = outra.getQuant();
	tam = outra.getTam();
	lista = outra.getLista();
}
void ListaPresentesRecebidos::copia(ListaPresentesRecebidos &outra){
	quant = outra.getQuant();
	tam = outra.getTam();
	lista = outra.getLista();
}
ListaPresentesRecebidos::~ListaPresentesRecebidos(){

}
int ListaPresentesRecebidos::getQuant(){
	return quant;
}
void ListaPresentesRecebidos::setQuant(int q){
	quant = q;
}
int ListaPresentesRecebidos::getTam(){
	return tam;
}
void ListaPresentesRecebidos::setTam(int t){
	tam = t;
}
Presente* ListaPresentesRecebidos::getLista(){
	return lista;
}
void ListaPresentesRecebidos::setLista(Presente *L){
	lista = L;
}

bool ListaPresentesRecebidos::temEspaco(){
	if (quant < tam)
		return true;
	else
		return false;
}
bool ListaPresentesRecebidos::isEmpty(){
	if (quant == 0)
		return true;
	else
		return false;
}
bool ListaPresentesRecebidos::indiceValido(int i){
	if (i > 0 && i < tam)
		return true;
	else
		return false;
}

void ListaPresentesRecebidos::shiftFront(int ap){
	if (indiceValido(ap)) {
		if (!isEmpty()) {
			for (int i = ap; i < quant; i++) {
				lista[i].copia(lista[i + 1]);
			}
		}
	}
}
void ListaPresentesRecebidos::shiftEnd(int ate){
	if (temEspaco() && !isEmpty()) {
		for (int i = quant; i > ate; i--) {			
			lista[i].copia(lista[i - 1]);
		}
	}
}
void ListaPresentesRecebidos::imprimirlpr(){
	cout << "\t-------------- Lista de presentes recebidos --------------\n";
	if (isEmpty()) {
		cout << "\tLista vazia\n";
	}
	else {
		for (int i = 0; i <= quant - 1; i++) {
			lista[i].imprimir();
		}
	}
	cout << "\t-----------------------------------------------------------\n";
}
void ListaPresentesRecebidos::insert(Presente &p){
	if (temEspaco()) {
		shiftEnd(0);
		lista[0].copia(p);
		quant++;
	}
}
void ListaPresentesRecebidos::remove(){
	shiftFront(0);
	quant--;
}
void ListaPresentesRecebidos::remove(int p){
	shiftFront(p);
	quant--;
}
Presente ListaPresentesRecebidos::buscar(int idPresente){
	for (int i = 0; i <= tam - 1; i++) {
		if (lista[i].getId() == idPresente)
			return lista[i];
	}
	Presente p;
	return p;
}
int ListaPresentesRecebidos::buscarIndice(int idPresente){
	for (int i = 0; i <= tam - 1; i++) {
		if (lista[i].getId() == idPresente)
			return i;
	}

	return -1;
}