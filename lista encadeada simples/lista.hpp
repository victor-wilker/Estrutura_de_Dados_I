#ifndef LISTA_HPP_INCLUDE
#define LISTA_HPP_INCLUDE

/* 
	info : Dados da Lista
	prox : ponteiro que aponta para o proximo elemento
	aux : auxiliar para percorrer a lista para imprimir os valores fuc: printar();
	aux1 : auxiliar na inserção do primeiro elemento na lista fuc: inserirIni(int info)
	aux2 : auxiliar na inserção do último elemento na lista fuc:  inserirFim(int info)
	aux3 : auxiliar para percorrer a lista e contar os elemento  fuc:  inserirFim(int info)
	tamanho : contator para mostrar quantos elementos possui uma lista fuc: inserirFim(int info)
	aux4 : auxiliar para percorrer a lista e buscar o elemento desejado fuc:  busca(int info)
	aux5 : Nó que recebe a lista a ser percorrida fuc:  fuc: del()
	aux6 : auxiliar para percorrer a lista e remover elementos desejados fuc: del()
	ant : nó que aponta para o proximo  elemento da lista fuc: del()
	ant 1 : nó que aponta para o proximo do proximo elemento da lista fuc: del()

*/


class No{
	private:
    	int info;
    	No * prox;
	  public:
		//construtor
		No (int info);		//funções gets e sets dos Nós 
		int getInfo();
		No * getProx();
		void setProx(No * n);
		void setInfo(int info);
};


class Lista{
	private:
		No * ini;
		No * fim;
	public:
		//Construtores
		Lista();


		virtual ~Lista();
		// mostra todos os elementos da lista
		void printar();
		// verifica se a lista está vazia
		bool vazia();
		// insere no início 
		void inserirIni(int info);
		//inserir no final da lista
		void inserirFim(int info);		
		//busca um valor na lista 
		bool busca(int info);
		//retorna o tamanho de uma lista
		int Sizes();
		void RemoveFim();
		void RemoveIni();
		void RemoveM(int pos);


};



#endif