#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "Jovem.h"
#include "Idoso.h"
#include "HighScores.h"
#include "Bonus.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

private:
	HighScores highScores;

	void carregaRecordes();
	void inicializarPessoas();
	void atualizarInput();
	void atualizarPessoas();
	void desenharInstrucoes();
	void desenharCronometro();

	void verificaPoderoso();

	//	metodos para colisao
	void testarColisoes();

	//	atributos
	TileMap mapa;
	Personagem player;
	Texto texto;

	Bonus obj1;
	Bonus obj2;

	float cronometro;
	float timerPoderoso;

	Pessoa * pessoas[5];
	int contaDoentes = 0;
};

