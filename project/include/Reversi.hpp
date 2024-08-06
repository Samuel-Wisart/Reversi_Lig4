#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Tabuleiro.hpp"

class Reversi : public Tabuleiro {
private:
    bool testarCondicaoVitoria(char time, int x, int y) override;

public:
    Reversi(int altura, int largura);
    virtual ~Reversi();

    void fazerJogada(char time, int x, int y) override;
    bool testarJogada(char time, int x, int y) override;

};

#endif // REVERSI_HPP
