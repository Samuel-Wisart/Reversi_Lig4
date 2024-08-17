#ifndef LIG4_HPP
#define LIG4_HPP

#include "Tabuleiro.hpp"
#include <vector>
#include <utility>
#include <string>

class Lig4 : public Tabuleiro {
public:
    Lig4(int altura, int largura);
    virtual ~Lig4();

    void fazerJogada(char time, int x, int y) override;
    std::string testarJogada(char time, int x, int y) override;
    bool checarSeDaPraJogar(char time);
    char testarCondicaoVitoria(char time) override;

    void imprimirTabuleiro() override;

private:
    bool pecaVenceu(int x, int y);
    bool pecaVenceu(int x, int y, void (direcionador)(int&, int&));
    void soltarPeca(char time, int x);
    char testarVitoriaPorLigacao();
    void retirarMarcacoesDeQuedaDePeca();

};

bool mudarCor(Casa *casa);

#endif // LIG4_HPP
