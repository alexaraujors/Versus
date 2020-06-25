#include "Bonus.h"
#include <time.h>

void Bonus::inicializar(string sheet, ObjetoTileMap * obj)
{
	srand(clock());
	this->spr.setSpriteSheet(sheet);
	this->spr.setAncora(0.5, 0.75);
	this->spr.setVelocidadeAnimacao(0);
	this->spr.setFrame(0);
	this->obj = obj;
	obj->setSprite(&spr);
	this->esconde();
}

void Bonus::esconde()
{
	this->obj->setVisivel(false);
}

void Bonus::exibe()
{
	if (! this->usado) {
		if (this->obj->estaVisivel()) {
			if (rand() % 1000 == 2) {
				this->esconde();
			}
		}
		else 
		{
			if (rand() % 1000 == 7) {
				this->obj->setVisivel(true);
			}
		}
	}
}

bool Bonus::visivel()
{
	return this->obj->estaVisivel();
}

void Bonus::usar()
{
	this->usado = true;
	this->esconde();
}
