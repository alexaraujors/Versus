#pragma once
#include<string>
#include "Salvamento.h"

using namespace std;

class Jogador
{
	public:
		Jogador();
		~Jogador();

		string getNome();
		void setNome(string nome);
		string getSenha();
		void setSenha(string senha);
		int getRecorde();
		void setRecorde(int recorde);
		Heroi* getHeroi();
		void setHeroi(Heroi* heroi);
		
		Salvamento* getSalvamentos();
		void incluiSalvamento(Salvamento* salvamento);
		Salvamento* buscaSalvamento(int posicao);

	private:
		string nome = "";
		string senha = "";
		int recorde = 0;
		Salvamento* salvamentos[3];
		Heroi* heroi;

};

