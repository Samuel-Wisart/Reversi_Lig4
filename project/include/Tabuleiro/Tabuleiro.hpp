#ifndef TABULEIRO_HPP
#define DE_TABULEIRO_HPP

class Tabuleiro {
public:
    virtual void lerJogada() = 0;
    virtual bool testarJogada() = 0;
    virtual bool testarCondicaoVitoria() = 0;
    virtual void imprimirTabuleiro() = 0;
};

#endif // TABULEIRO_HPP
