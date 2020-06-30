#pragma once
#include "Pocao.h"
//#include <iostream>
//#include "Heroi.h"

class Inventario
{
	public:
		Inventario();
		~Inventario();

		bool adicionarPocao(Pocao * pocao);
//		bool utilizarPocao(int numero, Heroi* heroi);

		Pocao * getPrimeiraPocao();

	private:
		Pocao * primeira;
		int numeroPocoes = 0;
};



