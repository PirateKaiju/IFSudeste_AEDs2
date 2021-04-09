
#ifndef NODOSIMPLES_H
#define	NODOSIMPLES_H

#include "Presente.h"
class NodoSimples
{
public:
	NodoSimples();
	NodoSimples(Presente &p);
	~NodoSimples();
	Presente getItem();
	void setItem(Presente outro);
	NodoSimples* getProx();
	void setProx(NodoSimples* p);
private:
	Presente item;
	NodoSimples *prox;
};

#endif	/* NODOSIMPLES_H */

