
#ifndef LISTAPESSOA_H
#define	LISTAPESSOA_H

#include "Pessoa.h"
#include "NodoDuplo.h"

class ListaPessoa
{
public:
	ListaPessoa();
	~ListaPessoa();
	void insert();
	void insertP(Presente &p , int i);
	void insertPr(Presente &p , int i);
	void insertPresente();
	void idCadastrado();
	void presenteCadastrado(int idPessoa);
	void remove();


	void removePresente();
	void imprimir();
	bool isEmpty();
	void imprimirP();
	int getQuant();
	NodoDuplo* buscaId(int i);
	NodoDuplo* getElemento(int posicao);
        
        /////////////
        void insert(int posicao);
        int insertVarios();
        void buscar();
        bool existe(int idpessoa);
        void imprimeAntesDepois();
        void RemoverPessoa();
private:
	int quant;
	NodoDuplo *head;
};



#endif	/* LISTAPESSOA_H */

