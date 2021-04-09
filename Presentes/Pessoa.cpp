#include "Pessoa.h"
#include <iostream>
using namespace std;



Pessoa::Pessoa(){
	id = -1;
	idade = 0;
	sexo = ' ';
	CPF = -1;
	tipo = -1;
	lpp = new ListaPresenteAPresentear();
	lpr = new ListaPresentesRecebidos();
}


Pessoa::~Pessoa(){

}
int Pessoa::getId(){
	return id;
}
void Pessoa::setId(int i){
	id = i;
}
int Pessoa::getIdade(){
	return idade;
}
void Pessoa::setIdade(int i){
	idade = i;
}
int Pessoa::getCFP(){
	return CPF;
}
void Pessoa::setCFP(int c){
	CPF = c;

}
int Pessoa::getTipo(){
	return tipo;
}
void Pessoa::setTipo(int t){
	tipo = t;
}
char Pessoa::getSexo(){
	return sexo;
}
void Pessoa::setSexo(char s){
	sexo = s;
}
void Pessoa::preencher(){
	cout << "\t--------------- Preencha os dados da Pessoa ------------------\n";
	do{
		cout << "\tID:";
		cin >> id;
	} while (id < 0);
	do{
		cout << "\tIdade:";
		cin >> idade;
	} while (idade < 0);
	do{
	    cout << "\tSexo (m/f):";
	    cin >> sexo;
	} while (sexo != 'm' && sexo != 'f');
	do{
		cout << "\tCPF:";
		cin >> CPF;
	} while (CPF <= 0);
	do{
		cout << "\tTipo \n\t0- para professor \n\t1- para aluno \n\t:";
		cin >> tipo;
	} while (tipo != 0 && tipo != 1);
	cout << "\t---------------------------------------------------------------\n";
}
void Pessoa::imprimir(){
	cout << "\t--------------- Pessoa ------------------\n";
	cout << "\tId:" << id << endl;
	cout << "\tIdade:" << idade << endl;
	cout << "\tSexo:" << sexo << endl;
	cout << "\tCPF:" << CPF << endl;
	if (tipo==0)
	    cout << "\tTipo: Professor" << endl;
	else
		cout << "\tTipo: Aluno" << endl;
	cout << "\t-------------------------------------------\n";
}
void Pessoa::preencherListaPresenteAPresentear(Presente &p){
	this->lpp->insert(p);
}
void Pessoa::preencherListaPresentesRecebidos(Presente &p){
	lpr->insert(p);
}
void Pessoa::copia(Pessoa &outra){
	id = outra.getId();
	idade = outra.getIdade();
	sexo = outra.getSexo();
	CPF = outra.getCFP();
	tipo = outra.getTipo();
}
void Pessoa::imprimirLp(){
	this->lpp->imprimirlpp();
}
void Pessoa::imprimirLr(){
	this->lpr->imprimirlpr();
}
ListaPresenteAPresentear* Pessoa::getLpp(){
	return lpp;
}
ListaPresentesRecebidos* Pessoa::getLpr(){
	return lpr;
}