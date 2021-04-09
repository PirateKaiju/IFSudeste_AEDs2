
#ifndef MENU_H
#define	MENU_H


class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    
    int imprimir(int tamanhodalista);
    int tipoInsercao(int tamanhodalista);
    int qtdInsercao();
    
    int remocao();
    int impressao();
    int buscador();
    int Presentear();
    
    
private:
    int decisao;
};

#endif	/* MENU_H */

