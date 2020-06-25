#pragma once
#include "Recorde.h"
#include <fstream>

using namespace std;

class HighScores
{
private:
	Recorde recorde;
	fstream arqRecordes;

public:
	bool bateuRecorde(float tempo);
	void adicionarRecorde(Recorde rec);
	bool carregarRecordes();
	bool salvarRecordes();
	string getRecorde();
};

