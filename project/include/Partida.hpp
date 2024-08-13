#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include "Tabuleiro.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

class Partida {
private:
    Tabuleiro& jogo;
    Jogador jogador1;
    Jogador jogador2;
public:
    Partida(Tabuleiro& jogo, Jogador& jogador1, Jogador& jogador2);
    
    void executarPartida();
    void atualizarEstatisticas(char resultado);
    void atualizarEstatisticasReversi(char resultado);
    void atualizarEstatisticasLig4(char resultado);
private:
    std::string fazerJogada(char time);
};

#endif // SISTEMA_HPP
