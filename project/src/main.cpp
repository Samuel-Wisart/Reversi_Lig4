#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

int main() {
    Jogador jogador1, jogador2;
    jogador1.cadastrarJogador("Nome1", "Apelido1");
    jogador2.cadastrarJogador("Nome2", "Apelido2");
    
    Reversi reversi;
    Sistema sistema;
    sistema.executarPartida(&reversi, jogador1, jogador2);
    
    return 0;
}
