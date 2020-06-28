#pragma once
#include "Heroi.h"

class Salvamento
{
	public:
		Salvamento(Heroi * heroi, string dataHora);
		~Salvamento();

		string getDataHora();
		Heroi * getHeroi();

	private:
		Heroi * heroi;
		string dataHora;
};

