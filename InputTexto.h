#pragma once
#include <string>
#include "libUnicornio.h"
class InputTexto
{
public:
	InputTexto() {};
	~InputTexto() {};

	void inicializar();
	void finalizar();

	void atualizar();
	void desenhar();

	string getTexto();
	Texto getTextoTxt() { return txt; }

private:
	Texto txt;
};
