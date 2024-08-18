#include "Lig4.hpp"
#include <iostream>

Lig4::Lig4(int altura, int largura) : Tabuleiro(altura, largura)
{
}

void Lig4::fazerJogada(char time, int x, int y)
{
    try
    {
        testarJogada(time, x, y);

        retirarMarcacoesDeQuedaDePeca();

        soltarPeca(time, x);

    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Jogada Invalida: " << e.what() << std::endl
                  << std::endl;
    }
}

std::pair<int, int> Lig4::coletarJogada(char time, std::string apelido)
{
    if (time != 'B' && time != 'P') throw std::invalid_argument("Time invalido");

    std::pair<int, int> jogada;

    while (true)
    {
        int x, y;

        std::cout << "Vez de " << apelido << " (x)" << std::endl;
        std::cin >> x;
        y = 0;

        std::string resultadoTeste = testarJogada(time, x, y);

        if (resultadoTeste == "OK")
        {
            jogada.first = x;
            jogada.second = y;
            return jogada;
        }
        else
        {
            std::cout << "Jogada Invalida: " << resultadoTeste << std::endl
                      << std::endl;
        }
    }
}

bool Lig4::checarSeDaPraJogar(char time)
{
    for (int i = 0; i < getLargura(); i++)
    {
        if (casas[i][getAltura() - 1]->getCor() == ' ')
        {
            return true;
        }
    }
    return false;
}

void Lig4::retirarMarcacoesDeQuedaDePeca()
{
    for (int i = 0; i < getLargura(); i++)
    {
        for (int j = 0; j < getAltura(); j++)
        {
            if (casas[i][j]->getCor() == '|')
            {
                casas[i][j]->setCor(' ');
            }
        }
    }
}

void Lig4::soltarPeca(char time, int x)
{
    int alturaAnalizada = 0;
    for (; alturaAnalizada < getAltura(); alturaAnalizada++)
    {
        if (casas[x][alturaAnalizada]->getCor() == ' ')
        {
            casas[x][alturaAnalizada]->setCor(time);
            alturaAnalizada++;
            break;
        }
    }
    for (; alturaAnalizada < getAltura(); alturaAnalizada++)
    {
        if (casas[x][alturaAnalizada]->getCor() == ' ')
        {
            casas[x][alturaAnalizada]->setCor('|');
        }
        else
        {
            throw std::runtime_error("Erro inesperado durante a execução.");
        }
    }
}

std::string Lig4::testarJogada(char time, int x, int y)
{
    if (y != 0)
    {
        throw std::invalid_argument("Posicao invalida, y deve ser 0");
    }

    if (x < 0 || x >= getLargura())
    {
        return "Posicao invalida, x fora do tabuleiro";
    }

    char topoColuna = casas[x][getAltura() - 1]->getCor();
    if (topoColuna != ' ' && topoColuna != '|')
    {
        return "Coluna cheia";
    }
    return "OK";
}

char Lig4::testarCondicaoVitoria(char time)
{
    char vencedor = testarVitoriaPorLigacao();
    if (vencedor != ' ')
    {
        return vencedor;
    }

    // Verificacao Empate
    int jogadasValidas = 0;
    for (int i = 0; i < getLargura(); i++)
    {
        if (casas[i][getAltura() - 1]->getCor() == ' ')
        {
            jogadasValidas++;
        }
    }
    if (jogadasValidas == 0)
    {
        return 'E';
    }

    return ' ';
}

char Lig4::testarVitoriaPorLigacao()
{
    char vencedor = ' ';
    for (int i = 0; i < getLargura(); i++)
    {
        for (int j = 0; j < getAltura(); j++)
        {
            if (pecaVenceu(i, j))
            {
                if (vencedor == ' ')
                {
                    vencedor = casas[i][j]->getCor();
                }
                else if (vencedor != casas[i][j]->getCor())
                {
                    throw std::invalid_argument("Mais de um vencedor");
                }
            }
        }
    }
    return vencedor;
}

bool Lig4::pecaVenceu(int x, int y)
{
    bool venceu = false;

    // Faz um OR com todas as direções possíveis
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x--; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x++; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { y--; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { y++; });

    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x--; y--; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x--; y++; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x++; y--; });
    venceu |= pecaVenceu(x, y, [](int &x, int &y)
                         { x++; y++; });

    return venceu;
}

bool Lig4::pecaVenceu(int x, int y, void(direcionador)(int &, int &))
{
    int seguenciaPecas = 0;
    int largura = this->getLargura();
    int altura = this->getAltura();
    char time = casas[x][y]->getCor();

    while (x >= 0 && x < largura && y >= 0 && y < altura)
    {
        if (casas[x][y]->getCor() == time)
        {
            seguenciaPecas++;
            if (seguenciaPecas == 4)
                return true;
        }
        if (casas[x][y]->getCor() == ' ' || casas[x][y]->getCor() == '|')
        {
            return false;
        }
        if (casas[x][y]->getCor() != time)
        {
            return false;
        }
        direcionador(x, y);
    }

    return false;
}

void Lig4::imprimirTabuleiro()
{
    for (int j = 0; j < getLargura(); j++)
    {
        std::cout << j << ' ';
    }
    std::cout << std::endl;

    for (int i = getAltura() - 1; i >= 0; i--)
    {
        for (int j = 0; j < getLargura(); j++)
        {
            std::cout << casas[j][i]->getCor() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "  "; // Espaço para as margens inferiores

    std::cout << std::endl;
}

Lig4::~Lig4()
{
    // Destrutor
}