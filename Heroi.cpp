#include "Heroi.h"

Heroi::Heroi()
{
	vida = 100;
	forca = 50;
	defesa = 30;
	ouro = 0;
}

Heroi::~Heroi()
{
}

void Heroi::inicializarPaineis()
{
	vida = 200;
	defesa = 30;
	forca = 50;
	ouro = 0;

	painelVida.inicializa("h_v", VERMELHO, mapa);
	painelDefesa.inicializa("h_d", AZUL, mapa);
	painelAtaque.inicializa("h_a", AMARELO, mapa);
	painelOuro.inicializa("ouro", VERDE, mapa);

	painelVida.defineValor(vida);
	painelDefesa.defineValor(defesa);
	painelAtaque.defineValor(forca);
	painelOuro.defineValor(ouro);
}

void Heroi::ganhaOuro(int qtd)
{
	ouro += qtd;
	painelOuro.defineValor(ouro);
}

int Heroi::getOuro()
{
	return this->ouro;
}

void Heroi::passaFase()
{
	fase++;
}
