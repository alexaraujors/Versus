#include "Salvamento.h"

Salvamento::Salvamento(string data, int vida, int forca, int defesa, int ouro, int fase)
{
	this->dataHora = data;
	this->vida = vida;
	this->forca = forca;
	this->defesa = defesa;
	this->ouro = ouro;
	this->fase = fase;
}

Salvamento::Salvamento()
{
}

Salvamento::~Salvamento()
{}

string Salvamento::getDataHora()
{
	return dataHora;
}

void Salvamento::setDataHora(string dataHora)
{
	this->dataHora = dataHora;
}

int Salvamento::getVida()
{
	return vida;
}

void Salvamento::setVida(int vida)
{
	this->vida = vida;
}

int Salvamento::getForca()
{
	return forca;
}

void Salvamento::setForca(int forca)
{
	this->forca = forca;
}

int Salvamento::getDefesa()
{
	return defesa;
}

void Salvamento::setDefesa(int defesa)
{
	this->defesa = defesa;
}

int Salvamento::getOuro()
{
	return ouro;
}

void Salvamento::setOuro(int ouro)
{
	this->ouro = ouro;
}

int Salvamento::getFase()
{
	return fase;
}

void Salvamento::setFase(int fase)
{
	this->fase = fase;
}
