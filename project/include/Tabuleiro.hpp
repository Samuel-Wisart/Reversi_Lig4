#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

class Casa
{
private:
    int x;
    int y;
    char cor;

public:
    Casa(int x, int y);
    Casa(int x, int y, char cor);
    virtual ~Casa();

    virtual int getX();
    virtual int getY();
    virtual char getCor();
    virtual void setCor(char cor);
    virtual void imprimirPosicao();
    
};

class Tabuleiro
{
private:
    int altura;
    int largura;

    virtual bool testarCondicaoVitoria(char time, int x, int y) = 0;
public:
    Casa ***casas;

    Tabuleiro(int altura, int largura);
    virtual ~Tabuleiro();	

    virtual void fazerJogada(char time, int x, int y) = 0;
    virtual bool testarJogada(char time, int x, int y) = 0;
    virtual void imprimirTabuleiro();
};

char numeroParaLetra(int numero);

#endif // TABULEIRO_HPP
