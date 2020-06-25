#pragma once
#include "Pessoa.h"


class Jovem :
	public Pessoa
{
public:
	float vel = 2;

	bool estaDoente();
	int getVelocidade();
	string getIdade();
};

