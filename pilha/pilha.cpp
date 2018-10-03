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

class Pilha
{
private:
    No *top;    
public:
	Pilha()
	{
	    top = NULL;
	}
	~Pilha(){
		delete top;
	}
	No * retornoNo(){
		return top;
	}
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

	void pop()
	{
	    if(top == NULL)
	            cout<< "Impossivel realizar operacao\n";
	    else
	    {
	        No * aux = top;
	        top = top->getProx();
	        delete(aux);
	    }
	}

	void print()
	{
	    No * aux;
	    aux = top;
	   	cout<<"Pilha\n";
	    while(aux!=NULL)
	    {
	        cout<<aux->getInfo()<<endl;
	        aux=aux->getProx();
	    }
	}


	int tamanho(){
		No * aux = top; 
		int cont = 0;
		while(aux != NULL){
			cont++;
			aux = aux->getProx();;
		}
		cout<<cont<<endl;	
		return cont;
	}

};



// void ordenar(Pilha p1,Pilha p2){
// 	Pilha Ps;
// 	int x;
// 	for (No * aux = p1.retornoNo();aux != NULL; aux = aux->getProx())
// 	{	
// 		x= aux->getInfo();

// 		for (No * aux2 = p2.retornoNo();aux2 != NULL; aux2 = aux2->getProx())
// 		{	
// 			if (x > aux2->getInfo()){
// 					x = aux2->getInfo();
// 			}
			 	
// 		}	
// 		Ps.push(x);
			 	  
// 	}


// 	Ps.print();

// }


void ordenar(Pilha p1,Pilha p2){
	No * aux = p1.retornoNo();
	No * aux2 = p2.retornoNo();
	
	Pilha Ps;
	Pilha Ps2;
	while(aux != NULL){
		Ps.push(aux->getInfo());
		aux = aux->getProx();
	}
	while(aux2 != NULL){
		Ps.push(aux2->getInfo());
		aux2 = aux2->getProx();
	}
	Ps.print();
	No * aux3 = Ps.retornoNo();
	No * aux4 = Ps.retornoNo();
	No * au;
	No * alfa;
	int i,j;
	while(aux3 != NULL){
		alfa = aux3->getProx();
		cout<<"ds\n";
		while(aux4 != NULL){
			aux4 = aux4->getProx()->getProx();
			
			cout<<"teste\n";
			if(aux4->getInfo() < alfa->getInfo())
            {
            	cout<<"testse\n";
              	alfa->setProx(aux4);
            }
            au->setProx(aux3);
			aux3->setProx(alfa);
			alfa->setProx(au);
		 	
		 	au->setInfo(aux3->getInfo());
	        aux3->setInfo(alfa->getInfo());
	        alfa->setInfo(au->getInfo());

		}
		aux3 = aux3->getProx();

	}
    // for(i=0; i<Ps.tamanho(); i++)
    // {
    // 	aux3 = aux3->getProx();		
    //     for(j=i+1; j < Ps.tamanho(); j++)
    //     {
    //     	aux4 = aux4->getProx()->getProx();
    //         if(aux3->getInfo() > aux4->getInfo())
    //         {
    //             au->setInfo(aux3->getInfo()) ;
    //             aux3->setInfo(aux4->getInfo());
    //             aux4->setInfo(au->getInfo());
    //         }

    //     }
    //     Ps.push(au->getInfo());
    // }


// for (i=2; i<=tam; i++){
//     x = vet[i];
//     j=i-1;
//     vet[0] = x; 
//     while (x < vet[j]){
//         vet[j+1] = vet[j];
//         j--;
//     }
//     vet[j+1] = x;
}

int busca(Pilha p1,int x){
	No * aux = p1.retornoNo(); 
	int cont = 1;
	while(aux != NULL){
		
		if (aux->getInfo()== x)
		{
			cout<<"valor encontrado\n";
			cout<<"valor: "<<aux->getInfo()<<" posicao: "<<cont << endl;

		}
		cont++;	
		aux = aux->getProx();
	}

	return 1;
}

void palindromo(Pilha p1){
	No * aux = p1.retornoNo();
	No * aux2 = p1.retornoNo();
	Pilha z;
	while(aux != NULL){
		z.push(aux->getInfo());
		aux = aux->getProx();
	}
	z.print();
	// while(aux2 != NULL){
	// 	Ps.push(aux2->getInfo());
	// 	aux2 = aux2->getProx();
	// }
}

int main() {   
    Pilha Exemplo;
    Pilha Exemplo2;
    Exemplo.push(1);
    Exemplo.push(3);
    Exemplo.push(5);
    Exemplo.push(4);
	
    Exemplo2.push(2);
    Exemplo2.push(4);
    Exemplo2.push(6);
    
    Exemplo.print();
    Exemplo2.print();
    
    //busca(Exemplo,3);
    palindromo(Exemplo);
   // 	ordenar(Exemplo,Exemplo2);


    return 0;
}

