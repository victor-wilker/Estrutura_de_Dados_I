
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
	}
	
	
	void push(int info)
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

	void pop()
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

		if(ini==NULL) {
			cout <<"ERRO: Fila vazia\n";

		}
		aux=ini;
		while(aux!=NULL) {
			cout<< aux->getInfo() <<endl;
			aux = aux->getProx();
		}
	}

};
 


 int main(){
 	Fila f1 ;
 	Fila f2 ;
 	f1.push(1);
 	f1.push(2);
 	f1.push(5);
 	f2.push(1);
 	f2.push(2);
 	f2.push(5);
 	f2.print();
 	
 	No * aux = f1.retorno();
 	No * aux1 = f2.retorno();
 	while(aux->getProx() != NULL and aux1->getProx()){
 		


 		aux1= aux1->getProx();
 		aux= aux->getProx();
 	}

 	return 0;
 }