#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Partida.hpp"

int main() {
    Jogadores jogadores;
    Jogador* j1 = jogadores.buscarJogadorPorApelido("J1");
    Jogador* j2 = jogadores.buscarJogadorPorApelido("J2");

    if (j1 == nullptr || j2 == nullptr) {
        std::cout << "Jogadores nao encontrados" << std::endl;
        
        jogadores.cadastrarJogador("J1", "J1");
        jogadores.cadastrarJogador("J2", "J2");
        j1 = jogadores.buscarJogadorPorApelido("J1");
        j2 = jogadores.buscarJogadorPorApelido("J2");
    }

    Lig4 lig4(8, 8);

    Partida partida(lig4, *j1, *j2);
    partida.executarPartida();
    jogadores.salvarJogadores();


    return 0;
}