#include <iostream>
#include "listaDupla.cpp"

/* 
	Nome: Victor Wilker
	Semestre : 3º
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
	exemplo.RemoveM(7);
	exemplo.RemoveFim();
	exemplo.RemoveIni();
	exemplo.printar();	
	return 0;
}