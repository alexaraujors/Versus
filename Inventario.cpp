using namespace std;

#include "Inventario.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string>

Inventario::Inventario()
{
	primeira = nullptr;
	numeroPocoes = 0;
}

Inventario::~Inventario()
{
}

bool Inventario::adicionarPocao(Pocao * pocao)
{
	if (this->primeira == nullptr) {
		this->primeira = pocao;
		numeroPocoes++;
	}
	else
	{
		Pocao* proximo = this->primeira;
		while (proximo->getProximo()!=nullptr)
		{
			proximo = proximo->getProximo();
		}
		proximo->setProximo(pocao);
		numeroPocoes++;
	}
	return true;
}

/*
bool Inventario::utilizarPocao(int numero, Heroi * heroi)
{
	if (numero <= numeroPocoes) {
		Pocao* selecionado = primeira;
		Pocao* anterior = nullptr;
		for (int i = 1; i < numero; i++)
		{
			anterior = selecionado;
			selecionado = selecionado->getProximo();
		}

		selecionado->usar(heroi);
		anterior->setProximo(selecionado->getProximo());
		delete selecionado;
		numeroPocoes--;
	}
	return true;
}
*/

Pocao * Inventario::getPrimeiraPocao()
{
	return primeira;
}

/*
string Inventario::listar()
{
	string lista="";
	ItemInventario* proximo = this->primeiroItem;
	while (proximo!=nullptr)
	{
		lista += proximo->getNome()+" - ";
		proximo = proximo->getProximo();
	}
	return lista;
}
*/
