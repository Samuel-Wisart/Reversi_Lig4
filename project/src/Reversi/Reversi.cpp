#include "Reversi.hpp"

Reversi::Reversi(int altura, int largura) : Tabuleiro(altura, largura)
{
    // Inicializa o tabuleiro com as peças iniciais
    casas[(altura/2-1)][(largura/2-1)]->setCor('B');
    casas[(altura/2)][(largura/2)-1]->setCor('P');
    casas[(altura/2)-1][(largura/2)]->setCor('P');
    casas[(altura/2)][(largura/2)]->setCor('B');
}

void Reversi::fazerJogada(char time, int x, int y)
{
    testarJogada(time, x, y);
    casas[x][y]->setCor(time);
}

bool Reversi::testarJogada(char time, int x, int y)
{
    
    return true;
}


Reversi::~Reversi()
{
    // Destrutor
}