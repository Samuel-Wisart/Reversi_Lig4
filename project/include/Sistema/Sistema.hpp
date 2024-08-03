#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

class Sistema {
public:
    void executarPartida(Tabuleiro* jogo, Jogador& jogador1, Jogador& jogador2);
    void atualizarEstatisticas(Jogador& jogador1, Jogador& jogador2);
};

#endif // SISTEMA_HPP
