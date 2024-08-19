#include "Partida.hpp"

Partida::Partida(Tabuleiro &jogo, Jogador &jogador1, Jogador &jogador2) : jogo(jogo), jogador1(jogador1), jogador2(jogador2)
{
}

void Partida::executarPartida()
{
    try {
        char resultado;
        while (true)
        {
            if (jogo.checarSeDaPraJogar('B'))
            {
                jogo.imprimirTabuleiro();

                std::pair<int, int> jogada = jogo.coletarJogada('B', jogador1.getApelido());
                jogo.fazerJogada('B', jogada.first, jogada.second);

                resultado = jogo.testarCondicaoVitoria('B');
                if (resultado != ' ')
                {   
                    jogo.imprimirTabuleiro();
                    std::cout << "O jogador " << jogador1.getApelido() << " venceu!" << std::endl;
                    atualizarEstatisticas(resultado);
                    break;  // Use break ao invés de return para não sair da função executarPartida.
                }
            }

            if (jogo.checarSeDaPraJogar('P'))
            {
                jogo.imprimirTabuleiro();

                std::pair<int, int> jogada = jogo.coletarJogada('P', jogador2.getApelido());
                jogo.fazerJogada('P', jogada.first, jogada.second);

                resultado = jogo.testarCondicaoVitoria('P');
                if (resultado != ' ')
                {
                    jogo.imprimirTabuleiro();
                    std::cout << "O jogador " << jogador2.getApelido() << " venceu!" << std::endl;
                    atualizarEstatisticas(resultado);
                    break;  // Use break ao invés de return para não sair da função executarPartida.
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro durante a execucao da partida: " << e.what() << std::endl;
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
    else if (resultado == 'P')
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
    else if (resultado == 'P')
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