#include "Pocao.h"



void Pocao::usar(Heroi* heroi)
{
}

Pocao* Pocao::getProximo()
{
	return proximo;
}

void Pocao::setProximo(Pocao* pocao)
{
	proximo = pocao;
}


void Pocao::inicializar(string sheet, ObjetoTileMap * obj)
{
	/*
	srand(clock());
	this->spr.setSpriteSheet(sheet);
	this->spr.setAncora(0.5, 0.75);
	this->spr.setVelocidadeAnimacao(0);
	this->spr.setFrame(0);
	this->obj = obj;
	obj->setSprite(&spr);
	this->esconde();
	*/
}

