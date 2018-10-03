
#include <cstdlib>
#include <iostream>
using namespace std;
/* 
	Nome: Victor Wilker
	Semestre : 3º
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
		delete ini;
		delete fim;
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
			aux->setProx(NULL); //ponteiro prox de aux recebe null(ou seja fim da fila)
		}
	}
	No * retorno(){
		return ini;
	}

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

	void print()
	{
	    No * aux;

		
		aux=ini;
		int cont=1;
			cout<<"\n    ------ Fila -----\n";
		while(aux!=NULL) {
			cout<<"\t"<<cont<<"º ( " << aux->getInfo()<<" )"<<endl;
				
			aux = aux->getProx();
		}
		if(vazia()) {
			cout <<"       Fila vazia\n";
		}
		 cout<<"    -----------------\n";
	}

	bool vazia(){
	if(ini != NULL){
		return false;
	}
	else{
		return true;
		}
	}
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
 	
 	f1.print();
 	f1.liberar();
 	f1.print();

 	return 0;
 }