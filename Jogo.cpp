#include "Jogo.h"
//#include <string>
#include <time.h>

Jogo::Jogo()
{}

Jogo::~Jogo()
{}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Versus");

	// Carrega recordes
	carregaRecordes();

	// Carregar o tilemap
	mapa.carregar("assets/mapa/versus.json");

	// Carregar recursos
	//sprintesheet para ações
	gRecursos.carregarSpriteSheet("actions", "assets/tilesets/action_192x64.png", 1, 3);

	// spritesheet para os personagens
	gRecursos.carregarSpriteSheet("heroi_p", "assets/tilesets/hero_p_8.png", 1, 8);
	gRecursos.carregarSpriteSheet("heroi_a", "assets/tilesets/hero_a_2x19.png", 2, 19);
	gRecursos.getSpriteSheet("heroi_a")->juntarAnimacoes(0, 1);

	gRecursos.carregarSpriteSheet("witcher_p", "assets/tilesets/witcher_p_10.png", 1, 10);
	gRecursos.carregarSpriteSheet("witcher_a", "assets/tilesets/witcher_a_12.png", 1, 12);

	//gRecursos.carregarSpriteSheet("idoso", "assets/char/idoso.png", 4, 3);
	//gRecursos.carregarSpriteSheet("doente", "assets/char/doente.png", 4, 3);
	//gRecursos.carregarSpriteSheet("poderoso", "assets/char/poderoso.png", 4, 3);

	// fonte para o texto de colisão
	//gRecursos.carregarSpriteSheet("bonus", "assets/char/bonus.png", 1, 1);

	
	// Inicializar o personagem do player,
	// passando o nome do spritesheet e o objeto que representa ele no mapa
	heroi.inicializar("heroi_p", mapa.getCamadaDeObjetos("objetos")->getObjeto("hero"));

	// Incicializa os guerreiros
	inicializarGuerreiros();
	
	// Inicializa os sprites de bonus
	//obj1.inicializar("bonus", mapa.getCamadaDeObjetos("objetos")->getObjeto("b1"));
	//obj2.inicializar("bonus", mapa.getCamadaDeObjetos("objetos")->getObjeto("b2"));

	// Inicializar texto
	texto.setFonte("fonte colisao");

	//this->cronometro = clock();
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

		// Verifica final da batalha
		verificaFinalBatalha();
		
		// Atualizar heroi e as guerreiros
		heroi.atualizar();
		
		atualizarGuerreiros();

		// Desenhar o tilemap (player eh desenhado junto)
		mapa.desenhar();

		// Desenhar instruções, recorde e cronometro
		//desenharInstrucoes();
		//desenharCronometro();

		uniTerminarFrame();
	}
}

void Jogo::carregaRecordes()
{
	//this->highScores.carregarRecordes();
}

void Jogo::atualizarInput()
{
	if (gTeclado.segurando[TECLA_A]) {
		heroi.atacar();
		bruxo.atacar();
		inicioBatalha = clock();

	}

//	if (gTeclado.segurando[TECLA_DIR])
//	{
//		if (mapa.tileECaminhavel(player.getX() + 1.0, player.getY()))
//		{
//			player.setDestino(player.getX() + 1.0, player.getY());
//		}
//	}
}

void Jogo::atualizarGuerreiros()
{
	bruxo.atualizar();
}

void Jogo::desenharInstrucoes()
{
	string txt = "Instruções:\n"
		"    Use as setas para mover o Bolsominion e contaminar as pessoas.";
	gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);
}
void Jogo::verificaFinalBatalha()
{
	if ((clock() - this->inicioBatalha) / CLOCKS_PER_SEC >= 10)
	{
		this->inicioBatalha = 0;
		heroi.atualizaSprite("heroi_p");
		bruxo.atualizaSprite("witcher_p");
	}
}

/*
void Jogo::desenharCronometro()
{
	float t = (clock() - this->cronometro) / CLOCKS_PER_SEC;
	int minutos = int(t) / 60;
	int segundos = int(t) % 60;
	string tempo = std::to_string(minutos) + ":" + std::to_string(segundos);

//	gGraficos.desenharTexto("Recorde: " +
//		this->highScores.getRecorde() +
//		"   |   Tempo: " + tempo, 25, 115, 255, 255, 255, 255, 0, 0);
}
*/

void Jogo::inicializarGuerreiros()
{
	
	bruxo.inicializar("witcher_p", mapa.getCamadaDeObjetos("objetos")->getObjeto("warrior"));
	


//	srand(clock());
//	for (int i = 0; i < 5; i++)
//	{
//		if (rand() % 2 == 0) {
//			this->pessoas[i] = new Idoso();
//		}
//		else {
//			this->pessoas[i] = new Jovem();
//		}
//		this->pessoas[i]->inicializar(this->pessoas[i]->getIdade(), 
//			mapa.getCamadaDeObjetos("objetos")->getObjeto("pessoa" + std::to_string(i + 1)));
//	}

}
