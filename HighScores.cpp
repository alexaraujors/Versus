#include "HighScores.h"

void HighScores::adicionarRecorde(string nome, int pontuacao)
{
	Recorde* rec = new Recorde(nome, pontuacao);
	this->recordes.push_back(*rec);
	this->salvarRecordes();
}

bool comparator(Recorde r1, Recorde r2)
{
	return r1.getPontuacao() > r2.getPontuacao();
}

 bool HighScores::carregarRecordes()
{

	arqRecordes.open("assets/recordes.txt", std::ios::out | std::ios::in);
	if (!arqRecordes.is_open()) {
		return false;
	}
	else {
		while (!arqRecordes.eof())  //lê todos os recordes 
		{
			string nome;
			int pontuacao;

			// lê linha com nome e linha com pontuação
			arqRecordes >> nome;
			arqRecordes >> pontuacao;

			// cria recorde com nome e pontuação lidos
			Recorde* recorde = new Recorde(nome, pontuacao);

			// adiciona recorde no fim da lista
			recordes.push_back(*recorde);		
		}
		// ordena a lista comparando as pontuações
		recordes.sort(comparator);

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
		//arqRecordes << recorde.getTempo();
	}
	arqRecordes.close();
	return true;
}

string HighScores::getRecordes()
{
	string retorno = "";
	for each (Recorde rec in recordes)
	{
		retorno += rec.getNome() + " : " + to_string(rec.getPontuacao()) + "\n";
	}
	return retorno;
}
