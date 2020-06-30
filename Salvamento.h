#pragma once
#include <string>
using namespace std;

class Salvamento
{
public:
		Salvamento(string data, int vida, int forca, int defesa, int ouro, int fase);
		Salvamento();
		~Salvamento();

		string getDataHora();
		void setDataHora(string dataHora);
		int getVida();
		void setVida(int vida);
		int getForca();
		void setForca(int forca);
		int getDefesa();
		void setDefesa(int defesa);
		int getOuro();
		void setOuro(int ouro);
		int getFase();
		void setFase(int fase);
private:
		string dataHora;
		int fase;
		int	vida;
		int forca;
		int defesa;
		int ouro;
};

