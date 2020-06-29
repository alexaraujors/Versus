#pragma once
#include "Recorde.h"
#include <fstream>
#include <list>


using namespace std;

class HighScores
{

private:
	fstream arqRecordes;
	list<Recorde> recordes;
	bool comparaRecorde(Recorde &r1, Recorde &r2);

public:
	void adicionarRecorde(string nome, int valor);
	bool carregarRecordes();
	bool salvarRecordes();
	string getRecordes();
};

