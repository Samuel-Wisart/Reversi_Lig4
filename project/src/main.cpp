#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

int main() {

    Jogadores Jogadores;
    Jogadores.carregarJogadores();

    Reversi reversi(8, 8);
    reversi.imprimirTabuleiro();
    reversi.fazerJogada('B', 1, 1);
    reversi.imprimirTabuleiro();

    return 0;
}
