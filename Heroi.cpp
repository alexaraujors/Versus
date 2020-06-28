#include "Heroi.h"

void Heroi::atacar()
{
	inicializar("heroi_a", objeto);

	spr.setAnimacao(0, false);

	if (spr.terminouAnimacao()) {
		inicializar("heroi_p", objeto);
	};
}

void Heroi::ganhaVida(int qtd)
{
	vida += qtd;
}

void Heroi::perdeVida(int qtd)
{
	vida -= qtd;
}

void Heroi::ganhaDefesa(int qtd)
{
	defesa += qtd;
}

void Heroi::perdeDefesa(int qtd)
{
	defesa -= qtd;
}

void Heroi::ganhaForca(int qtd)
{
	forca += qtd;
}

void Heroi::perdeForca(int qtd)
{
	forca -= qtd;
}

void Heroi::ganhaOuro(int qtd)
{
	ouro += qtd;
}

void Heroi::passaFase()
{
	fase++;
}
