#pragma once
#include "libUnicornio.h"
#include "Heroi.h"
#include "Guerreiro.h"
//#include "HighScores.h"
//#include "Bonus.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

private:
	//HighScores highScores;

	void carregaRecordes();
	void inicializarGuerreiros();
	void atualizarInput();
	void atualizarGuerreiros();
	void desenharInstrucoes();

	void verificaFinalBatalha();

	//	atributos
	TileMap mapa;
	Sprite action;

	Heroi heroi;
	Guerreiro bruxo;

	Texto texto;
	float inicioBatalha;
	

//	float cronometro;
//	int contaDoentes = 0;
};

