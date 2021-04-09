#include<iostream>

using namespace std;

struct Produto{
  
  int id;
  float preco;
  float custo;
  float estoque;
};

Produto * List1;
int quant = 0;
int tam = 0;

void criarlista(){
  cout<<"Digite o tamanho: "<<endl;
  cin>>tam;
  List1 = new Produto[tam];
  cout<<"Criada"<<endl;
}

void shiftend (){//move pro fim
  for(int i = quant; i>0; i--){
    List1[i]=List1[i-1];
  }
}

void shiftfront(){//move pro começo
  for(int i = 0; i<quant; i++){
    List1[i]=List1[i+1];
  }
}

void insert (Produto aux){
  shiftend();
  List1[0] = aux;
  quant++;
}

void remove (){
  shiftfront();
  quant--;
}

void AddProduto(){
  Produto aux;
  if(quant<tam){
  
  cout<<"Digite o ID do produto: "<<endl;
  cin>>aux.id;
  cout<<"Digite o PRECO do produto: "<<endl;
  cin>>aux.preco;
  cout<<"Digite o CUSTO do produto: "<<endl;
  cin>>aux.custo;
  cout<<"Digite o ESTOQUE do produto: "<<endl;
  cin>>aux.estoque;
  
  insert(aux);
  
  cout<<"Ta inserido!"<<endl;
  }else{
    cout<<"ERROU!"<<endl;
    
  }
}

void troca(Produto* a, Produto* b){//eh ASSIM QUE FAZ!!!
  Produto aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void Bubblesort(){//funfano
  for(int i = quant-1; i>=0; i--){
    for(int k = 0; k<i; k++){
      if(List1[k].id>List1[k+1].id){
	troca(&List1[k],&List1[k+1]);
      }
    }
  }
}


int BuscaBin (){//falta essa
  Bubblesort();
  int quantx = quant;
  
  
  
  
  
  
}

void Imprime(){
  for(int cont = 0; cont<quant; cont++){
    cout<<List1[cont].id<<endl;
    cout<<List1[cont].preco<<endl;
  }  
}




int main(){
criarlista();
AddProduto();
AddProduto();
AddProduto();
AddProduto();
Imprime();
cout<<"\n";
Bubblesort();
Imprime();




return 0;
}
