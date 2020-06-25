#include "Jogo.h"
#include "CadeiraItem.h"
#include <string>
#include <time.h>

Jogo::Jogo()
{}

Jogo::~Jogo()
{}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Pandemia");

	// Carrega recordes
	carregaRecordes();

	// Carregar o tilemap
	mapa.carregar("assets/mapa/pandemia.json");
	mapa.carregarConfigTileSet("campo", "assets/mapa/campo_config.txt");

	// Carregar recursos
	// spritesheet para os personagens
	// fonte para o texto de colisão
	gRecursos.carregarSpriteSheet("player", "assets/char/bolsonaro.png", 4, 3);
	gRecursos.carregarSpriteSheet("jovem", "assets/char/jovem.png", 4, 3);
	gRecursos.carregarSpriteSheet("idoso", "assets/char/idoso.png", 4, 3);
	gRecursos.carregarSpriteSheet("doente", "assets/char/doente.png", 4, 3);
	gRecursos.carregarSpriteSheet("poderoso", "assets/char/poderoso.png", 4, 3);

	gRecursos.carregarSpriteSheet("bonus", "assets/char/bonus.png", 1, 1);

	// Inicializar o personagem do player,
	// passando o nome do spritesheet e o objeto que representa ele no mapa
	player.inicializar("player", mapa.getCamadaDeObjetos("objetos")->getObjeto("player"));

	// Inicializa os sprites de bonus
	obj1.inicializar("bonus", mapa.getCamadaDeObjetos("objetos")->getObjeto("b1"));
	obj2.inicializar("bonus", mapa.getCamadaDeObjetos("objetos")->getObjeto("b2"));

	// Incicializa as pessoas
	inicializarPessoas();

	// Inicializar texto
	texto.setFonte("fonte colisao");

	this->cronometro = clock();
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
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		// Verifica as teclas do teclado e caso forem pressionadas
		// seta o destino do player
		atualizarInput();

		// Atualizar player e as pessoas
		player.atualizar();
		atualizarPessoas();

		// TESTAR E TRATAR COLISÃO COM OS OBJETOS NO TILEMAP
		testarColisoes();

		// Desenhar o tilemap (player eh desenhado junto)
		mapa.desenhar();

		// Renderiza os dois bonus de velocidade
		obj1.exibe();
		obj2.exibe();
		
		// Testa termino do efeito do bonus no player
		verificaPoderoso();

		// Desenhar instruções, recorde e cronometro
		desenharInstrucoes();
		desenharCronometro();

		uniTerminarFrame();
	}
}

void Jogo::carregaRecordes()
{
	this->highScores.carregarRecordes();
}

void Jogo::atualizarInput()
{
	if (!player.estaMovendo())
	{
		if (gTeclado.segurando[TECLA_DIR])
		{
			if (mapa.tileECaminhavel(player.getX() + 1.0 , player.getY()))
			{
				player.setDestino(player.getX() + 1.0 , player.getY());
			}
		}
		else if (gTeclado.segurando[TECLA_ESQ])
		{
			if (mapa.tileECaminhavel(player.getX() - 1.0, player.getY()))
			{
				player.setDestino(player.getX() - 1.0, player.getY());
			}
		}
		else if (gTeclado.segurando[TECLA_CIMA])
		{
			if (mapa.tileECaminhavel(player.getX(), player.getY()-1.0))
			{
				player.setDestino(player.getX(), player.getY() - 1.0);
			}
		}
		else if (gTeclado.segurando[TECLA_BAIXO])
		{
			if (mapa.tileECaminhavel(player.getX(), player.getY()+1.0))
			{
				player.setDestino(player.getX(), player.getY() + 1.0);
			}
		}
	}
}
void Jogo::testarColisoes()
{
	for (int i = 0; i < 5; i++)
	{
		if (mapa.existeObjetoDoTipoNaPos("pessoa" + std::to_string(i + 1), player.getX(), player.getY()))
		{
			this->pessoas[i]->adoecer();
		}
	}
	if (this->obj1.visivel()) {
		if (mapa.existeObjetoDoTipoNaPos("b1", player.getX(), player.getY())){
			player.atualizaSprite("poderoso");
			player.setVelocidade(5);
			this->obj1.usar();
			this->timerPoderoso = clock();
		}
	}
	if (this->obj2.visivel()) {
		if (mapa.existeObjetoDoTipoNaPos("b2", player.getX(), player.getY())) {
			player.atualizaSprite("poderoso");
			player.setVelocidade(5);
			this->obj2.usar();
			this->timerPoderoso = clock();
		}
	}
}

void Jogo::atualizarPessoas()
{
	this->contaDoentes = 0;
	for (int i = 0; i < 5; i++)
	{	
		if (!this->pessoas[i]->estaMovendo())
		{
			int direcao = this->pessoas[i]->getDirecao();
			switch (direcao)
			{
			case 0: // CIMA
				if (mapa.tileECaminhavel(this->pessoas[i]->getX(), this->pessoas[i]->getY() - 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX(), this->pessoas[i]->getY() - 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 1: // NORDESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY() - 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY() - 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 2: // LESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY()))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY());
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 3: // SUDESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY() + 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() + 1.0, this->pessoas[i]->getY() + 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 4: // SUL
				if (mapa.tileECaminhavel(this->pessoas[i]->getX(), this->pessoas[i]->getY() + 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX(), this->pessoas[i]->getY() + 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 5: // SUDOESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY() + 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY() + 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 6: // OESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY()))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY());
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			case 7: // NOROESTE
				if (mapa.tileECaminhavel(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY() - 1.0))
				{
					this->pessoas[i]->setDestino(this->pessoas[i]->getX() - 1.0, this->pessoas[i]->getY() - 1.0);
				}
				else {
					this->pessoas[i]->trocaDirecao();
				}
				break;
			default:
				break;
			}
		}
		this->pessoas[i]->atualizar();

		// Troca os sprites se pessoa ficou doente ou se ficou curada
		// Incrementa ou decrementa o contador de doentes
		if (this->pessoas[i]->estaDoente()) {
			this->contaDoentes++;
			this->pessoas[i]->atualizaSprite("doente");
		}
		else {
			this->contaDoentes--;
			this->pessoas[i]->atualizaSprite(this->pessoas[i]->getIdade());
		}
	}
	// Testa se todas as pessoas ficaram curadas e se o recorde foi batido
	if (this->contaDoentes >= 5) {
		float t = (clock() - this->cronometro) / CLOCKS_PER_SEC;
		if (highScores.bateuRecorde(t)) {
			Recorde* r = new Recorde();
			r->setTempo(t);
			highScores.adicionarRecorde(*r);
		}

		//* TODO Colocar código para encerrar a partida
	}
}

void Jogo::desenharInstrucoes()
{
	string txt = "Instruções:\n"
		"    Use as setas para mover o Bolsominion e contaminar as pessoas.";
	gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);
}

void Jogo::desenharCronometro()
{
	float t = (clock() - this->cronometro) / CLOCKS_PER_SEC;
	int minutos = int(t) / 60;
	int segundos = int(t) % 60;
	string tempo = std::to_string(minutos) + ":" + std::to_string(segundos);

	gGraficos.desenharTexto("Recorde: " +
		this->highScores.getRecorde() +
		"   |   Tempo: " + tempo, 25, 115, 255, 255, 255, 255, 0, 0);
}

void Jogo::verificaPoderoso()
{
	if ((clock() - this->timerPoderoso) / CLOCKS_PER_SEC >= 15)
	{
		this->timerPoderoso = 0;
		player.atualizaSprite("player");
		player.setVelocidade(2);
	}
}

void Jogo::inicializarPessoas()
{
	srand(clock());
	for (int i = 0; i < 5; i++)
	{
		if (rand() % 2 == 0) {
			this->pessoas[i] = new Idoso();
		}
		else {
			this->pessoas[i] = new Jovem();
		}
		this->pessoas[i]->inicializar(this->pessoas[i]->getIdade(), 
			mapa.getCamadaDeObjetos("objetos")->getObjeto("pessoa" + std::to_string(i + 1)));
	}
}
