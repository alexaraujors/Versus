#pragma once
#include "Personagem.h"
#include "Painel.h"

class Guerreiro :
    public Personagem
{
public: 
    Guerreiro();
    ~Guerreiro();

    void atacar();
    void inicializarPaineis();

};

