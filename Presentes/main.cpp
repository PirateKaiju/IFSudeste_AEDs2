

#include "ListaPessoa.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main(){
    
	ListaPessoa l; //Já fiz as mudanças para rodar no Linux/Netbina
        Menu principal;
        int decis = -1;
        int subdecis = -1;
        int subsubdecis = -1;
        
        while(decis!=0){
        int tempquant = l.getQuant();  
        decis = principal.imprimir(tempquant);
        
        if(decis==1){//para uma
            subdecis = principal.qtdInsercao();
            if(subdecis == 1){
                subsubdecis = principal.tipoInsercao(tempquant);
                if(subsubdecis = 1){
                l.insert();
                }else if (subsubdecis = 2 && tempquant>0){
                    int temppos = 1;
                    cout<<"\tDigite a posicao para inserir: ";
                    cin>>temppos;
                    l.insert(temppos);
                //l.insertnaposicao aqui!!!
                }else{
                    cout<<"\tERRO! Comando Desconhecido!"<<endl;
                }
                
            }else if(subdecis == 2){//para varias
                     //subsubdecis = principal.tipoInsercao(tempquant);
                l.insertVarios();
                     
                     
            }else{
                cout<<"\tERRO! Comando Inválido!"<<endl;
            }
            
        }else if (decis == 2 && tempquant>0){//Remoções
        
            l.RemoverPessoa();
        //Remoções aqui!!!
        
        
        }else if (decis == 3 && tempquant>0){
            l.insertPresente();
            
            
            //Presentear!!!
        
        }else if(decis == 4 && tempquant>0){//Impressão
            subdecis = principal.impressao();
            if(subdecis == 1){
                l.imprimir();
            }else if(subdecis == 2){
                l.buscar();
                
            }else if(subdecis == 3){
            //anterior, proximo
                l.imprimeAntesDepois();
            
            }else if(subdecis == 4){
                l.imprimirP();//imprime os presentes
            
            }else{
                cout<<"\tERRO! Comando Desconhecido!"<<endl;
            }
        
        
     
        }else if(decis == 0){
            cout<<"\tFim da Execucao, Tenha um bom dia!"<<endl;
        }else{
            cout<<"\tErro! Comando Desconhecido!"<<endl;
        
        
        }
	
        
        }
        
       
        
	/*l.insert();
          l.insert();
	  l.imprimir();
          l.insertP();//arrumar
	l.imprimirP();
	*/
	return 0;
}