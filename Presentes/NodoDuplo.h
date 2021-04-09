

#ifndef NODODUPLO_H
#define	NODODUPLO_H

#include "Pessoa.h"
#include <iostream>

using namespace std;

class NodoDuplo
{
public:
	NodoDuplo();
	~NodoDuplo();
	NodoDuplo(Pessoa &outra);
	Pessoa getItem();
	void setItem(Pessoa outro);
	NodoDuplo* getProx();
	void setProx(NodoDuplo* p);
	NodoDuplo* getAnt();
	void setAnt(NodoDuplo* a);
private:
	NodoDuplo *prox;
	Pessoa item;
	NodoDuplo *ant;
};




#endif	/* NODODUPLO_H */

