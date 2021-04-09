#include "NodoDuplo.h"

#include <iostream>

using namespace std;


NodoDuplo::NodoDuplo()
{
	prox = NULL;
	ant = NULL;
}

NodoDuplo::NodoDuplo(Pessoa &outra){
	item.copia(outra);
}
NodoDuplo::~NodoDuplo()
{
}
Pessoa NodoDuplo::getItem(){
	return item;
}
void NodoDuplo::setProx(NodoDuplo*p){
	this->prox = p;
}
void NodoDuplo::setItem(Pessoa outro){
	item = outro;
}
NodoDuplo* NodoDuplo::getProx(){
	return prox;
}
NodoDuplo* NodoDuplo::getAnt(){
	return ant;
}
void NodoDuplo::setAnt(NodoDuplo*an){
	this->ant = an;
}