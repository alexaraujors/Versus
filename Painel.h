#pragma once
#include "libUnicornio.h"
#include <string>

enum Cores
{
	VERDE = 0, VERMELHO = 1, AZUL = 2, AMARELO = 3
};
class Painel
{
public:
	void inicializa(string prefixo, Cores cor, TileMap* mapa);
	void defineValor(int valor);

	string prefixo;
	Cores cor;

	ObjetoTileMap* objeto[3];
	Sprite* spr[3];
	TileMap* mapa;

};

