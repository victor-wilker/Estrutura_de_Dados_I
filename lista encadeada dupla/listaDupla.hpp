#ifndef LISTADUPLA_HPP_INCLUDE
#define LISTADUPLA_HPP_INCLUDE

/* 
	Nome: Victor Wilker
	Estrutura de Dados I
*/



class No{
	private:
    	int info;
    	No * prox;
    	No * ant;
	  public:
		//construtor
		No (int info);		//funções gets e sets dos Nós 
		void setInfo(int info);
		int getInfo();
		No * getProx();
		void setProx(No * n);
		No * getAnt();
		void setAnt(No * n);
		
};


class Lista{
	private:
		No * ini;
		No * fim;
	public:
		//Construtores
		Lista();
		Lista(int info);

		virtual ~Lista();
		// mostra todos os elementos da lista
		void printar();
		// verifica se a lista está vazia
		bool vazia();
		// insere no início 
		void inserirIni(int info);
		void inserirMeio(int info,int pos);
		//inserir no final da lista
		void inserirFim(int info);		
		//busca um valor na lista 
		bool busca(int info);
		//retorna o tamanho de uma lista
		int Sizes();
		void RemoveIni();
		void RemoveFim();
		void RemoveM(int pos);
// 		void insertLefRi(int info);
//  		int calcImpPar(int cont , int cont1,No * aux);
//  		int recursivaContar(int cont,No * aux);
//  		bool Ordenacao();
// // //		bool fibVerificar();
// // 		void insere();
// // 		void intercala (Lista* l, Lista* l2);

};



#endif