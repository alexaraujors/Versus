#pragma once
#include "libUnicornio.h"
#include "Heroi.h"
#include "Guerreiro.h"
#include "Painel.h"
#include "SistemaLogin.h"
#include "HighScores.h"
//#include "Bonus.h"

enum Tela { tMenuPrincipal, tJogo, tCreditos, tPausa, tGameOver, tCadastrar, tLogin, tInicial, tRanking, tSalvamentos };

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

	void verificaAnimacaoFinalBatalha();
	void verificaAnimacaoFinalMorte();

	void setFase(int fase);

	// Atributos
	
	// Sistema login
	SistemaLogin login;
	fstream arqLogin;
	ifstream arquivo;

	// Telas
	stack<Tela> pilhaTelas;
	BotaoSprite botaoJogar, botaoSair, botaoCreditos, 
		botaoVoltar, botaoLogar, botaoCadastrar, botaoRanking, botaoNovo,
		botaoSalvamento1, botaoSalvamento2, botaoSalvamento3;
	Texto cabecalho, corpo;
	Cor branco;
	HighScores highScores;

	void configurarBotoes(BotaoSprite* botao, float x, float y, string nome, string sprite);
	void botaoLoop(BotaoSprite* botao, bool botaoDeVoltar);

	void telaMenuPrincipal();
	void telaJogo();
	void telaCreditos();
	void telaPausa();
	void telaGameOver();
	void telaInicial();
	void telaCadastrar();
	void telaLogin();
	void telaRanking();
	void telaSalvamentos();

	// Resto
	TileMap mapa;
	Sprite action;
	int fase = 1;

	Heroi heroi;
	Guerreiro guerreiro;
	Guerreiro bruxo;
	Guerreiro samurai;

	Texto texto;

	// Temporizadores
	float inicioBatalha = 0.0;
	float inicioMorte = 0.0;

};

