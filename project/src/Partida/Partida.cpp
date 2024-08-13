#include "Partida.hpp"

Partida::Partida(Tabuleiro &jogo, Jogador &jogador1, Jogador &jogador2) : jogo(jogo), jogador1(jogador1), jogador2(jogador2)
{
}

void Partida::executarPartida()
{
    char resultado;
    while (true)
    {
        if (jogo.checarSeDaPraJogar('B'))
        {
            jogo.imprimirTabuleiro();
            fazerJogada('B');
            resultado = jogo.testarCondicaoVitoria('B');
            if (resultado != ' ')
            {
                atualizarEstatisticas(resultado);
                return;
            }
        }

        if (jogo.checarSeDaPraJogar('P'))
        {
            jogo.imprimirTabuleiro();
            fazerJogada('P');
            resultado = jogo.testarCondicaoVitoria('P');
            if (resultado != ' ')
            {
                atualizarEstatisticas(resultado);
                return;
            }
        }
    }
}

std::string Partida::fazerJogada(char time)
{
    while (true)
    {
        int x, y;
        if (time == 'B')
        {
            std::cout << "Vez de " << jogador1.getApelido() << " (x y)" << std::endl;
            std::cin >> x >> y;
        }
        else if (time == 'P')
        {
            std::cout << "Vez de " << jogador2.getApelido() << " (x y)" << std::endl;
            std::cin >> x >> y;
        }
        else
        {
            throw std::invalid_argument("Time invalido");
        }

        std::string resultadoTeste = jogo.testarJogada(time, x, y);
        if (resultadoTeste == "OK")
        {
            jogo.fazerJogada(time, x, y);
            return "OK";
        }
        else
        {
            std::cout << "Jogada Invalida: " << resultadoTeste << std::endl
                      << std::endl;
        }
    }
}

void Partida::atualizarEstatisticas(char resultado)
{
    if (dynamic_cast<Reversi *>(&jogo))
    {
        atualizarEstatisticasReversi(resultado);
    }
    else if (dynamic_cast<Lig4 *>(&jogo))
    {
        atualizarEstatisticasLig4(resultado);
    }
    else
    {
        throw std::invalid_argument("Jogo invalido");
    }
}

void Partida::atualizarEstatisticasReversi(char resultado)
{
    if (resultado == 'B')
    {
        jogador1.incrementarVitoriasReversi();
        jogador2.incrementarDerrotasReversi();
    }
    else if (resultado == 'B')
    {
        jogador1.incrementarDerrotasReversi();
        jogador2.incrementarVitoriasReversi();
    }
    else if (resultado == 'E')
    {
        jogador1.incrementarEmpatesReversi();
        jogador2.incrementarEmpatesReversi();
    }
    else
    {
        throw std::invalid_argument("Resultado invalido");
    }
}

void Partida::atualizarEstatisticasLig4(char resultado)
{
    if (resultado == 'B')
    {
        jogador1.incrementarVitoriasLig4();
        jogador2.incrementarDerrotasLig4();
    }
    else if (resultado == 'B')
    {
        jogador1.incrementarDerrotasLig4();
        jogador2.incrementarVitoriasLig4();
    }
    else if (resultado == 'E')
    {
        jogador1.incrementarEmpatesLig4();
        jogador2.incrementarEmpatesLig4();
    }
    else
    {
        throw std::invalid_argument("Resultado invalido");
    }
}