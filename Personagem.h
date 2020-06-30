#pragma once
#include "libUnicornio.h"
#include "Painel.h"

class Personagem
{
public:
	Personagem();
	~Personagem();

	void inicializar(string sheetParado, string sheetAtacando, string sheetMorrendo, string objeto, TileMap* mapa);

	void atualizar();
	void atualizarSprite(string sheet);

	virtual void atacar();

	void morrer();

	float getX();
	float getY();

	int getAtaque();
	int getDefesa();
	int getVida();
	int getFase();

	void ganhaVida(int qtd);
	void perdeVida(int qtd);
	void ganhaDefesa(int qtd);
	void perdeDefesa(int qtd);
	void ganhaForca(int qtd);
	void perdeForca(int qtd);
	
	void atualizaSprite(string sheet);
	
	void parar();

protected:
	int vida, forca, defesa, fase;
	
	string sheetParado;
	string sheetAtacando;
	string sheetMorrendo;

	Painel painelVida;
	Painel painelDefesa;
	Painel painelAtaque;
		
	TileMap* mapa;
	ObjetoTileMap* objeto;
	Sprite spr;
	Vetor2D inicio;

	void atualizarAnimacao();
	void atualizarMovimento();
};

