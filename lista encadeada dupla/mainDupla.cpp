#include <iostream>
#include "listaDupla.cpp"

/* 
	Nome: Victor Wilker
	Estrutura de Dados I
*/

int main(int argc, char const *argv[])
{
	Lista exemplo;
	exemplo.printar();
	exemplo.inserirIni(4);
	exemplo.inserirIni(5);
	exemplo.inserirIni(7);
	exemplo.inserirFim(12);	
	exemplo.inserirFim(2);	
	exemplo.inserirIni(7);
	exemplo.printar();	

	exemplo.inserirMeio(9,3);
	exemplo.printar();
	
	exemplo.RemoveFim();
	exemplo.RemoveIni();
	exemplo.RemoveM(2);
	exemplo.printar();	
	if (exemplo.busca(5) == true)
	{
		cout << "elemento encontrado!!\n";
	}else{
		cout << "elemento nao encontrado\n";
	}
	exemplo.printar();	
	exemplo.liberar();
	exemplo.printar();
	return 0;
}