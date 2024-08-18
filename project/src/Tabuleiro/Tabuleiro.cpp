#include <iostream>
#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro(int altura, int largura) : altura(altura), largura(largura)
{
    casas = new Casa **[largura];
    for (int i = 0; i < largura; i++)
    {
        Casa **colunaCasas = new Casa*[altura];
        for (int j = 0; j < altura; j++)
        {
            colunaCasas[j] = new Casa(i, j);
        }
        casas[i] = colunaCasas;
    }
}

Tabuleiro::~Tabuleiro()
{
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            delete casas[i][j];
        }
        delete[] casas[i];
    }
    delete[] casas;
}

int Tabuleiro::getAltura()
{
    return altura;
}

int Tabuleiro::getLargura()
{
    return largura;
}

void Tabuleiro::imprimirTabuleiro()
{   
    for (int i = 0; i < altura; i++)
    {
        std::cout << i << ' '; // Margem esquerda
        for (int j = 0; j < largura; j++)
        {
            std::cout << casas[j][i]->getCor() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "  "; // Espaço para as margens inferiores
    for (int j = 0; j < largura; j++)
    {
        std::cout << j << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
