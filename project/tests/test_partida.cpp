#include "doctest.h"
#include "Partida.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include <sstream>

TEST_CASE("Teste de uma partida de Reversi com vitoria do jogador 1 em um tabuleiro 4x4") {
    Reversi reversi(4, 4);
    Jogador jogador1("Alice", "alice");
    Jogador jogador2("Bob", "bob");
    Partida partida(reversi, jogador1, jogador2);

    reversi.fazerJogada('B', 0, 0);
    
    std::istringstream input("3 3\n"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); 
    std::cin.rdbuf(input.rdbuf()); 

    partida.executarPartida();

    std::cin.rdbuf(cinbuf); 

    CHECK(jogador1.getVitoriasReversi() == 1);
    CHECK(jogador2.getDerrotasReversi() == 1);
}

TEST_CASE("Teste de uma partida de Lig4 com empate") {
    Lig4 lig4(1, 2);
    Jogador jogador1("Alice", "alice");
    Jogador jogador2("Bob", "bob");
    Partida partida(lig4, jogador1, jogador2);

    lig4.fazerJogada('P', 0, 0);

    lig4.imprimirTabuleiro();

    std::istringstream input("1\n");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    partida.executarPartida();

    std::cin.rdbuf(cinbuf);

    CHECK(jogador1.getEmpatesLig4() == 1);
    CHECK(jogador2.getEmpatesLig4() == 1);
}


TEST_CASE("Teste de uma partida de Lig4 com vitoria do jogador 2") {
    Lig4 lig4(6, 7);
    Jogador jogador1("Alice", "alice");
    Jogador jogador2("Bob", "bob");
    Partida partida(lig4, jogador1, jogador2);

    lig4.fazerJogada('B', 1, 0);  
    lig4.fazerJogada('P', 2, 0);  
    lig4.fazerJogada('B', 1, 0);  
    lig4.fazerJogada('P', 2, 0);  
    lig4.fazerJogada('B', 1, 0); 
    lig4.fazerJogada('P', 2, 0);  

    lig4.imprimirTabuleiro();

    std::istringstream input("0 2\n");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    partida.executarPartida();

    std::cin.rdbuf(cinbuf);

    CHECK(jogador1.getDerrotasLig4() == 1);
    CHECK(jogador2.getVitoriasLig4() == 1);
}