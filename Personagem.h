#pragma once
#include "libUnicornio.h"

class Personagem
{
public:
	Personagem();
	~Personagem();

	void inicializar(string sheet, ObjetoTileMap* objeto);

	void atualizar();

	virtual void atacar();
	//virtual bool atacando();

	void morrer();

	float getX();
	float getY();

	void atualizaSprite(string sheet);

protected:
	void atualizarAnimacao();
	void atualizarMovimento();

	int vida, forca, defesa;
	
	ObjetoTileMap* objeto;
	Sprite spr;

	Vetor2D destino;
	Vetor2D inicio;
	//float interpolador;
};

