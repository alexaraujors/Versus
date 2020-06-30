#include "Jogo.h"
#include <string>
#include <time.h>

Jogo::Jogo()
{}

Jogo::~Jogo()
{}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Versus");

	pilhaTelas.push(tInicial);
	arqLogin.open("assets/login.txt", std::ios::out | std::ios::in);
	if (!arqLogin.is_open()) gDebug.erro("Carregador de login não abriu");
	
	// Carrega recordes
	carregaRecordes();

	// Carregar o tilemap
	mapa.carregar("assets/mapa/versus.json");

	// Carregar recursos
	//sprintesheet para ações
	gRecursos.carregarSpriteSheet("actions", "assets/tilesets/actions_192x64.png", 3, 1);
	gRecursos.carregarSpriteSheet("numeros", "assets/tilesets/numeros_320x32.png", 4, 10);
	gRecursos.carregarSpriteSheet("morte", "assets/tilesets/morte_288x160.png", 1, 24);

	gRecursos.carregarSpriteSheet("botaoPequeno", "assets/tilesets/botaoPequeno.png", 3, 1);
	gRecursos.carregarFonte("arial", "assets/fontes/arial.ttf", 20);

	// spritesheet para os personagens
	gRecursos.carregarSpriteSheet("heroi_p", "assets/tilesets/hero_p_8.png", 1, 8);
	gRecursos.carregarSpriteSheet("heroi_a", "assets/tilesets/hero_a_2x19.png", 2, 19);
	gRecursos.getSpriteSheet("heroi_a")->juntarAnimacoes(0, 1);

	gRecursos.carregarSpriteSheet("witcher_p", "assets/tilesets/witcher_p_10.png", 1, 10);
	gRecursos.carregarSpriteSheet("witcher_a", "assets/tilesets/witcher_a_12.png", 1, 12);

	gRecursos.carregarSpriteSheet("samurai_p", "assets/tilesets/samurai_p_4.png", 1, 4);
	gRecursos.carregarSpriteSheet("samurai_a", "assets/tilesets/samurai_a_11.png", 1, 11);

	//inicializar sistema login
	login.inicializar();
	if (!login.inicializar()) gDebug.erro("Funcao login inicializar nao abriu!");
	gDebug.ativar();

	// Inicializar o personagem do player,
	// passando o nome do spritesheet e o objeto que representa ele no mapa
	heroi.inicializar("heroi_p", "heroi_a", "morte", "hero", &mapa);
	heroi.inicializarPaineis();

	// Incicializa os guerreiros
	inicializarGuerreiros();
	
	// Inicializar texto
	branco.set(255, 255, 255, 255);
	texto.setFonte("fonte colisao");

	cabecalho.setCor(branco);
	cabecalho.setFonte("arial");

	corpo.setCor(branco);
	corpo.setFonte("arial");

	// Inicializa a fase
	fase = 1;
	setFase(fase);
}

void Jogo::finalizar()
{
	// Descarregar recursos
	gRecursos.descarregarTudo();

	// Descarregar o tilemap
	mapa.descarregar();

	uniFinalizar();
}

void Jogo::executar() 
{
	while (!gEventos.sair) 
	{
		uniIniciarFrame();

		switch (pilhaTelas.top()) 
		{
		case tJogo: telaJogo();
			break;
		case tCreditos: telaCreditos();
			break;
		case tPausa: telaPausa();
			break;
		case tMenuPrincipal: telaMenuPrincipal();
			break;
		case tInicial: telaInicial();
			break;
		case tCadastrar: telaCadastrar();
			break;
		case tLogin: telaLogin();
			break;
		case tRanking: telaRanking();
			break;
		case tSalvamentos: telaSalvamentos();
			break;
		}
		uniTerminarFrame();
	}

	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		// Verifica as teclas do teclado e caso forem pressionadas
		// seta o destino do player
		atualizarInput();

		// Verifica final da batalha
		verificaAnimacaoFinalBatalha();
		verificaAnimacaoFinalMorte();
		
		// Atualizar heroi e as guerreiros
		heroi.atualizar();
		
		atualizarGuerreiro();

		// Desenhar o tilemap (player eh desenhado junto)
		mapa.desenhar();

		uniTerminarFrame();
	}
}

void Jogo::carregaRecordes()
{
	this->highScores.carregarRecordes();
}

void Jogo::atualizarInput()
{
	if (gTeclado.segurando[TECLA_A]) 
	{
		heroi.atacar();
		guerreiro.atacar();
		inicioBatalha = clock();
	}
}

void Jogo::atualizarGuerreiro()
{
	guerreiro.atualizar();
}

void Jogo::desenharInstrucoes()
{
	string txt = "Instruções:\n"
		"    Use as setas para mover o Bolsominion e contaminar as pessoas.";
	gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);
}

void Jogo::verificaAnimacaoFinalBatalha()
{
	if (this->inicioBatalha > 0.0 && ((clock() - this->inicioBatalha) / CLOCKS_PER_SEC >= 5))
	{
		this->inicioBatalha = 0.0;
		heroi.parar();
		guerreiro.parar();

		srand(time(NULL));
		int heroiPlus = rand() % 30;
		int guerreiroPlus = rand() % 30;

		int danoHeroi = guerreiro.getAtaque() + guerreiroPlus - heroi.getDefesa();
		int danoGuerreiro = heroi.getAtaque() + heroiPlus - guerreiro.getDefesa();

		heroi.perdeVida(danoHeroi);
		guerreiro.perdeVida(danoGuerreiro);

		if (danoHeroi < danoGuerreiro) 
		{
			heroi.ganhaOuro(100);
		}

		if (heroi.getVida() == 0) 
		{
			heroi.morrer();
			highScores.adicionarRecorde(login.getJogador().getNome(), heroi.getOuro());
			inicioMorte = clock();
		}
		if (guerreiro.getVida() == 0) 
		{
			guerreiro.morrer();
			inicioMorte = clock();
			heroi.ganhaOuro(150);
		}
	}
}

void Jogo::verificaAnimacaoFinalMorte()
{
	if (this->inicioMorte > 0.0 && ((clock() - this->inicioMorte) / CLOCKS_PER_SEC >= 2)) 
	{
		setFase(++fase);
		inicioMorte = 0.0;
	}
}

void Jogo::setFase(int fase)
{
	switch (fase) 
	{
	case  1:
		guerreiro = bruxo;
		break;

	case 2:
		guerreiro = samurai;
		break;

	default:
		break;
	}
	guerreiro.parar();
	guerreiro.inicializarPaineis();
}	

void Jogo::inicializarGuerreiros()
{
	bruxo.inicializar("witcher_p", "witcher_a", "morte", "warrior", &mapa);
	samurai.inicializar("samurai_p", "samurai_a","morte", "warrior", &mapa);
}

void Jogo::configurarBotoes(BotaoSprite* botao, float x, float y, string nome, string sprite) 
{
	botao->setPos(x, y);
	botao->setSpriteSheet(sprite);
	cabecalho.setString(nome);
	cabecalho.desenhar(x, y);
}

void Jogo::botaoLoop(BotaoSprite* botao, bool botaoDeVoltar) 
{
	botao->atualizar();
	botao->desenhar();
}

void Jogo::telaMenuPrincipal() 
{
	configurarBotoes(&botaoJogar, gJanela.getLargura() / 2, gJanela.getAltura() / 2, "Jogar", "botaoPequeno");
	configurarBotoes(&botaoRanking, botaoJogar.getPos().x, botaoJogar.getPos().y + 60, "Ranking", "botaoPequeno");	
	configurarBotoes(&botaoCreditos, botaoRanking.getPos().x, botaoRanking.getPos().y + 60, "Créditos", "botaoPequeno");
	configurarBotoes(&botaoSair, botaoCreditos.getPos().x, botaoCreditos.getPos().y + 60, "Sair", "botaoPequeno");

	botaoLoop(&botaoJogar, false);
	botaoLoop(&botaoRanking, false);
	botaoLoop(&botaoCreditos, false);
	botaoLoop(&botaoSair, true);

	if (botaoJogar.estaClicado()) pilhaTelas.push(tSalvamentos);
	if (botaoRanking.estaClicado())	pilhaTelas.push(tRanking);
	if (botaoCreditos.estaClicado()) pilhaTelas.push(tCreditos);
	if (botaoSair.estaClicado()) exit(0);

	cabecalho.setString("Menu Principal");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}

void Jogo::telaJogo() 
{

	if (gTeclado.pressionou[TECLA_ESC]) pilhaTelas.push(tPausa);

	// Verifica as teclas do teclado e caso forem pressionadas
	// seta o destino do player
	atualizarInput();

	// Verifica final da batalha
	verificaAnimacaoFinalBatalha();
	verificaAnimacaoFinalMorte();

	// Atualizar heroi e as guerreiros
	heroi.atualizar();

	atualizarGuerreiro();

	// Desenhar o tilemap (player eh desenhado junto)
	mapa.desenhar();
}

void Jogo::telaCreditos() 
{
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.15, gJanela.getAltura() * 0.15, "< Voltar  ", "botaoPequeno");

	botaoLoop(&botaoVoltar, true);

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) { pilhaTelas.pop(); }
	
	cabecalho.setString("Créditos");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);

	corpo.setAlinhamento(TEXTO_CENTRALIZADO);
	corpo.adicionarString("Design e desenvolvimento\n\n");
	corpo.setString("Patricia dos Santos Silva\n");
	corpo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4 + 100);
}

void Jogo::telaPausa() 
{
	mapa.desenhar();
	
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.5, gJanela.getAltura() * 0.5, "Voltar ao jogo", "botaoPequeno");
	configurarBotoes(&botaoSair, botaoVoltar.getPos().x, botaoVoltar.getPos().y + 60, "Sair do jogo", "botaoPequeno");

	botaoLoop(&botaoVoltar, true);
	botaoLoop(&botaoSair, true);

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) pilhaTelas.pop();
	if (botaoSair.estaClicado()) { pilhaTelas.pop(); pilhaTelas.pop(); pilhaTelas.pop(); }
	
	cabecalho.setString("Pausa");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}

void Jogo::telaInicial() 
{
	configurarBotoes(&botaoLogar, gJanela.getLargura() / 2, gJanela.getAltura() / 2, "Logar", "botaoPequeno");
	configurarBotoes(&botaoCadastrar, botaoLogar.getPos().x, botaoLogar.getPos().y + 60, "Cadastrar", "botaoPequeno");
	configurarBotoes(&botaoRanking, botaoCadastrar.getPos().x, botaoCadastrar.getPos().y + 60, "Ranking", "botaoPequeno");
	configurarBotoes(&botaoCreditos, botaoRanking.getPos().x, botaoRanking.getPos().y + 60, "Créditos", "botaoPequeno");
	configurarBotoes(&botaoSair, botaoCreditos.getPos().x, botaoCreditos.getPos().y + 60, "Sair", "botaoPequeno");

	botaoLoop(&botaoLogar, false);
	botaoLoop(&botaoCadastrar, false);
	botaoLoop(&botaoRanking, false);
	botaoLoop(&botaoCreditos, false);
	botaoLoop(&botaoSair, false);

	if (botaoLogar.estaClicado())	pilhaTelas.push(tLogin);
	if (botaoCadastrar.estaClicado())	pilhaTelas.push(tCadastrar);
	if (botaoRanking.estaClicado())	pilhaTelas.push(tRanking);
	if (botaoCreditos.estaClicado()) pilhaTelas.push(tCreditos);
	if (botaoSair.estaClicado()) { exit(0); }
	
	cabecalho.setString("Tela Início");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}

void Jogo::telaCadastrar() 
{
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.15, gJanela.getAltura() * 0.15, "< Voltar  ", "botaoPequeno");

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) pilhaTelas.pop();

	botaoLoop(&botaoVoltar, true);
	
	cabecalho.setString("Tela Cadastrar");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);

	login.iniciarCadastro();
	if (login.iniciarCadastro() == true) pilhaTelas.push(tMenuPrincipal);
}

void Jogo::telaLogin() 
{
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.15, gJanela.getAltura() * 0.15, "< Voltar  ", "botaoPequeno");

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) pilhaTelas.pop();

	botaoLoop(&botaoVoltar, true);
	
	cabecalho.setString("Tela Login");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);

	login.iniciarLogin();
	if (login.getLoginAprovado() == true) pilhaTelas.push(tMenuPrincipal);
}

void Jogo::telaRanking()
{
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.15, gJanela.getAltura() * 0.15, "< Voltar  ", "botaoPequeno");

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) pilhaTelas.pop();

	botaoLoop(&botaoVoltar, true);

	cabecalho.setString("Tela Ranking");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);

	corpo.setString(highScores.getRecordes());
	corpo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4 + 100);
}

void Jogo::telaSalvamentos()
{
	configurarBotoes(&botaoVoltar, gJanela.getLargura() * 0.15, gJanela.getAltura() * 0.15, "< Voltar  ", "botaoPequeno");
	
	configurarBotoes(&botaoSalvamento1, gJanela.getLargura() / 2, gJanela.getAltura() / 2, 
		this->login.getJogador().buscaSalvamento(1).getDataHora(), "botaoPequeno");
	configurarBotoes(&botaoSalvamento2, botaoSalvamento1.getPos().x, botaoSalvamento1.getPos().y + 60, 
		this->login.getJogador().buscaSalvamento(2).getDataHora(), "botaoPequeno");
	configurarBotoes(&botaoSalvamento3, botaoSalvamento2.getPos().x, botaoSalvamento2.getPos().y + 60, 
		this->login.getJogador().buscaSalvamento(3).getDataHora(), "botaoPequeno");
	configurarBotoes(&botaoNovo, botaoSalvamento3.getPos().x, botaoSalvamento3.getPos().y + 60, "Novo jogo", "botaoPequeno");
	
	botaoLoop(&botaoVoltar, true);
	botaoLoop(&botaoSalvamento1, false);
	botaoLoop(&botaoSalvamento2, false);
	botaoLoop(&botaoSalvamento3, false);	
	botaoLoop(&botaoNovo, false);

	if (gTeclado.pressionou[TECLA_ESC] || botaoVoltar.estaClicado()) pilhaTelas.pop();

	Salvamento salvamentoSelecionado;

	if (botaoSalvamento1.estaClicado()) 
	{
		pilhaTelas.push(tJogo);
		salvamentoSelecionado = this->login.getJogador().buscaSalvamento(1);
		this->heroi.carregaSalvamento(salvamentoSelecionado);
	}
	if (botaoSalvamento2.estaClicado())
	{
		pilhaTelas.push(tJogo);
		salvamentoSelecionado = this->login.getJogador().buscaSalvamento(2);
		this->heroi.carregaSalvamento(salvamentoSelecionado);
	}
	if (botaoSalvamento3.estaClicado())
	{
		pilhaTelas.push(tJogo);
		salvamentoSelecionado = this->login.getJogador().buscaSalvamento(3);
		this->heroi.carregaSalvamento(salvamentoSelecionado);
	}
	if (botaoNovo.estaClicado())
	{
		pilhaTelas.push(tJogo);
		this->heroi.carregaSalvamento(salvamentoSelecionado);
	}
	cabecalho.setString("Selecione um salvamento");
	cabecalho.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 4);
}

