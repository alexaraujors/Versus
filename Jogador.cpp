#include "Jogador.h"
#include "Salvamento.h"

void Jogador::incluiSalvamento(Salvamento salvamento)
{
	this->salvamentos.push_back(salvamento);
	if (this->salvamentos.size() > 3) {
		this->salvamentos.emplace_front();
	}
}

Salvamento Jogador::buscaSalvamento(int posicao)
{	
	int i = 0;
	for each (Salvamento salv in salvamentos)
	{
		++i;
		if (i == posicao) {
			return salv;
		}
	}
	return *(new Salvamento());
}

Jogador::Jogador()
{}

Jogador::~Jogador()
{}

string Jogador::getNome()
{
	return nome;
}

void Jogador::setNome(string nome)
{
	this->nome = nome;
}

string Jogador::getSenha()
{
	return senha;
}

void Jogador::setSenha(string senha)
{
	this->senha = senha;
}

int Jogador::getRecorde()
{
	return this->recorde;
}

void Jogador::setRecorde(int recorde)
{
	this->recorde = recorde;
}

Heroi* Jogador::getHeroi()
{
	return this->heroi;
}

void Jogador::setHeroi(Heroi* heroi)
{
	this->heroi = heroi;
}
