#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Partida.hpp"

int main() {
    Jogadores jogadores;
    Jogador* j1 = jogadores.buscarJogadorPorApelido("J1");
    Jogador* j2 = jogadores.buscarJogadorPorApelido("J2");

    Reversi reversi(8, 8);

    Partida partida(reversi, *j1, *j2);
    partida.executarPartida();


    return 0;
}