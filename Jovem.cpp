#include "Jovem.h"
#include <time.h>

int Jovem::getVelocidade() 
{
	return 3;
}

string Jovem::getIdade()
{
	return "jovem";
}

bool Jovem::estaDoente()
{
	if (this->adoeceu != 0) 
	{
		clock_t agora = clock();
		if ((agora - this->adoeceu) / CLOCKS_PER_SEC < 10.0) 
		{
			return true;
		}
		else 
		{
			this->adoeceu = 0;
		}
	}
	return false;
}


