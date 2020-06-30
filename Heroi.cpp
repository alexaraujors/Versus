#include "Heroi.h"

Heroi::Heroi()
{
	this->vida = 100;
	this->forca = 50;
	this->defesa = 30;
	this->ouro = 0;
}

Heroi::~Heroi()
{
}

void Heroi::inicializarPaineis()
{
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
	this->ouro += qtd;
	painelOuro.defineValor(ouro);
}

int Heroi::getOuro()
{
	return this->ouro;
}

void Heroi::passaFase()
{
	this->fase++;
	this->vida = 70 + this->fase * 30;
	this->forca = 20 + this->fase * 15;
	this->defesa = 20 + this->fase * 10;
	this->parar();
	this->inicializarPaineis();
}

void Heroi::reiniciar()
{
	this->vida = 100;
	this->defesa = 30;
	this->forca = 50;
	this->ouro = 0;
	this->fase = 1;

	this->parar();
	this->inicializarPaineis();
}

void Heroi::carregaSalvamento(Salvamento salvamento)
{
	if (salvamento.getDataHora()!= "") {
		this->vida = salvamento.getVida();
		this->forca = salvamento.getForca();
		this->defesa = salvamento.getDefesa();
		this->ouro = salvamento.getOuro();
		this->fase = salvamento.getFase();
		inicializarPaineis();
	}

}
