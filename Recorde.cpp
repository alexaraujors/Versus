#include "Recorde.h"
#include <string>

Recorde::Recorde()
{
}

Recorde::~Recorde()
{
}

string Recorde::getNome()
{
	return nome;
}

void Recorde::setNome(string nome)
{
	this->nome = nome;
}

int Recorde::getPontuacao()
{
	return pontuacao;
}

void Recorde::setPontuacao(int pontuacao)
{
	this->pontuacao = pontuacao;
}
