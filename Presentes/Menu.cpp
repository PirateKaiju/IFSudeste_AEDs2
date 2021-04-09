#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    decisao = -1;
}

Menu::Menu(const Menu& orig) {//nao eh necessario
}

Menu::~Menu() {
}

//Adaptado
int Menu::imprimir(int tamanhodalista){//main menu
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\tEscolha uma opção: "<<endl;
    cout<<"\t1 - Cadastrar Pessoa"<<endl;
    if(tamanhodalista>0){
    cout<<"\t2 - Remover"<<endl;
    cout<<"\t3 - Presentear"<<endl;
    cout<<"\t4 - Imprimir"<<endl;
    
    }
    cout<<"\t0 - Sair do Programa"<<endl;
    cout<<"\tSua opção: ";
    cin>> decisao;
    return decisao;
}

int Menu::tipoInsercao(int tamanhodalista){//AJUSTAR
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\tEscolha o metodo de Insercao: "<<endl;
    cout<<"\t1 - Inserir normalmente"<<endl;//essa eh a escolha
    if(tamanhodalista>0){
    cout<<"\t2 - Inserir em uma posicao especifica"<<endl;
    }
    cout<<"\tSua opção: ";
    cin>>decisao;
    return decisao;
}

int Menu::qtdInsercao(){
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\tQuantas pessoas deseja cadastrar?"<<endl;
    cout<<"\t1 - Somente uma;"<<endl;
    cout<<"\t2 - Varias;"<<endl;
    cout<<"\tSua opção: ";
    cin>>decisao;
    return decisao;
}

int Menu::remocao(){
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\tComo deseja Remover?"<<endl;
    cout<<"\t1 - Remover a Primeira Posicao"<<endl;
    cout<<"\t2 - Remover por Posicao"<<endl;
    cout<<"\tSua opção: ";
    
    cin>>decisao;
    return decisao;

}

int Menu::impressao(){
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\t Menu de Impressao "<<endl;
    cout<<"\t1 - Imprimir Lista de Pessoas;"<<endl;
    cout<<"\t2 - Buscar Pessoa;"<<endl;
    cout<<"\t3 - Imprime Anterior / Proximo;"<<endl;//podemos usar, so pra aproveitar a duplaencadeada
    cout<<"\t4 - Imprimir Listas de Presentes"<<endl;
    cout<<"\tSua opção: ";
    cin>>decisao;
    return (decisao);
}

int Menu::buscador(){
    cout<<"\t-------------------------------------------------------------------------"<<endl;
    cout<<"\t1 - Buscar por ID;"<<endl;
    cout<<"\t2 - Buscar por Posicao;"<<endl;
    cout<<"\tSua opção: ";
    cin>>decisao;
    return(decisao);

}

int Menu::Presentear(){
    cout<<"\t      "<<endl;//inserir opçoes aqui...



    cin>>decisao;
    return(decisao);
}
