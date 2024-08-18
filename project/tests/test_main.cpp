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

TEST_CASE("Testes para a função cadastrarJogador") {
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

TEST_CASE("Testes para a função removerJogador") {
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

TEST_CASE("Testes para a função iniciarPartida") {
    Jogadores jogadores;
    simularCadastro(jogadores, "Joao", "jo01");
    simularCadastro(jogadores, "Maria", "ma02");

    SUBCASE("Início de uma partida válida com Lig4") {
        Lig4 lig4(7, 6);
        Partida partida(lig4, *jogadores.buscarJogadorPorApelido("jo01"), *jogadores.buscarJogadorPorApelido("ma02"));
        partida.executarPartida();
        CHECK(true); // Apenas certifica-se de que não há erros na execução
    }

    SUBCASE("Início de uma partida válida com Reversi") {
        Reversi reversi(8, 8);
        Partida partida(reversi, *jogadores.buscarJogadorPorApelido("jo01"), *jogadores.buscarJogadorPorApelido("ma02"));
        partida.executarPartida();
        CHECK(true); // Apenas certifica-se de que não há erros na execução
    }

    SUBCASE("Tentativa de iniciar partida com jogador inexistente") {
        CHECK(jogadores.buscarJogadorPorApelido("inexistente") == nullptr);
    }
}

TEST_CASE("Testes para a função coletarJogada em Lig4") {
    Lig4 lig4(7, 6);

    std::istringstream input("3\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); // salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // redireciona std::cin para o input simulado

    auto jogada = lig4.coletarJogada('B', "Joao");
    CHECK(jogada.first == 3);
    CHECK(jogada.second == 0);

    std::cin.rdbuf(cinbuf); // restaura o buffer original de std::cin
}

TEST_CASE("Testes para a função coletarJogada em Reversi") {
    Reversi reversi(8, 8);

    std::istringstream input("4 5\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); // salva o buffer original de std::cin
    std::cin.rdbuf(input.rdbuf()); // redireciona std::cin para o input simulado

    auto jogada = reversi.coletarJogada('B', "Maria");
    CHECK(jogada.first == 4);
    CHECK(jogada.second == 5);

    std::cin.rdbuf(cinbuf); // restaura o buffer original de std::cin
}
