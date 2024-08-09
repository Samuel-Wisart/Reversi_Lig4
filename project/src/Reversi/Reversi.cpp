#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi(int altura, int largura) : Tabuleiro(altura, largura)
{
    // Inicializa o tabuleiro com as peças iniciais
    casas[(altura / 2 - 1)][(largura / 2 - 1)]->setCor('B');
    casas[(altura / 2)][(largura / 2) - 1]->setCor('P');
    casas[(altura / 2) - 1][(largura / 2)]->setCor('P');
    casas[(altura / 2)][(largura / 2)]->setCor('B');
}

void Reversi::fazerJogada(char time, int x, int y)
{
    try
    {
        testarJogada(time, x, y);

        casas[x][y]->setCor(time);
        for (auto &i : selecionarPecasAlteradas(time, x, y))
        {
            mudarCor(casas[i.first][i.second]);
        }

        testarCondicaoVitoria(time, x, y);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Jogada Invalida: " << e.what() << std::endl << std::endl;
    }
}

bool Reversi::testarJogada(char time, int x, int y)
{   
    if (x < 0 || x >= getLargura() || y < 0 || y >= getAltura())
    {
        throw std::invalid_argument("Posicao invalida");
        return false;
    }
    if (casas[x][y]->getCor() != ' ')
    {
        throw std::invalid_argument("Casa ja ocupada");
        return false;
    }
    if (selecionarPecasAlteradas(time, x, y).size() == 0)
    {
        throw std::invalid_argument("Sem pecas para capturar");
        return false;
    }
    return true;
}

bool Reversi::testarCondicaoVitoria(char time, int x, int y)
{
    return true;
}

std::vector<std::pair<int, int>> Reversi::selecionarPecasAlteradas(char time, int x, int y)
{   
    std::vector<std::pair<int, int>> pecasAlteradasTotais;
    
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x--; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x++; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { y--; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { y++; });

    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x--; y--; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x--; y++; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x++; y--; });
    pecasAlteradasTotais += selecionarPecasAlteradas(time, x, y, [](int &x, int &y) { x++; y++; });

    return pecasAlteradasTotais;
}

std::vector<std::pair<int, int>> Reversi::selecionarPecasAlteradas(char time, int x, int y, void (direcionador)(int&, int&))
{
    std::vector<std::pair<int, int>> pecasAlteradas; // Retorno da função
    int largura = this->getLargura();
    int altura = this->getAltura();

    std::vector<std::pair<int, int>> bufferPecasAlteradas; // Armazena as peças que serão alteradas se uma peça aliada for encontrada

    direcionador(x, y); // Função que subtrai ou adiciona 1 a x e y

    while(x >= 0 && x < largura && y >= 0 && y < altura)
    {
        
        if (casas[x][y]->getCor() == time)
        {
            pecasAlteradas += bufferPecasAlteradas;
            break;
        }
        if (casas[x][y]->getCor() == ' ')
        {
            break;
        }
        if (casas[x][y]->getCor() != time)
        {
            std::pair<int, int> posicao(x, y);
            bufferPecasAlteradas.push_back(posicao);
        }
        direcionador(x, y);
    }

    return pecasAlteradas;
}

Reversi::~Reversi()
{
    // Destrutor
}

bool mudarCor(Casa *casa)
{
    char cor = casa->getCor();
    if (cor == 'B')
    {
        casa->setCor('P');
    }
    else if (cor == 'P')
    {
        casa->setCor('B');
    }
    else
    {
        return false;
    }
    return true;
}