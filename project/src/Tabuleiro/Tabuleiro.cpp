#include <iostream>
#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro(int altura, int largura) : altura(altura), largura(largura)
{
    casas = new Casa **[altura];
    for (int i = 0; i < altura; i++)
    {
        Casa **linhaCasas = new Casa*[largura];
        for (int j = 0; j < largura; j++)
        {
            linhaCasas[j] = new Casa(i, j);
        }
        casas[i] = linhaCasas;
    }
}

Tabuleiro::~Tabuleiro()
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            delete casas[i][j];
        }
        delete[] casas[i];
    }
    delete[] casas;
}

void Tabuleiro::imprimirTabuleiro()
{   
    std::cout << "  "; // Espaço para as margens superiores
    for (int j = 0; j < largura; j++)
    {
        std::cout << j << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < altura; i++)
    {
        std::cout << i << ' '; // Margem esquerda
        for (int j = 0; j < largura; j++)
        {
            std::cout << casas[i][j]->getCor() << ' ';
        }
        std::cout << std::endl;
    }
}
