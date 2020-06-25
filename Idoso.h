#pragma once
#include "Pessoa.h"

class Idoso :
	public Pessoa
{
public:
	bool estaDoente();
	int getVelocidade();
	string getIdade();
};

