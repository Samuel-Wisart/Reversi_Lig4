#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

int main() {
    Jogadores Jogadores;
    Jogadores.carregarJogadores();

    Reversi reversi(8, 8);
    
    while (true) {
        reversi.imprimirTabuleiro();
        
        int x, y;
        std::cout << "Faca sua jogada B (x y): ";
        std::cin >> x >> y;
       
        if (x == -1 && y == -1) {
            break;
        }
        reversi.fazerJogada('B', x, y);
        reversi.imprimirTabuleiro();

        std::cout << "Faca sua jogada P (x y): ";
        std::cin >> x >> y;

        if (x == -1 && y == -1) {
            break;
        }
       
        reversi.fazerJogada('P', x, y);
    }

    return 0;
}