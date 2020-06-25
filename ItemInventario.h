#pragma once
#include<iostream>

using namespace std;
class ItemInventario
{
public:
	ItemInventario();
	~ItemInventario();

	ItemInventario* getProximo();
	void setProximo(ItemInventario* item);

	string getNome();

protected:
	string nome;
	ItemInventario* proximo;
};

