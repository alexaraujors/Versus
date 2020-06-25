#pragma once
#include "libUnicornio.h"

class Bonus
{
private:
    ObjetoTileMap * obj;
    Sprite spr;
    bool usado = false;

public:
    void inicializar(string sheet, ObjetoTileMap * obj);
    void esconde();
    void exibe();
    bool visivel();
    void usar();
};

