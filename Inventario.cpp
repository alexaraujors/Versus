using namespace std;
#include "Inventario.h"
#include "ItemInventario.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

Inventario::Inventario()
{
	this->primeiroItem = nullptr;
}

Inventario::~Inventario()
{

}

bool Inventario::adicionarItem(ItemInventario* item)
{
	if (this->primeiroItem == nullptr) {
		this->primeiroItem = item;
	}
	else
	{
		ItemInventario* proximo = this->primeiroItem;
		while (proximo->getProximo()!=nullptr)
		{
			proximo = proximo->getProximo();
		}
		proximo->setProximo(item);
	}
	return true;
}

bool Inventario::utilizarItem(string nome)
{
	ItemInventario* anterior = this->primeiroItem;
	if (anterior != nullptr) {

		if (anterior->getNome()._Equal(nome)) {
			primeiroItem = primeiroItem->getProximo();
			return true;
		}
		else 
		{
			ItemInventario* proximo = anterior->getProximo();	
			do
			{
				if (proximo->getNome() == nome) 
				{
					anterior->setProximo(proximo->getProximo());
					return true;
				}
				else {
					anterior = proximo;
					proximo = proximo->getProximo();
				}
			} while (proximo==nullptr);
			return false;
		}
	}
}

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
