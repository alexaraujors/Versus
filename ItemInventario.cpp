#include "ItemInventario.h"



ItemInventario::ItemInventario()
{
	this->proximo = nullptr;
}


ItemInventario::~ItemInventario()
{
}

ItemInventario* ItemInventario::getProximo()
{
	return this->proximo;
}

void ItemInventario::setProximo(ItemInventario* item)
{
	this->proximo = item;
}

string ItemInventario::getNome()
{
	return this->nome;
}
