#include "Guerreiro.h"

void Guerreiro::atacar()
{
	inicializar("witcher_a", objeto);

	spr.setAnimacao(0, false);

	if (spr.terminouAnimacao()) {
		inicializar("witcher_p", objeto);
	};
}
