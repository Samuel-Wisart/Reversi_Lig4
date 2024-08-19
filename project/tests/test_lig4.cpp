#include "doctest.h"
#include "Lig4.hpp"
#include "Tabuleiro.hpp"
#include <stdexcept>

TEST_CASE("Inicialização do tabuleiro Lig4") {
    Lig4 jogo(6, 7);

    CHECK(jogo.getAltura() == 6);
    CHECK(jogo.getLargura() == 7);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            CHECK(jogo.getCasa(i, j).getCor() == ' '); 
        }
    }
}

TEST_CASE("Testar jogadas válidas no Lig4") {
    Lig4 jogo(6, 7);

    CHECK(jogo.testarJogada('B', 0, 0) == "OK");
    CHECK_NOTHROW(jogo.fazerJogada('B', 0, 0));

    CHECK(jogo.getCasa(0, 0).getCor() == 'B');
}

TEST_CASE("Testar jogadas inválidas no Lig4") {
    Lig4 jogo(6, 7);

    CHECK(jogo.testarJogada('B', -1, 0) == "Posicao invalida, x fora do tabuleiro");
    CHECK_THROWS_AS(jogo.fazerJogada('B', -1, 0), std::invalid_argument);

    CHECK(jogo.testarJogada('B', 7, 0) == "Posicao invalida, x fora do tabuleiro");
    CHECK_THROWS_AS(jogo.fazerJogada('B', 7, 0), std::invalid_argument);

    CHECK(jogo.testarJogada('B', 0, 1) == "Posicao invalida, y deve ser 0");
    CHECK_THROWS_AS(jogo.fazerJogada('B', 0, 1), std::invalid_argument);
}

TEST_CASE("Testar condição de vitória no Lig4") {
    Lig4 jogo(6, 7);

    jogo.fazerJogada('B', 0, 0);
    jogo.fazerJogada('B', 0, 0);
    jogo.fazerJogada('B', 0, 0);
    jogo.fazerJogada('B', 0, 0);

    CHECK(jogo.testarCondicaoVitoria('B') == 'B');
}

TEST_CASE("Testar função de soltar peça no Lig4") {
    Lig4 jogo(6, 7);

    jogo.fazerJogada('B', 0, 0);

    CHECK(jogo.getCasa(0, 0).getCor() == 'B');
    CHECK(jogo.getCasa(0, 1).getCor() == '|');
}

TEST_CASE("Verificação de jogadas válidas no Lig4") {
    Lig4 jogo(6, 7);

    CHECK(jogo.checarSeDaPraJogar('B') == true);

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            jogo.fazerJogada('B', i, 0);  // Preenche o tabuleiro
        }
    }

    CHECK(jogo.checarSeDaPraJogar('B') == false);
}
