#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <string>

/**
 * @brief Classe que representa uma casa no tabuleiro.
 * 
 * Cada casa possui coordenadas (x, y) e uma cor que indica o estado da casa.
 */
class Casa
{
private:
    int x;      ///< Coordenada x da casa.
    int y;      ///< Coordenada y da casa.
    char cor;   ///< Cor da casa (' ' para vazio, 'B' para branco, 'P' para preto).

public:
    /**
     * @brief Construtor da classe Casa.
     * 
     * Inicializa uma casa com as coordenadas especificadas e sem cor definida.
     * 
     * @param x Coordenada x da casa.
     * @param y Coordenada y da casa.
     */
    Casa(int x, int y);

    /**
     * @brief Construtor da classe Casa com cor.
     * 
     * Inicializa uma casa com as coordenadas e a cor especificadas.
     * 
     * @param x Coordenada x da casa.
     * @param y Coordenada y da casa.
     * @param cor Cor da casa.
     */
    Casa(int x, int y, char cor);

    /**
     * @brief Destrutor da classe Casa.
     */
    virtual ~Casa();

    // Getters e setters (sem comentários conforme preferência)

    virtual int getX();
    virtual int getY();
    virtual char getCor();
    virtual void setCor(char cor);

    /**
     * @brief Imprime as coordenadas e a cor da casa.
     */
    virtual void imprimirPosicao();
    
};

/**
 * @brief Classe que representa um tabuleiro de jogo.
 * 
 * Esta classe é abstrata e deve ser herdada por jogos específicos.
 */
class Tabuleiro
{
private:
    int altura;    ///< Altura do tabuleiro.
    int largura;   ///< Largura do tabuleiro.

public:
    Casa ***casas; ///< Matriz de casas que compõem o tabuleiro.

    /**
     * @brief Construtor da classe Tabuleiro.
     * 
     * Inicializa um tabuleiro com a altura e largura especificadas.
     * 
     * @param altura Altura do tabuleiro.
     * @param largura Largura do tabuleiro.
     */
    Tabuleiro(int altura, int largura);

    /**
     * @brief Destrutor da classe Tabuleiro.
     * 
     * Libera a memória alocada para as casas do tabuleiro.
     */
    virtual ~Tabuleiro();

    // Getters (sem comentários conforme preferência)

    int getAltura();
    int getLargura();
    Casa& getCasa(int x, int y);

    /**
     * @brief Realiza uma jogada no tabuleiro.
     * 
     * Método abstrato que deve ser implementado nas classes derivadas para definir como uma jogada é feita.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x onde a jogada será realizada.
     * @param y Coordenada y onde a jogada será realizada.
     */
    virtual void fazerJogada(char time, int x, int y) = 0;

    /**
     * @brief Testa se a jogada é válida.
     * 
     * Método abstrato que deve ser implementado nas classes derivadas para verificar a validade de uma jogada.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da jogada.
     * @param y Coordenada y da jogada.
     * @return std::string "OK" se a jogada é válida, ou uma mensagem de erro se não for.
     */
    virtual std::string testarJogada(char time, int x, int y) = 0;

    /**
     * @brief Verifica se ainda é possível realizar jogadas válidas no tabuleiro.
     * 
     * Método abstrato que deve ser implementado nas classes derivadas.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @return true Se ainda há jogadas possíveis.
     * @return false Se não há jogadas possíveis.
     */
    virtual bool checarSeDaPraJogar(char time) = 0;

    /**
     * @brief Testa as condições de vitória ou empate.
     * 
     * Método abstrato que deve ser implementado nas classes derivadas para verificar se há um vencedor ou se o jogo terminou em empate.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @return char Caractere representando o vencedor ('B' ou 'P'), 'E' para empate, ou ' ' para continuar o jogo.
     */
    virtual char testarCondicaoVitoria(char time) = 0;

    /**
     * @brief Coleta a jogada do jogador.
     * 
     * Método abstrato que deve ser implementado nas classes derivadas para coletar a jogada do jogador.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param apelido Apelido do jogador.
     * @return std::pair<int, int> Par de coordenadas x e y onde a peça será jogada.
     */
    virtual std::pair<int, int> coletarJogada(char time, std::string apelido) = 0;
    
    /**
     * @brief Imprime o estado atual do tabuleiro.
     * 
     * Este método pode ser sobrescrito nas classes derivadas para definir como o tabuleiro é impresso.
     */
    virtual void imprimirTabuleiro();
};

/**
 * @brief Converte um número em uma letra correspondente.
 * 
 * @param numero O número a ser convertido.
 * @return char A letra correspondente ao número.
 */
char numeroParaLetra(int numero);

#endif // TABULEIRO_HPP
