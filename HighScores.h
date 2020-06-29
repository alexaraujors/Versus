#pragma once
#include "Recorde.h"
#include <fstream>

using namespace std;

class HighScores
{

private:
	fstream arqRecordes;
	Recorde* recordes[5];

public:
	bool bateuRecorde(string nome, int valor);
	void adicionarRecorde(Recorde rec);
	bool carregarRecordes();
	bool salvarRecordes();
	Recorde getRecorde(int posicao);
};

