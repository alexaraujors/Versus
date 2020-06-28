#pragma once
#include "Personagem.h"
#include "Inventario.h"

class Heroi : 
    public Personagem
{
protected:
    int ouro = 0;
    int fase = 0;

    Inventario * inventario;

public:

    void atacar();

    void ganhaVida(int qtd);
    void perdeVida(int qtd);
    void ganhaDefesa(int qtd);
    void perdeDefesa(int qtd);
    void ganhaForca(int qtd);
    void perdeForca(int qtd);
    void ganhaOuro(int qtd);
    void passaFase();

    /*
    void adoecer();
    int getDirecao();
    void trocaDirecao();

    virtual int  getVelocidade();
    virtual void setVelocidade(int velocitade);
    virtual bool estaDoente();
    virtual string getIdade();
    */
};

