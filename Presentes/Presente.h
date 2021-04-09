
#ifndef PRESENTE_H
#define	PRESENTE_H

#include <iostream>
using namespace std;
class Presente
{
    
public:
	Presente();
	Presente(Presente &outro);
	~Presente();
	void setId(int i);
	void setPreco(double p);
	void setTamanho(double t);
	int getId();
	double getPreco();
	double getTamanho();
	void preencher();
	void copia(Presente &outro);
	void imprimir();
private:
	int id;
	double preco;
	double tamanho;
};



#endif	/* PRESENTE_H */

