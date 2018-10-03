#ifndef LISTA_HPP_INCLUDE
#define LISTA_HPP_INCLUDE

/* 
	Nome: Victor Wilker
	Estrutura de Dados I
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
		void inserirMeio(int info,int pos);		
		//busca um valor na lista 
		bool busca(int info);
		//retorna o tamanho de uma lista
		int Sizes();
		void RemoveFim();
		void RemoveIni();
		void RemoveM(int pos);


};



#endif