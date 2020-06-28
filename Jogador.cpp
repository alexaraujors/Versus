#include "Jogador.h"
#include "Salvamento.h"

Salvamento* Jogador::getSalvamentos()
{
	return nullptr;
}

void Jogador::incluiSalvamento(Salvamento* salvamento)
{
	salvamentos[1] = salvamentos[2];
	salvamentos[2] = salvamentos[3];
	salvamentos[3] = salvamento;
}

Salvamento* Jogador::buscaSalvamento(int posicao)
{
	return nullptr;
}

Jogador::Jogador()
{
}

Jogador::~Jogador()
{
}

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
	return recorde;
}

void Jogador::setRecorde(int recorde)
{
	this->recorde = recorde;
}

Heroi* Jogador::getHeroi()
{
	return heroi;
}

void Jogador::setHeroi(Heroi* heroi)
{
	this->heroi = heroi;
}
