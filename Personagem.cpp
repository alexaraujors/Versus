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

void Personagem::inicializar(string sheetParado, string sheetAtacando, string sheetMorrendo, string objeto, TileMap* mapa)
{
	this->sheetParado = sheetParado;
	this->sheetAtacando = sheetAtacando;
	this->sheetMorrendo = sheetMorrendo;

	// Guarda ponteiro para mapa
	this->mapa = mapa;

	//	Guardar o ponteiro do objeto
	this->objeto = mapa->getCamadaDeObjetos("objetos")->getObjeto(objeto);

	//	Setar valores iniciais
	inicio.x = this->objeto->getX();
	inicio.y = this->objeto->getY();
	
	atualizarSprite(sheetParado);
}

void Personagem::atualizar()
{
	spr.avancarAnimacao();
}

void Personagem::atualizarSprite(string sheet)
{
	//	setar spritesheet
	spr.setSpriteSheet(sheet);

	//	setar ancora para os pes do personagem
	spr.setAncora(0.1, 0.9);

	//	set vel anim (4 frames por segundo)
	spr.setVelocidadeAnimacao(10);

	//	Setar sprite para o objeto
		//	ao fazer isso, o sprite passa a ser desenhado automaticamente junto com o mapa, na posicao central do objeto, 
		//	entao não precisamos chamar spr.desenhar(x, y)
	this->objeto->setSprite(&spr);

	atualizarAnimacao();
}

void Personagem::atacar()
{
	atualizaSprite(sheetAtacando);
}

void Personagem::morrer()
{
	atualizaSprite(sheetMorrendo);
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

void Personagem::parar()
{
	atualizaSprite(sheetParado);
}

void Personagem::atualizarAnimacao()
{
	//	Avançar anim
	spr.avancarAnimacao();
}

int Personagem::getAtaque()
{
	return forca;
}

int Personagem::getDefesa()
{
	return defesa;
}

int Personagem::getVida()
{
	return vida;
}

void Personagem::ganhaVida(int qtd)
{
	vida += qtd;
	painelVida.defineValor(vida);
}

void Personagem::perdeVida(int qtd)
{
	vida -= qtd;
	if (vida < 0) {
		vida = 0;
	}
	painelVida.defineValor(vida);
}

void Personagem::ganhaDefesa(int qtd)
{
	defesa += qtd;
	painelDefesa.defineValor(defesa);
}

void Personagem::perdeDefesa(int qtd)
{
	defesa -= qtd;
	if (defesa < 0) {
		defesa = 0;
	}
	painelDefesa.defineValor(defesa);
}

void Personagem::ganhaForca(int qtd)
{
	forca += qtd;
	painelAtaque.defineValor(forca);
}

void Personagem::perdeForca(int qtd)
{
	forca -= qtd;
	if (forca < 0) {
		forca = 0;
	}

	painelAtaque.defineValor(forca);
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
