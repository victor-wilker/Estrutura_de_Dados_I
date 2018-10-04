#include <iostream>
#include "lista.cpp"
/* 
	Nome: Victor Wilker
	Estrutura de Dados I
*/

int main(int argc, char const *argv[])
{
	Lista exemplo;
	exemplo.printar();
	exemplo.inserirIni(3);
	exemplo.inserirIni(2);
	exemplo.inserirIni(1);
	exemplo.inserirFim(4);
	exemplo.inserirFim(5);	
	exemplo.inserirFim(6);	
	exemplo.inserirIni(0);
	exemplo.inserirMeio(45,6);
	if (exemplo.busca(6) == true)
	{
		cout << "elemento encontrado\n";
	}else{
		cout << "elemento nao encontrado\n";
	}

	exemplo.printar();	
	exemplo.RemoveM(5);
	exemplo.RemoveIni();
	exemplo.printar();
	exemplo.liberar();
	exemplo.printar();	
	return 0;
}