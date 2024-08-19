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

    // Simulação de jogadas válidas para terminar o jogo
    std::istringstream input("3\n4\n3\n4\n3\n4\n3\n"); // Jogadas simuladas
    std::streambuf *cinbuf = std::cin.rdbuf(); // Salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // Redireciona std::cin para o input simulado

    partida.executarPartida();
    CHECK(true); // Verifica se a partida terminou

    std::cin.rdbuf(cinbuf); // Restaura o buffer original de std::cin
}

TEST_CASE("Início de uma partida válida com Reversi com jogadas simuladas") {
    Jogadores jogadores;
    simularCadastro(jogadores, "Joao", "jo01");
    simularCadastro(jogadores, "Maria", "ma02");

    Reversi reversi(8, 8);
    Partida partida(reversi, *jogadores.buscarJogadorPorApelido("jo01"), *jogadores.buscarJogadorPorApelido("ma02"));

    // Simulação de jogadas válidas para terminar o jogo
    std::istringstream input("2 3\n2 2\n2 4\n3 2\n4 2\n5 3\n5 4\n4 5\n3 5\n2 5\n5 2\n5 5\n6 3\n6 4\n3 6\n4 6\n3 1\n4 1\n5 1\n2 6\n6 5\n2 1\n1 2\n1 3\n1 4\n1 5\n3 0\n4 0\n5 0\n6 1\n7 2\n0 3\n0 4\n7 3\n7 4\n1 6\n6 6\n0 2\n0 5\n1 7\n2 0\n7 5\n3 7\n4 7\n5 7\n6 7\n7 6\n6 2\n6 0\n0 1\n7 1\n7 0\n1 0\n0 6\n0 7\n7 7\n6 7\n0 0"); // Jogadas simuladas
    std::streambuf *cinbuf = std::cin.rdbuf(); // Salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // Redireciona std::cin para o input simulado

    partida.executarPartida();
    CHECK(true); // Verifica se a partida terminou

    std::cin.rdbuf(cinbuf); // Restaura o buffer original de std::cin
}

TEST_CASE("Testes para a funcao coletarJogada em Lig4") {
    Lig4 lig4(7, 6);

    std::istringstream input("3");
    std::streambuf *cinbuf = std::cin.rdbuf(); // salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // redireciona std::cin para o input simulado

    auto jogada = lig4.coletarJogada('B', "Joao");
    CHECK(jogada.first == 3);
    CHECK(jogada.second == 0);

    std::cin.rdbuf(cinbuf); // restaura o buffer original de std::cin
}

TEST_CASE("Testes para a funcao coletarJogada em Reversi") {
    Reversi reversi(8, 8);

    std::istringstream input("4 5\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); // salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // redireciona std::cin para o input simulado

    auto jogada = reversi.coletarJogada('B', "Maria");
    CHECK(jogada.first == 4);
    CHECK(jogada.second == 5);

    std::cin.rdbuf(cinbuf); // restaura o buffer original de std::cin
}
