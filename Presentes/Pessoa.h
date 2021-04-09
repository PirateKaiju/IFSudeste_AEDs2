

#ifndef PESSOA_H
#define	PESSOA_H

#include "ListaPresenteAPresentear.h"
#include "ListaPresentesRecebidos.h"
class Pessoa
{
public:
	Pessoa();
	~Pessoa();
	int getId();
	void setId(int i);
	int getIdade();
	void setIdade(int i);
	int getCFP();
	void setCFP(int c);
	int getTipo();
	void setTipo(int t);
	char getSexo();
	void setSexo(char s);
	ListaPresenteAPresentear * getLpp();	
	ListaPresentesRecebidos * getLpr();
	void preencher();
	void imprimir();
	void imprimirLp();
	void imprimirLr();
	void preencherListaPresenteAPresentear(Presente &p);
	void preencherListaPresentesRecebidos(Presente &p);
	void copia(Pessoa &outra);

private:
	int id;
	int idade;
	char sexo;
	int CPF;
	int tipo;
	ListaPresenteAPresentear *lpp;
	ListaPresentesRecebidos *lpr;
};



#endif	/* PESSOA_H */

