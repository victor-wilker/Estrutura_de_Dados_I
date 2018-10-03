#include <iostream>
#include "listaDupla.hpp"

using namespace std;
/* 
	Nome: Victor Wilker
	Semestre : 3º
*/

No::No (int info){
	this->info = info;
	this->prox = NULL;
	this->ant = NULL;
}
		//funções gets e sets dos Nós 
int No::getInfo(){
	return info;
}
void No::setInfo(int info){
	this->info = info;
}


No * No::getProx(){
	return  prox;
}
void No::setProx(No * n){
	prox = n;
}


No * No::getAnt(){
	return  ant;
}
void No::setAnt(No * n){
	ant = n;
}


//Construtores
Lista::Lista(){//inicializar lista vazia
	this->ini =NULL;
	this->fim = NULL;
}


Lista::~Lista() // destrutor
{
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
		int cont =1;
		cout << "\n--Lista-- "<<endl;
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
		ini->setAnt(aux1) ;
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
		aux2->setAnt(fim);
		fim = aux2;
	}
}		
	
		//inserir no final da lista
void Lista::inserirMeio(int info,int pos)
{
	No * aux = ini; // O ant guarda o ponteiro para o nó anterior
	No * aux2 = ini->getProx(); // O pos guarda o ponteiro para o atual
	int cont =2;
	if (pos <= this->Sizes() && pos>0)
	{
		if (pos==1)
		{
			inserirIni(info);
		}else{
		
			while(pos > cont) {
				aux = aux2; // Guarda o ponteiro para o nó atual, que será o anterior
				aux2 = aux2->getProx(); // Vai para o próximo nó
				cont ++;
			}
			// Quando encontrou a posição correta na ordem crescente
			No * novo = new No(info); // Cria um novo nó
			//novo->setInfo(info); // Coloca a chave no nó
			novo->setProx(aux2); // Aponta para o próximo nó
			aux->setProx(novo); // Nó anterior aponta para o novo nó
			cout<< "Inseriu elemento na posicao: "<< pos<<endl;
		}
		
	}else{
		cout<< "Posicao nao existe\n";
	}
}		
		

// void List::addAt(int pos, int data){
// 	if(pos < 0 || pos >= size()){
// 		cout << endl << "posicao inexistente" << endl;
// 		return;
// 	}

// 	int cont = 0;
// 	Node *newNode = new Node;
// 	Node *temp = head;
// 	newNode->setValue(data);

// 	if(pos == 0){
// 		newNode->setNext(head);
// 		newNode->setPrev(NULL);
// 		head->setPrev(newNode);
// 		head = newNode;
// 		return;
// 	}

// 	while(cont < pos){
// 		temp = temp->getProx();
// 		cont++;
// 	}
// 	newNode->setNext(temp);
// 	newNode->setPrev(temp->getPrev());
// 	temp->getPrev()->setNext(newNode);	//atualiza o ponteiro anterior a posicao em que sera inserido para o novo noh
// 	temp->setPrev(newNode);
// }










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
	No * eleAtual,*eleProx,*eleAnt;
	if(vazia()){
		return ;
	}else{
		int cont =1;
		eleAtual = ini;
		while(eleAtual != NULL){
			eleProx = eleAtual->getProx();
			eleAnt = eleAtual->getAnt();
			if (cont == pos )
			{
				if (eleAnt != NULL)
				{
					if (eleProx!=NULL)
					{
						eleAnt->setProx(eleProx);
						eleProx->setAnt(eleAnt);
						delete eleAtual;
						break;
					}else{
						eleAnt->setProx(NULL);
						fim = eleAnt;
						delete eleAtual;
						break;
					}
				}else{
					if (eleProx != NULL)
					{
						eleProx->setAnt(NULL);
						ini= eleProx;
						delete eleAtual;
					}else{
						delete eleAtual;
					}

				}
			}else{
				eleAtual= eleAtual->getProx();
			}
		
			cont++;	
		}
		cout << "removeu posicao: " <<pos<<endl;
	}

	
	
}

