#include "Personagem.h"

Personagem::Personagem()
{
	objeto = NULL;
	vida = 100;
	forca = 100;
	defesa = 100;
}

Personagem::~Personagem()
{
}

void Personagem::inicializar(string sheet, ObjetoTileMap* objeto)
{
	//	setar spritesheet
	spr.setSpriteSheet(sheet);

	//	setar ancora para os pes do personagem
	spr.setAncora(0.1, 0.9);

	//	set vel anim (4 frames por segundo)
	spr.setVelocidadeAnimacao(5);
	
	//	Guardar o ponteiro do objeto
	this->objeto = objeto;

	//	Setar sprite para o objeto
		//	ao fazer isso, o sprite passa a ser desenhado automaticamente junto com o mapa, na posicao central do objeto, 
		//	entao não precisamos chamar spr.desenhar(x, y)
	objeto->setSprite(&spr);

	//	Setar valores iniciais
	inicio.x = objeto->getX();
	inicio.y = objeto->getY();
	destino.x = 0;
	destino.y = 0;
	//interpolador = 0.0f;
}

void Personagem::atualizar()
{
	atualizarAnimacao();
	//atualizarMovimento();
}

void Personagem::atacar()
{
}

void Personagem::morrer()
{
}

float Personagem::getX()
{
	return objeto->getXCentro();
}

float Personagem::getY()
{
	return objeto->getYCentro();
}

void Personagem::atualizaSprite(string sheet)
{
	spr.setSpriteSheet(sheet);
	objeto->setSprite(&spr);
}

void Personagem::atualizarAnimacao()
{
	//	Avançar anim
	spr.avancarAnimacao();
}

void Personagem::atualizarMovimento()
{
	/*
	//	Interpola posições
	float x = inicio.x + (destino.x - inicio.x)*interpolador;
	float y = inicio.y + (destino.y - inicio.y)*interpolador;

	//	Avança interpolação com velocidade de vel (2.0) tiles por segundo;
	interpolador += 0 * gTempo.getDeltaTempo();

	//	Se interpolador chegou em, ou ultrapassou 100%,
	if (interpolador >= 1.0)
	{
		interpolador = 0.0f;
		x = destino.x;			//	x = x final
		y = destino.y;			//	y = y final
		inicio.x = destino.x;
		inicio.y = destino.y;
	}

	//	Setar posicao atual para o objeto no mapa
	objeto->setPosCentro(x, y);
	*/
}
