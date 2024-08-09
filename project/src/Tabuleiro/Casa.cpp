#include <iostream>
#include "Tabuleiro.hpp"

Casa::Casa(int x, int y)
{
    this->x = x;
    this->y = y;
    this->cor = ' ';
};

Casa::Casa(int x, int y, char cor)
{
    this->x = x;
    this->y = y;
    this->cor = cor;
};

Casa::~Casa(){};

char Casa::getCor()
{
    return cor;
}

int Casa::getX()
{
    return x;
}

int Casa::getY()
{
    return y;
}

void Casa::setCor(char cor)
{
    this->cor = cor;
}



void Casa::imprimirPosicao()
{
    std::cout << numeroParaLetra(x) << ' ' << y << std::endl;
}

char numeroParaLetra(int numero)
{
    return 'a' + numero;
}