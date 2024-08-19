#ifndef LIG4_HPP
#define LIG4_HPP

#include "Tabuleiro.hpp"
#include <vector>
#include <utility>
#include <string>

/**
 * @brief Classe que representa o jogo Lig4.
 * 
 * Herda da classe Tabuleiro e implementa a lógica específica do jogo Lig4.
 */
class Lig4 : public Tabuleiro
{
public:
    /**
     * @brief Construtor da classe Lig4.
     * 
     * Inicializa o jogo Lig4 com um tabuleiro de tamanho especificado.
     * 
     * @param altura Altura do tabuleiro.
     * @param largura Largura do tabuleiro.
     */
    Lig4(int altura, int largura);

    /**
     * @brief Destrutor da classe Lig4.
     */
    virtual ~Lig4();

    /**
     * @brief Realiza uma jogada no jogo Lig4.
     * 
     * Verifica a validade da jogada e, se válida, faz a peça cair na posição apropriada.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x onde a peça será solta.
     * @param y Coordenada y (deve ser 0 para Lig4).
     * 
     * @throws std::invalid_argument Se a jogada não for válida.
     */
    void fazerJogada(char time, int x, int y) override;

    /**
     * @brief Testa se a jogada é válida.
     * 
     * Verifica as condições de validade da jogada, como posição dentro dos limites do tabuleiro e se a coluna está cheia.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da jogada.
     * @param y Coordenada y da jogada (deve ser 0 para Lig4).
     * @return std::string "OK" se a jogada é válida, ou uma mensagem de erro se não for.
     */
    std::string testarJogada(char time, int x, int y) override;

    /**
     * @brief Verifica se ainda é possível realizar jogadas válidas no tabuleiro.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @return true Se ainda há jogadas possíveis.
     * @return false Se não há jogadas possíveis.
     */
    bool checarSeDaPraJogar(char time);

    /**
     * @brief Testa as condições de vitória ou empate.
     * 
     * Verifica se há um vencedor ou se o jogo terminou em empate.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @return char Caractere representando o vencedor ('B' ou 'P'), 'E' para empate, ou ' ' para continuar o jogo.
     */
    char testarCondicaoVitoria(char time) override;

    /**
     * @brief Coleta a jogada do jogador.
     * 
     * Solicita ao jogador a coordenada x para a jogada e verifica sua validade.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param apelido Apelido do jogador.
     * @return std::pair<int, int> Par de coordenadas x e y onde a peça será jogada (y é sempre 0).
     * 
     * @throws std::invalid_argument Se o time for inválido.
     */
    std::pair<int, int> coletarJogada(char time, std::string apelido) override;

    /**
     * @brief Imprime o estado atual do tabuleiro.
     */
    void imprimirTabuleiro() override;

private:
    /**
     * @brief Verifica se uma peça na posição (x, y) formou uma sequência vitoriosa.
     * 
     * Testa em todas as direções possíveis para determinar se a peça forma uma sequência de quatro peças do mesmo time.
     * 
     * @param x Coordenada x da peça.
     * @param y Coordenada y da peça.
     * @return true Se a peça forma uma sequência vitoriosa.
     * @return false Se a peça não forma uma sequência vitoriosa.
     */
    bool pecaVenceu(int x, int y);

    /**
     * @brief Verifica se uma peça na posição (x, y) formou uma sequência vitoriosa em uma direção específica.
     * 
     * Testa em uma direção específica para determinar se a peça forma uma sequência de quatro peças do mesmo time.
     * 
     * @param x Coordenada x da peça.
     * @param y Coordenada y da peça.
     * @param direcionador Função que define a direção a ser verificada.
     * @return true Se a peça forma uma sequência vitoriosa na direção especificada.
     * @return false Se a peça não forma uma sequência vitoriosa na direção especificada.
     */
    bool pecaVenceu(int x, int y, void(direcionador)(int &, int &));

    /**
     * @brief Solta uma peça no tabuleiro na coluna especificada.
     * 
     * A peça cairá na posição mais baixa disponível na coluna.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da coluna onde a peça será solta.
     * 
     * @throws std::runtime_error Se ocorrer um erro inesperado durante a execução.
     */
    void soltarPeca(char time, int x);

    /**
     * @brief Testa se há uma condição de vitória por ligação de quatro peças.
     * 
     * Verifica se há uma sequência de quatro peças do mesmo time em qualquer direção.
     * 
     * @return char Caractere representando o vencedor ('B' ou 'P'), ou ' ' se não houver vencedor.
     */
    char testarVitoriaPorLigacao();

    /**
     * @brief Remove as marcações temporárias de queda de peças do tabuleiro.
     */
    void retirarMarcacoesDeQuedaDePeca();
};

/**
 * @brief Função auxiliar para mudar a cor de uma casa.
 * 
 * @param casa Ponteiro para a casa cuja cor será alterada.
 * @return true Se a cor foi alterada com sucesso.
 * @return false Se a cor não foi alterada.
 */
bool mudarCor(Casa *casa);

#endif // LIG4_HPP
