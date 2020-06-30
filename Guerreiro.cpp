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
	
	painelVida.inicializa("w_v", VERMELHO, mapa);
	painelDefesa.inicializa("w_d", AZUL, mapa);
	painelAtaque.inicializa("w_a", AMARELO, mapa);

	painelVida.defineValor(vida);
	painelDefesa.defineValor(defesa);
	painelAtaque.defineValor(forca);
}

void Guerreiro::reiniciar(int fase)
{	
	this->vida = 70  + fase * 30;
	this->forca = 10 + fase * 10;
	this->defesa = 30 + fase * 20;
	this->parar();
	this->inicializarPaineis();
}
