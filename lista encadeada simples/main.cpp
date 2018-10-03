#include <iostream>
#include "lista.cpp"
/* 
	Nome: Victor Wilker
	Semestre : 3º
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
	exemplo.printar();	

	exemplo.RemoveM(7);
	exemplo.RemoveIni();
	exemplo.printar();
	return 0;
}