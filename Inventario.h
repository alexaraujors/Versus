#pragma once
#include "Item.h"
#include <iostream>
#include "ItemInventario.h"

class Inventario
{
public:

	Inventario();
	~Inventario();

	bool adicionarItem(ItemInventario* item);
	bool utilizarItem(string nomeitem);

	string listar();

private:
	ItemInventario* primeiroItem = nullptr;
	

};



