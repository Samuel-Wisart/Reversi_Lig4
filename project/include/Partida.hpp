#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

class Partida {
public:
    void executarPartida(Tabuleiro& jogo, Jogador& jogador1, Jogador& jogador2);
    void atualizarEstatisticas(Reversi& reversi, char resultado, Jogador& jogador1, Jogador& jogador2);
    void atualizarEstatisticas(Lig4& lig4, char resultado, Jogador& jogador1, Jogador& jogador2);
private:
    std::string fazerJogada(char time,Tabuleiro& jogo, Jogador& jogador);
};

#endif // SISTEMA_HPP
