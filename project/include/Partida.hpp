#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include "Tabuleiro.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

/**
 * @brief Classe que representa uma partida entre dois jogadores em um jogo de tabuleiro.
 */
class Partida {
private:
    Tabuleiro &jogo;       ///< Referência ao jogo de tabuleiro sendo jogado.
    Jogador &jogador1;     ///< Referência ao primeiro jogador.
    Jogador &jogador2;     ///< Referência ao segundo jogador.
    
public:
    /**
     * @brief Construtor da classe Partida.
     * 
     * Inicializa uma nova partida entre dois jogadores em um jogo de tabuleiro específico.
     * 
     * @param jogo Referência ao objeto Tabuleiro que representa o jogo.
     * @param jogador1 Referência ao primeiro jogador.
     * @param jogador2 Referência ao segundo jogador.
     */
    Partida(Tabuleiro& jogo, Jogador& jogador1, Jogador& jogador2);
    
    /**
     * @brief Executa a partida entre os dois jogadores.
     * 
     * Controla o fluxo do jogo até que haja um vencedor ou empate.
     */
    void executarPartida();

    /**
     * @brief Atualiza as estatísticas dos jogadores com base no resultado da partida.
     * 
     * @param resultado Caractere que representa o resultado da partida ('B' para jogador1, 'P' para jogador2, 'E' para empate).
     */
    void atualizarEstatisticas(char resultado);

    /**
     * @brief Atualiza as estatísticas dos jogadores especificamente para o jogo Reversi.
     * 
     * @param resultado Caractere que representa o resultado da partida em Reversi ('B' para jogador1, 'P' para jogador2, 'E' para empate).
     */
    void atualizarEstatisticasReversi(char resultado);

    /**
     * @brief Atualiza as estatísticas dos jogadores especificamente para o jogo Lig4.
     * 
     * @param resultado Caractere que representa o resultado da partida em Lig4 ('B' para jogador1, 'P' para jogador2, 'E' para empate).
     */
    void atualizarEstatisticasLig4(char resultado);
    
private:
    /**
     * @brief Realiza uma jogada para o time especificado.
     * 
     * @param time Caractere representando o time que está jogando ('B' ou 'P').
     * @return std::string Mensagem indicando o resultado da jogada.
     */
    std::string fazerJogada(char time);
};

#endif // PARTIDA_HPP
