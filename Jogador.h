#pragma once
#include<string>
#include <list>
#include "Salvamento.h"
#include "Heroi.h"

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
		
		void incluiSalvamento(Salvamento salvamento);
		Salvamento buscaSalvamento(int posicao);

	private:
		string nome = "";
		string senha = "";
		int recorde = 0;
		list<Salvamento> salvamentos;
		Heroi* heroi;

};

