#pragma once
#include "libUnicornio.h"
#include "Heroi.h"

class Pocao
{
private:
    ObjetoTileMap * obj;
    Sprite spr;
    Pocao * proximo = nullptr;

protected:
    int valor = 0;

public:
//    virtual void usar(Heroi* heroi);
    
    Pocao* getProximo();
    void setProximo(Pocao * pocao);

 //   void inicializar(string sheet, ObjetoTileMap* obj);
};

