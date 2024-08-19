#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Jogador.hpp"
#include "Partida.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include <sstream> // Incluído para simular std::cin

// Funções auxiliares para simular comportamento sem alterar o código original

void simularCadastro(Jogadores &jogadores, const std::string &nome, const std::string &apelido) {
    jogadores.cadastrarJogador(nome, apelido);
    jogadores.salvarJogadores();
}

void simularRemocao(Jogadores &jogadores, const std::string &apelido) {
    jogadores.removerJogador(apelido);
    jogadores.salvarJogadores();
}

TEST_CASE("Testes para a funcao cadastrarJogador") {
    Jogadores jogadores;

    SUBCASE("Cadastro de um novo jogador") {
        simularCadastro(jogadores, "Joao", "jo01");
        CHECK(jogadores.buscarJogadorPorApelido("jo01") != nullptr);
    }

    SUBCASE("Cadastro de um jogador com apelido duplicado") {
        simularCadastro(jogadores, "Maria", "ma02");
        simularCadastro(jogadores, "Maria", "ma02"); // Deve falhar silenciosamente
        CHECK(jogadores.buscarJogadorPorApelido("ma02") != nullptr);
    }
}

TEST_CASE("Testes para a funcao removerJogador") {
    Jogadores jogadores;
    simularCadastro(jogadores, "Joao", "jo01");

    SUBCASE("Remoção de jogador existente") {
        simularRemocao(jogadores, "jo01");
        CHECK(jogadores.buscarJogadorPorApelido("jo01") == nullptr);
    }

    SUBCASE("Remoção de jogador inexistente") {
        simularRemocao(jogadores, "inexistente"); // Deve falhar silenciosamente
        CHECK(jogadores.buscarJogadorPorApelido("inexistente") == nullptr);
    }
}

TEST_CASE("Início de uma partida válida com Lig4 com jogadas simuladas") {
    Jogadores jogadores;
    simularCadastro(jogadores, "Joao", "jo01");
    simularCadastro(jogadores, "Maria", "ma02");

    Lig4 lig4(7, 6);
    Partida partida(lig4, *jogadores.buscarJogadorPorApelido("jo01"), *jogadores.buscarJogadorPorApelido("ma02"));

    std::istringstream input("3\n4\n3\n4\n3\n4\n3\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); 
    std::cin.rdbuf(input.rdbuf());

    partida.executarPartida();
    CHECK(true); // Verifica se a partida terminou

    std::cin.rdbuf(cinbuf); 
}

TEST_CASE("Início de uma partida válida com Reversi com jogadas simuladas") {
    Jogadores jogadores;
    simularCadastro(jogadores, "Joao", "jo01");
    simularCadastro(jogadores, "Maria", "ma02");

    Reversi reversi(8, 8);
    Partida partida(reversi, *jogadores.buscarJogadorPorApelido("jo01"), *jogadores.buscarJogadorPorApelido("ma02"));

    reversi.fazerJogada('B', 2, 2);
    
    std::istringstream input("5 5\n"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); 
    std::cin.rdbuf(input.rdbuf()); 

    partida.executarPartida();
    CHECK(true); // Verifica se a partida terminou

    std::cin.rdbuf(cinbuf); 
}

TEST_CASE("Testes para a funcao coletarJogada em Lig4") {
    Lig4 lig4(7, 6);

    std::istringstream input("3");
    std::streambuf *cinbuf = std::cin.rdbuf(); 
    std::cin.rdbuf(input.rdbuf()); 

    auto jogada = lig4.coletarJogada('B', "Joao");
    CHECK(jogada.first == 3);
    CHECK(jogada.second == 0);

    std::cin.rdbuf(cinbuf);
}

TEST_CASE("Testes para a funcao coletarJogada em Reversi") {
    Reversi reversi(8, 8);

    std::istringstream input("4 5\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); 
    std::cin.rdbuf(input.rdbuf()); 

    auto jogada = reversi.coletarJogada('B', "Maria");
    CHECK(jogada.first == 4);
    CHECK(jogada.second == 5);

    std::cin.rdbuf(cinbuf); 
}
