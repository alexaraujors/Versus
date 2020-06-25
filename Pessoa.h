#pragma once
#include "Personagem.h"

class Pessoa :
    public Personagem
{
protected:
    float adoeceu = 0;
    int direcao = 0;

public:
    void adoecer();
    int getDirecao();
    void trocaDirecao();

    virtual int  getVelocidade();
    virtual void setVelocidade(int velocitade);
    virtual bool estaDoente();
    virtual string getIdade();
};

