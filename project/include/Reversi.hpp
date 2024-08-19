#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Tabuleiro.hpp"
#include <vector>
#include <utility>
#include <string>

/**
 * @brief Classe que representa o jogo Reversi.
 * 
 * Herda da classe Tabuleiro e implementa a lógica específica do jogo Reversi.
 */
class Reversi : public Tabuleiro {
public:
    /**
     * @brief Construtor da classe Reversi.
     * 
     * Inicializa o jogo Reversi com um tabuleiro de tamanho especificado.
     * 
     * @param altura Altura do tabuleiro.
     * @param largura Largura do tabuleiro.
     */
    Reversi(int altura, int largura);

    /**
     * @brief Destrutor da classe Reversi.
     */
    virtual ~Reversi();

    /**
     * @brief Realiza uma jogada no jogo Reversi.
     * 
     * Verifica a validade da jogada e, se válida, realiza as alterações necessárias no tabuleiro.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x onde a peça será jogada.
     * @param y Coordenada y onde a peça será jogada.
     * 
     * @throws std::invalid_argument Se a jogada não for válida.
     */
    void fazerJogada(char time, int x, int y) override;

    /**
     * @brief Testa se a jogada é válida.
     * 
     * Verifica as condições de validade da jogada, como posição dentro dos limites do tabuleiro e se a jogada respeita as regras do jogo.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da jogada.
     * @param y Coordenada y da jogada.
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
     * Solicita ao jogador as coordenadas x e y para a jogada e verifica sua validade.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param apelido Apelido do jogador.
     * @return std::pair<int, int> Par de coordenadas x e y onde a peça será jogada.
     * 
     * @throws std::invalid_argument Se o time for inválido.
     */
    std::pair<int, int> coletarJogada(char time, std::string apelido) override;

private:
    /**
     * @brief Seleciona as peças que serão alteradas após uma jogada.
     * 
     * Determina quais peças serão viradas com base na jogada realizada.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da jogada.
     * @param y Coordenada y da jogada.
     * @return std::vector<std::pair<int, int>> Vetor de pares de coordenadas das peças que serão alteradas.
     */
    std::vector<std::pair<int, int>> selecionarPecasAlteradas(char time, int x, int y);

    /**
     * @brief Seleciona as peças que serão alteradas após uma jogada em uma direção específica.
     * 
     * Determina quais peças serão viradas em uma direção específica com base na jogada realizada.
     * 
     * @param time Caractere representando o time ('B' ou 'P').
     * @param x Coordenada x da jogada.
     * @param y Coordenada y da jogada.
     * @param direcionador Função que define a direção a ser verificada.
     * @return std::vector<std::pair<int, int>> Vetor de pares de coordenadas das peças que serão alteradas na direção especificada.
     */
    std::vector<std::pair<int, int>> selecionarPecasAlteradas(char time, int x, int y, void (direcionador)(int&, int&));

};

/**
 * @brief Função auxiliar para mudar a cor de uma casa.
 * 
 * @param casa Ponteiro para a casa cuja cor será alterada.
 * @return true Se a cor foi alterada com sucesso.
 * @return false Se a cor não foi alterada.
 */
bool mudarCor(Casa *casa);

/**
 * @brief Sobrecarga do operador += para adicionar elementos de um vetor a outro.
 * 
 * @tparam V Tipo dos elementos do vetor.
 * @param vec1 Vetor que receberá os elementos.
 * @param vec2 Vetor cujos elementos serão adicionados ao vec1.
 * @return std::vector<V>& Referência ao vetor vec1 após a adição dos elementos.
 */
template <typename V>
std::vector<V>& operator+=(std::vector<V>& vec1, const std::vector<V>& vec2) {
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

#endif // REVERSI_HPP
