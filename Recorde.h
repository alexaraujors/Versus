#pragma once
using namespace std;
#include <string>

class Recorde
{
private:
    string nome;
    int pontuacao;

public:
    Recorde(string nome, int pontuacao);
    ~Recorde();

    string getNome();
    void setNome(string nome);
    int getPontuacao();
    void setPontuacao(int pontuacao);
};

