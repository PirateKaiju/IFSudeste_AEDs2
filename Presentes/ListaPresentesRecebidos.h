

#ifndef LISTAPRESENTESRECEBIDOS_H
#define	LISTAPRESENTESRECEBIDOS_H

#include "Presente.h"
class ListaPresentesRecebidos
{
public:
	ListaPresentesRecebidos();
	ListaPresentesRecebidos(ListaPresentesRecebidos &outra);
	~ListaPresentesRecebidos();
	void copia(ListaPresentesRecebidos &outra);
	bool temEspaco();
	bool isEmpty();
	bool indiceValido(int i);
	void shiftFront(int aPartir);
	void shiftEnd(int ate);

	void imprimirlpr();
	void insert(Presente &p);
	void insert(int posicao);
	void remove();
	void remove(int posicao);
	Presente buscar(int idPresente);
	int buscarIndice(int idPresente);

	void setLista(Presente* lista);
	Presente* getLista();
	void setQuant(int quant);
	int getQuant();
	void setTam(int tam);
	int getTam();
private:
	Presente *lista;
	int quant, tam;
};



#endif	/* LISTAPRESENTESRECEBIDOS_H */

