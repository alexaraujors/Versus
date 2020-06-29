#include "Painel.h"

void Painel::inicializa(string prefixo, Cores cor, TileMap *mapa)
{
	this->prefixo = prefixo;
	this->mapa = mapa;
	this->cor = cor;

	this->objeto[0] = this->mapa->getCamadaDeObjetos("objetos")->getObjeto(this->prefixo + "1");
	this->objeto[1] = this->mapa->getCamadaDeObjetos("objetos")->getObjeto(this->prefixo + "2");
	this->objeto[2] = this->mapa->getCamadaDeObjetos("objetos")->getObjeto(this->prefixo + "3");

	this->spr[0] = new Sprite();
	this->spr[1] = new Sprite();
	this->spr[2] = new Sprite();

	this->spr[0]->setSpriteSheet("numeros");
	this->spr[1]->setSpriteSheet("numeros");
	this->spr[2]->setSpriteSheet("numeros");

	this->objeto[0]->setSprite(this->spr[0]);
	this->objeto[1]->setSprite(this->spr[1]);
	this->objeto[2]->setSprite(this->spr[2]);
}

void Painel::defineValor(int valor)
{	
	if (valor < 0) {
		valor = 0;
	}
	if (valor > 999) {
		valor = 999;
	}

	int d1 = valor / 100;
	int m1 = valor % 100;
	int d2 = m1 / 10;
	int d3 = m1 % 10;

	this->spr[0]->setAnimacao(this->cor);
	this->spr[0]->setFrame(d1);

	this->spr[1]->setAnimacao(this->cor);
	this->spr[1]->setFrame(d2);

	this->spr[2]->setAnimacao(this->cor);
	this->spr[2]->setFrame(d3);
}
