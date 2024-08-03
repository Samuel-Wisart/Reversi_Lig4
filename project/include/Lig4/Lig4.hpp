#ifndef LIG4_HPP
#define LIG4_HPP

#include "Tabuleiro.hpp"

class Lig4 : public Tabuleiro {
public:
    void lerJogada() override;
    bool testarJogada() override;
    bool testarCondicaoVitoria() override;
    void imprimirTabuleiro() override;
};

#endif // LIG4_HPP
