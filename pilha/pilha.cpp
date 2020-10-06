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

class Pilha
{
private:
    No * top;    
public:
	Pilha()
	{
	    top = NULL;
	}
	~Pilha(){
		remove();
		delete top;
	}
	No * retornoNo(){
		return top;
	}
	//Insere elemento na Pilha
	void push(int info)
	{
	   
	        No * novo = new No;
	        if(top == NULL)
	        {       
	            novo->setInfo(info);
	            novo->setProx(NULL) ;
	            top = novo;
	     	        }
	        else
	        {
	            novo->setInfo(info);
	            novo->setProx(top);
	            top = novo;
	        }
	    
	}
	//remove elemento da Pilha
	void pop()
	{
	    if(top == NULL)
	            cout<< "Impossible to perform operation\n";
	    else
	    {
	        No * aux = top;
	        top = top->getProx();
	        delete(aux);
	    }
	}
	//exibe elementos da pilha
	void print()
	{
	    No * aux;
	    aux = top;
	   	cout<<"\n    ---- stack -----\n";
	    int cont=1;
	    while(aux!=NULL)
	    {
	        cout<<"\t"<<cont<<"º ( " << aux->getInfo()<<" )"<<endl;
	        aux=aux->getProx();
	    	cont++;
	    	
	    }
	    if (vazia()==true)
	    {
	    	cout<<"     stack empty\n";
	    }
	    cout<<"    -----------------\n";
	}

	bool vazia(){
		if(top != NULL){
			return false;
		}
		else{
			return true;
		}
	}

	//retorna o tamanho da pilha
	int tamanho(){
		int cont = 1;
		Pilha aux;
		//remove  elementos
		while(!vazia()){	
			aux.push(top->getInfo());
			pop();
			cont++;
		}
		//adiciona elemetos 
		while(!aux.vazia()){	
			push(aux.retornoNo()->getInfo());
			aux.pop();
		}

			
			return cont;
		}

		//faz a busca de elementos na pilha
		void busca(int info){
			cout <<"-- seeking element: "<<info<<endl<<endl;
			int cont = 1;
			Pilha aux;
			bool teste=false;
			while(!vazia()){
				if(top->getInfo() == info){//verifica se existe
					while(!aux.vazia()){
						push(aux.retornoNo()->getInfo());
						aux.pop();
					}
					cout << " Element: "<< info<<" found "<< cont << "º position" << endl;
					teste = true;
					break;
				}
				aux.push(top->getInfo());
				pop();
				cont++;
			}
			if (teste ==false)
			{
				cout << "Element not exist" << endl;
			}
			while(!aux.vazia()){//recoloca os elementos 
				push(aux.retornoNo()->getInfo());
				aux.pop();
			}
			
		}
		
	void remove(){
		while(!vazia()){
			pop();
		}
		
	}


};


int main() {   
    Pilha Exemplo;

    Exemplo.push(1);
    Exemplo.push(3);
    Exemplo.push(4);
    Exemplo.push(5);
    Exemplo.push(6);
    Exemplo.push(7);
    Exemplo.print();
    Exemplo.busca(10);
    Exemplo.busca(5);
	Exemplo.print();
 	Exemplo.pop();   
    Exemplo.remove();
    Exemplo.print();
    return 0;
}

