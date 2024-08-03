#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Tabuleiro.hpp"

class Reversi : public Tabuleiro {
public:
    void lerJogada() override;
    bool testarJogada() override;
    bool testarCondicaoVitoria() override;
    void imprimirTabuleiro() override;
};

#endif // REVERSI_HPP
