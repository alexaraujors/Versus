#include "Pessoa.h"
#include <time.h>

int Pessoa::getVelocidade()
{
	return 1;
}

void Pessoa::setVelocidade(int velocitade)
{
	this->vel = velocitade;
}

bool Pessoa::estaDoente()
{
	return false;
}

void Pessoa::adoecer()
{
	this->adoeceu = clock();
}

int Pessoa::getDirecao()
{
	return direcao;
}

void Pessoa::trocaDirecao()
{
	this->direcao = rand() % 8;
}

string Pessoa::getIdade()
{
	return "";
}


