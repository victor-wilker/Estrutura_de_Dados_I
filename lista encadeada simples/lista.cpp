#include <iostream>
#include "lista.hpp"

/* 
	Nome: Victor Wilker
	Estrutura de Dados I
*/


using namespace std;


No::No (int info){
	this->info = info;
	this->prox = NULL;
}
		//funções gets e sets dos Nós 
int No::getInfo(){
	return info;
}
No * No::getProx(){
	return  prox;
}
void No::setProx(No * n){
	prox = n;
}
void No::setInfo(int info){
	this->info = info;
}



//Construtores
Lista::Lista(){//inicializar lista vazia
	this->ini =NULL;
	this->fim = NULL;
}

Lista::~Lista() // destrutor
{
	liberar();
	delete ini;
	delete fim;
}

		// mostra todos os elementos da lista
void Lista::printar() 
{
	No* aux = ini;	
	if(aux == NULL)
		cout << " lista Vazia\n";
	else
	{
		int cont=1;
		cout << "\nLista "<<endl;
		while(aux) // percorre a lista
		{
			cout << cont <<"º | "<<aux->getInfo() << " ";
			aux = aux->getProx();
			cout << endl;
			cont++;
		}
		cout << endl;
	}
}
		// verifica se a lista está vazia
bool Lista::vazia() 
{
	if (ini ==NULL)
	{
		return true;
	}else{
		return false;
	}
}

		// insere no início 
void Lista::inserirIni(int info)
{
	No* aux1 = new No(info);
		if(vazia())
	{
		ini = aux1;
		fim = aux1;
	}
	else
	{
		aux1->setProx(ini);
		ini = aux1;
	}
}
		//inserir no final da lista
void Lista::inserirFim(int info)
{
	No * aux2 = new No(info);
	if(vazia())
	{
		ini = aux2;
		fim = aux2;
	}
	else
	{
		fim->setProx(aux2);
		fim = aux2;
	}
}		
void Lista::inserirMeio(int info,int pos)
{
	No * aux = ini; // O aux é o ponteiro para o anterior
	No * aux2 = ini->getProx(); // O aux é o ponteiro para o proximo
	int cont =2;
	if (pos <= this->Sizes() && pos>0)
	{
		if (pos == 1)
		{
			this->inserirIni(info);
		}else{
			while(pos >cont) {
				// recebe ponteiro para o nó atual, que será o anterior
				aux = aux2; 
				aux2 = aux2->getProx(); // Vai para o próximo nó
				cont ++;
			}
		// Quando encontrou a posição correta na ordem crescente
			No * novo = new No(info); // Cria um novo nó
			// Aponta para o próximo nó
			novo->setProx(aux2); 
			aux->setProx(novo); // Nó anterior aponta para o novo nó
		
		}
		cout<< "Inseriu elemento na posicao: "<< pos <<endl;
	}else{
		cout<< "Posicao nao existe\n";
	}
	
}		
			
			
		//busca um valor na lista 
bool Lista::busca(int info)
{
	No* aux4 = ini;
			
	while(aux4)
	{
		if(aux4->getInfo() == info)
			return true;
		aux4 = aux4->getProx();
	}
	return false;
}


		//retorna o tamanho de uma lista
int Lista::Sizes()
{
	if(vazia()){
		return 0;
	}
		
	No* aux3 = ini;
	int tamanho = 0;
	
	// percorre a lista
	do
	{
		aux3 = aux3->getProx();
		tamanho++;
	}
	while(aux3);
	
	return tamanho;
}

void Lista::RemoveFim()
{
	cout<< "removeu do Fim da lista\n";
	if(!vazia())
	{

		// para apenas 1 elemento
		if(ini->getProx() == NULL)
			ini = NULL;
		else if(ini->getProx()->getProx() == NULL) // 2 elementos
			ini->setProx(NULL);
		else // para mais de dois elementos
		{
			No* ant = ini;
			No* ant1 = ini->getProx();
			No* aux5 = ini->getProx()->getProx();

			while(aux5)
			{
				No* aux6 = ant1;
				ant1 = aux5;
				ant = aux6;
				aux5 = aux5->getProx();
			}
			delete ant->getProx(); // libera memória
			ant->setProx(NULL); // seta o prox como NULL
			fim = ant; // atualiza o fim lista
		}
	}
}

void Lista::RemoveIni(){
	cout<< "removeu do Inicio da lista\n";
	if(ini->getProx() == NULL){
			ini = NULL;
	}else if(ini->getProx()->getProx() == NULL){
			ini->setProx(NULL);
	}else{
		No* exe = ini;
		ini = ini->getProx();
		exe->setProx(exe);
		delete exe;
	}
}

void Lista::RemoveM(int pos)
{
	No * eleAtual,*eleAnt;
	if(vazia()){
		return ;
	}else{
		int cont =1;
		eleAnt = ini;
		eleAtual = ini;
		if (pos ==1 )
		{
			RemoveIni(); 
		}else{
			while(eleAtual !=NULL){
			if (cont == pos)
			{
				if (eleAtual == ini)
				{
					ini->setProx(ini);
					delete eleAtual;
					cout<< "removeu elemento na posicao: " <<pos <<endl;
					break;
				}else{
					if (eleAtual == fim)
					{
						fim = eleAnt;
					}
					eleAnt->setProx(eleAtual->getProx());
					delete eleAtual;
					cout<< "removeu elemento na posicao: " <<pos <<endl;
					break;
				}
			}else{
				eleAnt = eleAtual;
				eleAtual = eleAtual->getProx();


			}
			
			cont++;
		}

		}
		
	}	
}
// função auxiliara para limpar lista
void Lista::RemoveAux(){

	if(ini->getProx() == NULL){
			ini = NULL;
	}else if(ini->getProx()->getProx() == NULL){
			ini->setProx(NULL);
	}else{
		No* exe = ini;
		ini = ini->getProx();
		exe->setProx(exe);
		delete exe;
	}
}
//remove todos os elementos da lista
void Lista::liberar(){
		cout << "** esvaziando lista **" <<endl;
		while(ini != NULL){
			RemoveAux();
		}	
}

