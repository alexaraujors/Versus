#include "HighScores.h"

bool HighScores::bateuRecorde(string nome, int valor)
{
	return tempo <= this->recorde.getTempo();
}

void HighScores::adicionarRecorde(Recorde rec)
{
	this->recordes[0] = &rec;
	this->salvarRecordes();
}

bool HighScores::carregarRecordes()
{
	arqRecordes.open("assets/recordes.txt", std::ios::out | std::ios::in);
	if (!arqRecordes.is_open()) {
		return false;
	}
	else {
		while (!arqRecordes.eof()) { //lê todos os recordes
			Recorde recorde = new Recorde();
			float valor;
			string nome;
			arqRecordes >> nome;
			arqRecordes >> valor;
			recorde->setPontuacao(valor);
			recorde->setNome(nome);
			this->recorde = *recorde;
		}
	}
	arqRecordes.close();
	return true;
}

bool HighScores::salvarRecordes()
{
	arqRecordes.open("assets/recordes.txt", std::ios::out | std::ios::in);
	if (!arqRecordes.is_open()) {
		return false;
	}
	else {
		arqRecordes.clear();
		arqRecordes << recorde.getTempo();
	}
	arqRecordes.close();
	return true;
}

Recorde HighScores::getRecorde(int posicao)
{
	return recordes[posicao];
}

string HighScores::getRecorde()
{
	float t = this->recorde.getTempo();
	int minutos = int(t) / 60;
	int segundos = int(t) % 60;
	return std::to_string(minutos) + ":" + std::to_string(segundos);
}
