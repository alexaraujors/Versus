#pragma once
#include <fstream>
#include <string>
#include "InputTexto.h"
#include "libUnicornio.h"
#include <list>
#include "Usuario.h"

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

	bool percorrerUsuario(string& alvo, list<Usuario>& fLista);

	bool getLoginAprovado() { return logou; }
	Usuario getUsuario() { return logando; }

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
	Usuario logando;
	string test1, test2;
	bool logou = false;

	// Controle de lista
	list<Usuario> listaUsuario;
	Usuario *uUsuario, fimLista, aux, *cadastroUsuario;

};