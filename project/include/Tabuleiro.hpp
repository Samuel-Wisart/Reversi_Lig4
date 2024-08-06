#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

class Tabuleiro {
public:
    virtual void lerJogada() = 0;
    virtual bool testarJogada() = 0;
    virtual bool testarCondicaoVitoria() = 0;
    virtual void imprimirTabuleiro() = 0;
};

class Casa {
private:
    int x;
    int y;
    char cor;
    bool vazia;
public:
    virtual void lerCasa() = 0;
    virtual void imprimirCasa() = 0;
};

#endif // TABULEIRO_HPP
