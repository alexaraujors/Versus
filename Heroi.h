#pragma once
#include "Personagem.h"
#include "Painel.h"
#include "Salvamento.h"

//#include "Inventario.h"
class Heroi : 
    public Personagem
{
protected:
    int ouro = 0;
    int fase = 0;

    Painel painelOuro;
//    Inventario * inventario;

public:
    Heroi();
    ~Heroi();

    void inicializarPaineis();

    void ganhaOuro(int qtd);
    int getOuro();
    void passaFase();
    void reiniciar();

    void carregaSalvamento(Salvamento salvamento);
};

