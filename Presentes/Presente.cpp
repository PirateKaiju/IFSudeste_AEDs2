#include "Presente.h"
#include<iostream>

using namespace std;

Presente::Presente(){
	id = -1;
	preco = -1;
	tamanho = -1;
}
Presente::Presente(Presente &outro){
	id = outro.getId();
	preco = outro.getPreco();
	tamanho = outro.getTamanho();
}

Presente::~Presente(){

}
int Presente::getId(){
	return id;
}
double Presente::getPreco(){
	return preco;
}
double Presente::getTamanho(){
	return tamanho;
}
void Presente::setId(int i){
	id = i;
}
void Presente::setPreco(double p){
	preco = p;
		
}
void Presente::setTamanho(double t){
	tamanho = t;
}
void Presente::preencher(){
	cout << "\t--------------- Preencha os dados do presente ------------------\n";
	do{
		cout << "\tID: ";
		cin >> id;
	} while (id <= 0);
	do{
		cout << "\tPreco: ";
		cin >> preco;
	} while (preco <= 0);
	do{
		cout << "\tTamanho: ";
		cin >> tamanho;
	} while (tamanho < 0);
	cout << "\t---------------------------------------------------------------\n";
}
void Presente::copia(Presente &outro){
	id = outro.getId();
	preco = outro.getPreco();
	tamanho = outro.getTamanho();
}
void Presente::imprimir(){
	cout << "\t--------------- Presente ------------------\n";
	cout << "\tID: "<<id<<endl;
	cout << "\tPreco: "<<preco<<endl;
	cout << "\tTamanho: "<<tamanho<<endl;
	cout << "\t--------------------------------------------\n";
}