#include "doctest.h"
#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <cstdio> 

// Helper function para limpar o ambiente de testes
void limparArquivoJogadores() {
    std::remove("../data/jogadores.csv");
}

TEST_CASE("Testar criação de jogador e getters") {
    Jogador jogador("Joao", "joaozinho");

    CHECK(jogador.getNome() == "Joao");
    CHECK(jogador.getApelido() == "joaozinho");
    CHECK(jogador.getVitoriasReversi() == 0);
    CHECK(jogador.getDerrotasReversi() == 0);
    CHECK(jogador.getEmpatesReversi() == 0);
    CHECK(jogador.getVitoriasLig4() == 0);
    CHECK(jogador.getDerrotasLig4() == 0);
    CHECK(jogador.getEmpatesLig4() == 0);
}

TEST_CASE("Testar incremento de vitorias, derrotas e empates") {
    Jogador jogador("Maria", "maricota");

    jogador.incrementarVitoriasReversi();
    jogador.incrementarDerrotasLig4();
    jogador.incrementarEmpatesReversi();
    jogador.incrementarVitoriasLig4();

    CHECK(jogador.getVitoriasReversi() == 1);
    CHECK(jogador.getDerrotasLig4() == 1);
    CHECK(jogador.getEmpatesReversi() == 1);
    CHECK(jogador.getVitoriasLig4() == 1);
}

TEST_CASE("Testar cadastro e busca de jogadores") {
    limparArquivoJogadores();
    Jogadores jogadores;

    jogadores.cadastrarJogador("Joao", "joaozinho");
    jogadores.cadastrarJogador("Maria", "maricota");

    Jogador* jogador1 = jogadores.buscarJogadorPorApelido("joaozinho");
    Jogador* jogador2 = jogadores.buscarJogadorPorApelido("maricota");

    REQUIRE(jogador1 != nullptr);
    CHECK(jogador1->getNome() == "Joao");

    REQUIRE(jogador2 != nullptr);
    CHECK(jogador2->getNome() == "Maria");
}

TEST_CASE("Testar remoção de jogador") {
    limparArquivoJogadores();
    Jogadores jogadores;

    jogadores.cadastrarJogador("Joao", "joaozinho");
    jogadores.cadastrarJogador("Maria", "maricota");

    jogadores.removerJogador("joaozinho");

    Jogador* jogador1 = jogadores.buscarJogadorPorApelido("joaozinho");
    Jogador* jogador2 = jogadores.buscarJogadorPorApelido("maricota");

    CHECK(jogador1 == nullptr);
    REQUIRE(jogador2 != nullptr);
    CHECK(jogador2->getNome() == "Maria");
}

TEST_CASE("Testar salvar e carregar jogadores") {
    limparArquivoJogadores();
    {
        Jogadores jogadores;
        jogadores.cadastrarJogador("Joao", "joaozinho");
        jogadores.cadastrarJogador("Maria", "maricota");
        jogadores.salvarJogadores();
    }

    Jogadores jogadoresCarregados;
    Jogador* jogador1 = jogadoresCarregados.buscarJogadorPorApelido("joaozinho");
    Jogador* jogador2 = jogadoresCarregados.buscarJogadorPorApelido("maricota");

    REQUIRE(jogador1 != nullptr);
    CHECK(jogador1->getNome() == "Joao");

    REQUIRE(jogador2 != nullptr);
    CHECK(jogador2->getNome() == "Maria");
}

TEST_CASE("Testar erro ao cadastrar jogador repetido") {
    limparArquivoJogadores();
    Jogadores jogadores;

    jogadores.cadastrarJogador("Joao", "joaozinho");
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    jogadores.cadastrarJogador("Joao", "joaozinho");

    std::cout.rdbuf(old);
    CHECK(buffer.str() == "ERRO: jogador repetido\n");
}

TEST_CASE("Testar erro ao remover jogador inexistente") {
    limparArquivoJogadores();
    Jogadores jogadores;

    jogadores.cadastrarJogador("Joao", "joaozinho");
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    jogadores.removerJogador("maria");

    std::cout.rdbuf(old);
    CHECK(buffer.str() == "ERRO: jogador inexistente\n");
}