#include "Guerreiro.h"

Guerreiro::Guerreiro()
{
	vida = 100;
	forca = 50;
	defesa = 30;
}

Guerreiro::~Guerreiro()
{
}

void Guerreiro::atacar()
{
	atualizarSprite(sheetAtacando);
}

void Guerreiro::inicializarPaineis()
{
	vida = 100;
	defesa = 30;
	forca = 50;

	painelVida.inicializa("w_v", VERMELHO, mapa);
	painelDefesa.inicializa("w_d", AZUL, mapa);
	painelAtaque.inicializa("w_a", AMARELO, mapa);

	painelVida.defineValor(vida);
	painelDefesa.defineValor(defesa);
	painelAtaque.defineValor(forca);
}
