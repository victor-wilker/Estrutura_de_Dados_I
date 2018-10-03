
#include <cstdlib>
#include <iostream>
using namespace std;
/* 
	Nome: Victor Wilker
	Estrutura de Dados I
*/


class No
{
private:
	int info;
    No * prox;
public:
   	int getInfo(){
		return info;
	}
	No * getProx(){
		return  prox;
	}
	void setProx(No * n){
		prox = n;
	}	
	void setInfo(int info){
		this->info = info;
	}
};

class Fila
{
private:
    No * ini;
    No * fim;   
public:
	Fila()
	{
	    ini = NULL;
		fim = NULL;
	}
	~Fila(){
		liberar();
		delete ini;
	}
	
	
	void insere(int info)
	{
		No * aux = new No();
		aux->setInfo(info);
		if(ini == NULL) { //caso seja o primeiro elemento faz com que os ponteiros inicio e fim apontem para ele
			ini = aux;
			fim = aux;
		}else{
			fim->setProx(aux); // faz com que o ponteiro prox que fim aponta aponte para aux
			fim = aux; //fim recebe aux
			aux->setProx(NULL); //ponteiro prox de aux recebe o fim da fila
		}
	}
	No * retornoNo(){
		return ini;
	}
	//remove apenas um elemento da fila
	void removerEle()
	{
	   No *aux;
		if(ini==NULL) {
		cout<<"ERRO: Fila vazia\n";
		}
		aux = ini;
		ini = ini->getProx(); //inicio recebe o proximo elemento da fila
		delete(aux);
	}
	//exibe fila
	void print()
	{
	    No * aux;

		
		aux=ini;
		int cont=1;
			cout<<"\n    ------ Fila -----\n";
		while(aux!=NULL) {
			cout<<"\t"<<cont<<"º ( " << aux->getInfo()<<" )"<<endl;
			aux = aux->getProx();
			cont ++;
		}
		if(vazia()) {
			cout <<"       Fila vazia\n";
		}
		 cout<<"    -----------------\n";
	}
	void busca(int info){
		cout <<"--Busca pelo elemento: "<<info<<endl<<endl;
		Fila aux;
		int cont = 0, cont1 = -1;
		bool teste;
		if (vazia())
		{
			this->print();	
		}else{
				while(vazia()){
				if(ini->getInfo() == info){
					teste = true;
					cont1 = cont;
				}
				//fila auxiliar
				aux.insere(ini->getInfo());	
				removerEle();
				cont++;
			}
			//insere na sequencia correta a fila
			while(!aux.vazia()){
				insere(aux.retornoNo()->getInfo());	
				aux.removerEle();
			}
			if(teste != true){
				cout << " Elemento -> "<< info<<" encontrado " << endl;
			}
			else{
				cout <<"Elemento nao encontrado" << endl;
			}	
		}
		
}



	//verifica se a fila está vazia
	bool vazia(){
		if(ini != NULL){
			return false;
		}
		else{
			return true;
			}
	}
	//libera toda a fila
	void liberar(){
		while(ini != NULL){
			removerEle();
		}	
	}



};
 


 int main(){
 	Fila f1 ;
 	Fila f2 ;
 	f1.insere(1);
 	f1.insere(2);
 	f1.insere(5);
 	f1.insere(6);
 	f1.insere(9);
 	f1.print();
 	f1.busca(2);
 	f1.removerEle();
 	f1.print();
 	f1.liberar();
 	f1.print();
 	

 	return 0;
 }