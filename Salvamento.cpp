#include "Salvamento.h"

Salvamento::Salvamento(Heroi * heroi, string dataHora)
{
	this->heroi = heroi;
	this->dataHora = dataHora;
}

Salvamento::~Salvamento()
{
}

string Salvamento::getDataHora()
{
	return dataHora;
}

Heroi * Salvamento::getHeroi()
{
	return heroi;
}
