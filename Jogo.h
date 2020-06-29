#pragma once
#include "libUnicornio.h"
#include "Heroi.h"
#include "Guerreiro.h"
#include "Painel.h"
#include "SistemaLogin.h"

//#include "HighScores.h"
//#include "Bonus.h"

enum Tela { tMenuPrincipal, tJogo, tCreditos, tPausa, tCadastrar, tLogin, tInicial, tRanking };

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
	void atualizarGuerreiro();
	void desenharInstrucoes();

	void verificaFinalBatalha();
	void verificaMorrendo();

	void setFase(int fase);

	// Atributos
	
	// Sistema login
	SistemaLogin login;
	fstream arqLogin;
	ifstream arquivo;

	// Telas
	stack<Tela> pilhaTelas;
	BotaoSprite botaoJogar, botaoSair, botaoCreditos, botaoVoltar, botaoLogar, botaoCadastrar, botaoRanking;
	Texto cabecalho, corpo;
	bool bCancelaPodeTocar, bMovePodeTocar, bSelecionaPodeTocar;
	Cor branco;

	void configurarBotoes(BotaoSprite* botao, float x, float y, string nome, string sprite);
	void botaoLoop(BotaoSprite* botao, bool botaoDeVoltar);

	void telaMenuPrincipal();
	void telaJogo();
	void telaCreditos();
	void telaPausa();
	void telaInicial();
	void telaCadastrar();
	void telaLogin();
	void telaRanking();

	// Resto
	TileMap mapa;
	Sprite action;
	int fase;

	Heroi heroi;
	Guerreiro guerreiro;
	Guerreiro bruxo;
	Guerreiro samurai;

	Texto texto;

	// Temporizadores
	float inicioBatalha = 0.0;
	float inicioMorte = 0.0;

};

