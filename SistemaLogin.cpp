#include "SistemaLogin.h"

bool SistemaLogin::inicializar() 
{
	textoGuia.setFonte("arial");
	branco.set(255, 255, 255, 255);
	textoGuia.setCor(branco);

	//tenho certeza que isso não deveria estar sendo chamado aqui
	arq.open("assets/login.txt", std::ios::out | std::ios::in);
	if (!arq.is_open()) 
	{
		gDebug.erro("inicializar() não conseguiu abrir o arquivo de login");
		return false;
	}
	else if (arq.eof()) 
	{
		gDebug.erro("Arquivo vazio de login está vazio");
		return false;
	}
	else 
	{
		while (!arq.eof())	{ //aloca um novo usuario, lê o nome e a senha e insere na lista
			uJogador = new Jogador();
			string nome = "", senha = "";

			arq >> nome;
			uJogador->setNome(nome);
			arq >> senha;
			uJogador->setSenha(senha);

			for (int i = 0; i < 3; i++)
			{
				string data = "";
				int vida = 0, forca = 0, defesa = 0, ouro = 0, fase = 0;
				
				arq >> data;
				arq >> vida;
				arq >> forca;
				arq >> defesa;
				arq >> ouro;
				arq >> fase;
				Salvamento *salv = new Salvamento(data, vida, forca, defesa, ouro, fase);
				uJogador->incluiSalvamento(*salv);
			}

			listaJogador.push_back(*uJogador);
		}
	}
	arq.close();
}

bool SistemaLogin::cadastrar(string user, string senha) 
{
	gDebug.erro("passou pelo cadastrar()");

	arq.open("assets/login.txt", std::ios::out | std::ios::in |std::ios::app);
	if (!arq.is_open()) 
	{
		gDebug.erro("cadastrar() não conseguiu abrir o arquivo de login");
		return false;
	}
	else 
	{	//salvar usuario e salvar senha
		arq << endl << user;
		arq << endl << senha;
	}
	arq.close();
	return true;
}

bool SistemaLogin::iniciarCadastro(){
	bool usuarioRepetido = false;
	cadastroJogador = new Jogador();

	gDebug.depurar("bUsuario", bUsuario);
	gDebug.depurar("usuario repetido", usuarioRepetido);

	if (inputInicio == false) {
		input.inicializar();
		inputInicio = true;
	}

	if (bUsuario == false) //Salvar Usuario
	{
		//configurar texto
		textoGuia.setString("Informe o seu nome de Usuario:");
		textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) 
		{
			user = input.getTexto();
			input.finalizar();

			if (user != "") {	//verificar lista de usuarios
				//Enquanto o cadastro estiver salvando duas vezes cada usurário esse método de cima não funciona
				//Usuario ultimoUsuario = listaUsuario.back();
				//while (listaUsuario.front().nome != ultimoUsuario.nome){

				int i = listaJogador.size();
				while (i >= 0) {
					gDebug.depurar("primeiro da lista: ", listaJogador.front().getNome());
					gDebug.depurar("tamanho lista: ", listaJogador.size());
					if (listaJogador.front().getNome()==user) {
						usuarioRepetido = true;
						textoGuia.setString("Nome indisponível. Informe o seu nome de Usuario:");
						gDebug.erro("Usuario ja existente!");
						break;
					}
					else {
						listaJogador.push_back(listaJogador.front());
						listaJogador.pop_front();
					}
					i--;
				}

				if (usuarioRepetido == false) {
					bUsuario = true;
					inputInicio = false;

					cadastroJogador->setNome(user);
				}
			}
			else input.inicializar();
		}
	}
	else if (bSenha1 == false) {
		//configurar texto
		textoGuia.setString("Informe a sua senha:");//informar a senha
		textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
			sn1 = input.getTexto();
			input.finalizar();

			if (sn1 != "") {
				bSenha1 = true;
				inputInicio = false;
				bSenha2 = false;
			}
			else input.inicializar();
		}
	}
	else if (bSenha2 == false) {
		//configurar texto
		textoGuia.setString("Confirme a senha a sua senha:");//confirmar senha
		textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
			sn2 = input.getTexto();
			input.finalizar();

			if (sn2 != "") {
				bSenha2 = true;
				inputInicio = false;
			}
			else input.inicializar();
		}
	}
	if (bSenha1 == true && bSenha2 == true) {//verifica se as senhas foram prenchidas
		if (sn1 != "" && sn2 != "") {//verrifica se as senhas nao estao vazias
			if (sn1 == sn2) {//verifica se as senhas sao iguais

				gDebug.erro("passou pelo iniciarCadastro()");

				textoGuia.setString("Senha salva:");
				textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

				cadastroJogador->setSenha(sn1);

				listaJogador.push_back(*cadastroJogador);

				logando = *cadastroJogador;

				cadastrar(user, sn1);
				return true;
			}
			else 
			{
				textoGuia.setString("Senha incorreta: pressione ENTER para redigita-la");
				textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
				gDebug.erro("Senha incorreta");

				if (gTeclado.pressionou[TECLA_ENTER]) //reiniciar cadastro
				{
					bSenha1 = false;
				}

				return false;
			}
		}
		else 
		{
			textoGuia.setString("Erro: variaveis de senha vazias!");
			textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
			return false;
		}
	}
}

void SistemaLogin::finalizar()
{
	//esse método não tá sendo chamado em lugar nenhum
	listaJogador.clear();
	delete uJogador;
	delete cadastroJogador;
}

bool SistemaLogin::iniciarLogin()
{

	if (lUser == false) { // verificar usuario
		textoGuia.setString("Informe seu nome de usuario:");
		textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		if (inputInicio == false) {
			input.inicializar();
			inputInicio = true;
		}
		input.atualizar();
		input.desenhar();

		if (input.getTexto() != "")
			if (gTeclado.pressionou[TECLA_ENTER]) 
			{

				test1 = input.getTexto();
				input.finalizar();

				if (listaJogador.front().getNome() == input.getTexto()) 
				{
					lExiste = true;
				}

				if (percorrerJogador(test1, listaJogador)) 
				{
					//encontrou usuario
					lUser = true;
					lSenha = false;
					inputInicio = false;
					//logando = listaUsuario.front();
				}
				else 
				{
					//nao encontrou
					gDebug.erro("Usuário não encontrado");
					//lUser = false;
					inputInicio = false;
					iniciarLogin();
				}
			}
	}

	if (lSenha == false) //verificar senha 
	{
		textoGuia.setString("Informe sua senha:");
		textoGuia.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		if (inputInicio == false) 
		{//ativar input
			input.inicializar();
			inputInicio = true;
		}
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] && input.getTexto() != "") 
		{
			test2 = input.getTexto();
			input.finalizar();
			if (logando.getSenha() == test2) 
			{
				lSenha = true;
				logou = true;
				gGraficos.desenharTexto("Logando", 400, 300, 255, 255, 255, 255);
				return true;
			}
			else 
			{
				gDebug.erro("Senha incorreta!");
				lSenha = false;
				inputInicio = false;
				iniciarLogin();
				return false;
			}
		}
	}
}

bool SistemaLogin::percorrerJogador(std::string& alvo, list<Jogador>& fLista) 
{
	int i = listaJogador.size();
	while (i >= 0) 
	{
		gDebug.depurar("primeiro da lista: ", listaJogador.front().getNome());
		gDebug.depurar("tamanho lista: ", listaJogador.size());
		if (listaJogador.front().getNome() == alvo) 
		{
			lExiste = true;
			logando = fLista.front();
			return true;
		}
		else 
		{
			listaJogador.push_back(listaJogador.front());
			listaJogador.pop_front();
		}
		i--;
	}
	gDebug.erro("Jogador não cadastrado.");
	lExiste = false;
	return false;
}