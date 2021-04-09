#include "ListaPessoa.h"
#include "Menu.h"
#include "NodoSimples.h"
#include <iostream>

using namespace std;

ListaPessoa::ListaPessoa()
{
	quant = 0;
	head = NULL;
}


ListaPessoa::~ListaPessoa()
{
}
void ListaPessoa::insert(){
	Pessoa p;
	NodoDuplo *novo;
	p.preencher();
	novo = new NodoDuplo(p);
	novo->setProx(head);
	if (quant>0)
	novo->getProx()->setAnt(novo);
	head = novo;
	quant++;
}
NodoDuplo*ListaPessoa::getElemento(int n){//por posicao
	NodoDuplo* p = head;
	int j = 1;

	while (j <= n - 1 && p->getProx() != NULL) {
		p = p->getProx();
		j++;
	}

	if (j == n)
		return p;
	else
		return NULL;

}
void ListaPessoa::idCadastrado(){
	cout << "\tID's cadastrados \n";
	for (NodoDuplo*p = head; p != NULL; p = p->getProx()){
		cout << "\tID :" << p->getItem().getId()<<endl;
	}
}
void ListaPessoa::remove(){
	head = head->getProx();
	if (quant>1)
	head->setAnt(NULL);

	quant--;
}

bool ListaPessoa::isEmpty(){
	if (quant == 0)
		return true;
	else
		return false;
}
void ListaPessoa::imprimir(){
	cout << "\t>>>>>>>>>>>>>> Dados da Lista <<<<<<<<<<<<<<<<<<<<\n";
	if (isEmpty()) {
		cout << "\tLista vazia\n";
	}
	else {
		NodoDuplo* p = head;
		while (p != NULL){
			p->getItem().imprimir();
			p = p->getProx();
		}

	}
	cout << "\n\t>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
}
NodoDuplo* ListaPessoa::buscaId(int i){
	for (NodoDuplo*p = head; p != NULL; p = p->getProx()){
		if (p->getItem().getId() == i){
			return p;
		}
	}
	NodoDuplo *n;
	n = new NodoDuplo();
	return n;
}
void ListaPessoa::insertP(Presente &p , int i){
	NodoDuplo *novo = buscaId(i);
	novo->getItem().preencherListaPresenteAPresentear(p);

}
void ListaPessoa::imprimirP(){
	int i;
	idCadastrado();
	cout << "\tDigite o id da pessoa : ";
	cin >> i;
        if(existe(i)){
	NodoDuplo *novo = buscaId(i);
	novo->getItem().imprimirLp();
	novo->getItem().imprimirLr();
        }else{
            cout<<"\tERRO: ID Inexistente!"<<endl;
        }
}
void ListaPessoa::insertPr(Presente &p , int i){
	NodoDuplo *novo = buscaId(i);
	novo->getItem().preencherListaPresentesRecebidos(p);
}
void ListaPessoa::insertPresente(){
	int ide = 0;
	int	idr = 0;
	idCadastrado();
	cout << "\n\tDigite o ID de quem vai enviar o presente :";
	cin >> ide;
	cout << "\n\tDigite o ID que vai receber o presente : ";
	cin >> idr;
	Presente p;
	p.preencher();
	insertP(p, ide);
	insertPr(p, idr);
}
int ListaPessoa::getQuant(){
	return quant;
}
void ListaPessoa::removePresente(){
	int i;
	int ip;
	int posicao2 = 0;
	idCadastrado();
	cout << "\n\tDigite o ID da pessoa" << endl;
	cin >> i;
	presenteCadastrado(i);
	cout << "\n\tDigite o ID do presente a ser removido :" << endl;
	cin >> ip;
	for (NodoDuplo*p = head; p != NULL; p = p->getProx()){
		p->getItem().getLpp()->remove(ip);
		for (int k = 0; k < 100; k++){
			if (p->getItem().getLpr()->getLista()[k].getId() == ip){
				p->getItem().getLpr()->remove(posicao2);
			}
			posicao2++;
		}
	}
}
void ListaPessoa::presenteCadastrado(int idPessoa){
	NodoDuplo *p = buscaId(idPessoa);
	p->getItem().getLpp()->imprimirIds();
}




//////////////////////////////



void ListaPessoa::insert(int posicao){
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    if (quant>0 && posicao>1){
        Pessoa p;
        p.preencher();
        NodoDuplo * novo = new NodoDuplo(p);
        
        NodoDuplo* n = getElemento(posicao); //economia!!!
        novo->setProx(n);//estudar isto
        
        novo->setAnt(n->getAnt());//nova linha aquif
        (n->getAnt())->setProx(novo);
        n->setAnt(novo);
        quant++;
        
    }else if(posicao == 1){
        insert();
    }
}

int ListaPessoa::insertVarios(){//Insere varios de uma vez ate parar
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    char resp=' ';
    int aux = -1;
    int decis = -1;
    Menu local;
    
    do{
        decis = local.tipoInsercao(quant);
        if(decis==1){
            insert();
        }else if(decis==2 && quant>0){
            while(aux<=0 || aux>quant){//necessario
            cout<<"\tDigite a posicao para insercao: ";
            cin>>aux;
            }
            insert(aux);
        }else{
            cout<<"\tErro: Opção Inválida!!!"<<endl;
        }
        cout<<"\t-------------------------------------------------------------------------"<<endl;//somente embelezamento
        cout<<"\tDeseja cadastrar mais pessoas?(s/n): ";
        cin>>resp;
    }while(resp!='n' && resp !='N');
    
    cout<<"\tInserções Concluídas!!!"<<endl;
}

void ListaPessoa::buscar(){//busca pelo id que entrar

    NodoDuplo * aux;
    int help;
    cout<<"\tDigite o ID a buscar: ";
    cin>>help;
    if(existe(help)){
    aux = buscaId(help);
    aux->getItem().imprimir();
    }else{
        cout<<"\tERRO: Este ID nao consta!"<<endl;
    }
}

bool ListaPessoa::existe(int idpessoa){//checa se um id existe
    for(NodoDuplo * p = head; p != NULL; p = p->getProx()){
        if(idpessoa == p->getItem().getId()){
            return true;
        }
    }
    return false;
}

void ListaPessoa::imprimeAntesDepois(){
    int posicao;
    
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\tDigite uma posicao: ";
    cin>>posicao;
    if(posicao>0 && posicao<=quant){
        NodoDuplo * n = getElemento(posicao);//economia de mem
        
        
        if(n->getProx()!=NULL){//necessario para nao termos falha de seg.
        cout<<"\t-------------------------------------------------------------------------"<<endl;
        cout<<"\tProximo:"<<endl;
        (n->getProx())->getItem().imprimir();
        }
        
        
        if(n->getAnt()!=NULL){
        cout<<"\t-------------------------------------------------------------------------"<<endl;
        cout<<"\tAnterior: "<<endl;
        (n->getAnt())->getItem().imprimir(); //presta atençao nos parenteses bicho! ja estamos economizando aqui!
        }
    }
}

void ListaPessoa::RemoverPessoa(){//remover pessoa + lista de enviados + recebidos
    idCadastrado();
    int tempid;
    cout<<"\tDigite o Id da Pessoa: ";
    cin>>tempid;//passando o id;
    
    
    ///Continue a partir daqui...
    NodoDuplo * aux;
   if(existe(tempid)){//buscando e checando este id
    aux = buscaId(tempid);//ja temos o nodo aqui! eh o que removeremos
    
    
   //aux->getItem().
    NodoSimples* ate1;
    
    NodoSimples* ate2;
    
    NodoDuplo* p = head;//ESTE CARA SERÁ A NOSSA LISTA DE PESSOA!
    while (p != NULL){//percorrer a lista de pessoas toda
           
          
           for(int i = 0; i<p->getItem().getLpr()->getTam(); i++ ){
               
           ate1 = aux->getItem().getLpp()->getHead();//pega a lista a presentear do cara que vamos remover
           
           while(ate1 != NULL){
               if((ate1)->getItem().getId()==(p->getItem().getLpr()->getLista())[i].getId()){//compara eles
                   //uma função de remoção aqui dentro...
                   p->getItem().getLpr()->shiftFront(i);
                   p->getItem().getLpr()->setQuant((p->getItem().getLpr()->getQuant())-1);//tirar o que agente acabou de remover
               }
              
               (ate1) = (ate1)->getProx();//esta passando de um presente para o outro
           }
          
        }             
           p = p->getProx();
    }
    
    ///PAREI AQUI!!! FALTA A OUTRA PARTE!!!///
    
    p = head;
    NodoSimples* meuAux = p->getItem().getLpp()->getHead();
    bool ehprimeiro = true;
    
    while (p != NULL){
        
        for (int i = 0; i<aux->getItem().getLpr()->getTam(); i++){
        
        ate2 = p->getItem().getLpp()->getHead();
        
        while(ate2 != NULL){
        
            if(ate2->getItem().getId() == (aux->getItem().getLpr()->getLista())[i].getId()){//preciso armazenar o antes de ate2
                if(ehprimeiro == true){
                    meuAux->setProx(ate2->getProx());
                    
                }else{
                    ate2->setProx(ate2->getProx()->getProx());
                }
               
            }
                ehprimeiro = false;
            
            (ate2) = (ate2)->getProx();
          }
    
        }
        p = p->getProx();//passando para a proxima pessoa!!!
    }
    
    //while ( p != NULL){//mudar
        
       /* for(int i = 0; i<aux->getItem().getLpr()->getTam(); i++){
            
            ate2 = p->getItem().getLpp()->getHead();
            
           
            while(ate2!=NULL){
                if((ate2)->getItem().getId()==(aux->getItem().getLpr()->getLista())[i].getId()){
                    if(ate2->getProx()!=p->getItem().getLpp()->getHead()){//para o caso da 1 ser
                       meuAux->setProx(ate2->getProx());
                    }else{
                       p->getItem().getLpp()->getHead()->setProx(ate2->getProx()); //sappora nao vai dar certo...
                    }
                
                
                }
                if(ate2->getProx()!=p->getItem().getLpp()->getHead()){
                 meuAux = meuAux->getProx();
                }
                
                (ate2) = (ate2)->getProx();
                
            }
        
        
        
        }
    
    */
    
    
     //   p = p->getProx();
    //}
    
    
    
    
    
    cout<<"Passou 1 etapa"<<endl;//rastreio, remover depois
    
    
    //Daqui para baixo, funcinando!!!
    NodoDuplo* n = buscaId(tempid);//fazer a condicional para quando for 0
    
    if(n->getAnt()!=NULL){
        
    if(n->getProx()==NULL){
       n->getAnt()->setProx(NULL);
    

    }else{
        
        n->getAnt()->setProx(n->getProx());
        n->getProx()->setAnt(n->getAnt());
    
    
    }
    
    }else{
        head = head->getProx();
    }
    
    quant--;// já que retiramos...
    
    cout<<"\tJa removi!"<<endl;
    
    }else{
        cout<<"\tERRO: Este ID nao consta!"<<endl;
    }




}





/*
 while (p != NULL){//percorrer a lista de pessoas toda
           
           ate2 = p->getItem().getLpr()->getLista(); //pega a lista recebidos da pessoa em que a gente tá comparando
           while(ate2 != NULL){
           int meucontador = 1; //a gambiarra cada vez aumenta mais...
           ate1 = aux->getItem().getLpp()->getHead();//pega a lista do cara que vamos remover
           
           while(ate1 != NULL){
               if(ate1.getItem().getId()==ate2.getItem().getId()){//compara eles
                   //uma função de remoção aqui dentro...
                   
               }
              
               ate1 = ate1.getProx();//esta passando de um presente para o outro
           }
           meucontador++;
           ate2 = ate2.getProx();
        }             
           p = p->getProx();
    }
    
 
 
 
 
 */