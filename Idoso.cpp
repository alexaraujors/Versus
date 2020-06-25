#include "Idoso.h"
#include <time.h>

int Idoso::getVelocidade() {
	return 1;
}

string Idoso::getIdade()
{
	return "idoso";
}

bool Idoso::estaDoente()
{
	if (this->adoeceu == 0) {
		return false;
	}
	else {
		clock_t agora = clock();

		if ((agora - this->adoeceu) / CLOCKS_PER_SEC >= 20.0) {
			this->adoeceu = 0;
			return false;
		}
		return true;
	}
}

