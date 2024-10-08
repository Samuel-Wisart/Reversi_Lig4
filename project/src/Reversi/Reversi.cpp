#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi(int altura, int largura) : Tabuleiro(altura, largura)
{
    // Inicializa o tabuleiro com as peças iniciais
    casas[(altura / 2 - 1)][(largura / 2 - 1)]->setCor('P');
    casas[(altura / 2)][(largura / 2) - 1]->setCor('B');
    casas[(altura / 2) - 1][(largura / 2)]->setCor('B');
    casas[(altura / 2)][(largura / 2)]->setCor('P');
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
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Jogada Invalida: " << e.what() << std::endl << std::endl;
    }
}

std::string Reversi::testarJogada(char time, int x, int y)
{   
    if (x < 0 || x >= getLargura() || y < 0 || y >= getAltura())
    {   
        return "Posicao invalida";
    }
    if (casas[x][y]->getCor() != ' ')
    {
        return "Casa ja ocupada";
    }
    if (selecionarPecasAlteradas(time, x, y).size() == 0)
    {
        return "Sem pecas para capturar";
    }
    return "OK";
}

char Reversi::testarCondicaoVitoria(char time)
{
    if (!checarSeDaPraJogar('B') && !checarSeDaPraJogar('P'))
    {
        int pecasB = 0;
        int pecasP = 0;
        for (int i = 0; i < getLargura(); i++)
        {
            for (int j = 0; j < getAltura(); j++)
            {
                if (casas[i][j]->getCor() == 'B')
                {
                    pecasB++;
                }
                if (casas[i][j]->getCor() == 'P')
                {
                    pecasP++;
                }
            }
        }
        if (pecasB > pecasP)
        {
            return 'B';
        }
        if (pecasP > pecasB)
        {
            return 'P';
        }
        return 'E';
    }
    return ' ';
}

std::pair<int, int> Reversi::coletarJogada(char time, std::string apelido)
{
    if (time != 'B' && time != 'P') throw std::invalid_argument("Time invalido");

    std::pair<int, int> jogada(-1, -1);
    int tentativas = 0;

    while (tentativas < 5)
    {
        int x, y;

        std::cout << "Vez de " << apelido << " (x y)" << std::endl;
        std::cin >> x >> y;

        std::string resultadoTeste = testarJogada(time, x, y);

        if (resultadoTeste == "OK")
        {
            jogada.first = x;
            jogada.second = y;
            return jogada;
        }
        else
        {
            std::cout << "Jogada Invalida: " << resultadoTeste << std::endl << std::endl;
            tentativas++;
        }
    }
    if (tentativas >= 5)
    {
        throw std::invalid_argument("Jogada invalida: Tentativas excedidas");
    }
    return jogada;
}

bool Reversi::checarSeDaPraJogar(char time)
{
    for (int i = 0; i < getLargura(); i++)
    {
        for (int j = 0; j < getAltura(); j++)
        {
            if (testarJogada(time, i, j) == "OK")
            {
                return true;
            }
        }
    }
    return false;
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