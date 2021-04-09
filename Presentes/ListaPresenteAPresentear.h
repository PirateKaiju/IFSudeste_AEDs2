

#ifndef LISTAPRESENTEAPRESENTEAR_H
#define	LISTAPRESENTEAPRESENTEAR_H

#include "NodoSimples.h"

class ListaPresenteAPresentear
{
public:
	ListaPresenteAPresentear();
	~ListaPresenteAPresentear();
	void insert(Presente &p);
	void remove();
	NodoSimples* buscar(int idPresente);
	NodoSimples* getElemento(int posicao);
	void remove(int idp);
	void imprimirlpp();
	void imprimirIds();
	NodoSimples* getHead();
	bool isEmpty();
	void setQuant(int quant);
	int getQuant() const;

private:
	NodoSimples *head;
	int quant;
};


#endif	/* LISTAPRESENTEAPRESENTEAR_H */

