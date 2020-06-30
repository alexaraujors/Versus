#pragma once
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "InputTexto.h"
#include "libUnicornio.h"
#include <list>
#include "Jogador.h"
//#include "Usuario.h"

class SistemaLogin
{
public:
	SistemaLogin() {};
	~SistemaLogin() {};

	bool inicializar();
	//void executar();
	void finalizar();

	bool cadastrar(string user, string senha);

	bool iniciarCadastro();
	bool iniciarLogin();

	bool percorrerJogador(string& alvo, list<Jogador>& fLista);

	bool getLoginAprovado() { return logou; }
	Jogador getJogador() { return logando; }

private:
	fstream login;
	string sTokken;
	fstream arq;

	// Input de Texto
	InputTexto input;

	Texto textoGuia;
	Cor branco;

	bool bUsuario = false, bSenha1 = false, bSenha2 = false, inputInicio = false;
	string user = "", sn1 = "", sn2 = "";

	// Input login
	bool lUser = false, lSenha = true, lExiste = false;
	Jogador logando;
	string test1, test2;
	bool logou = false;

	// Controle de lista
	list<Jogador> listaJogador;
	Jogador* uJogador, fimLista, aux, *cadastroJogador;

};