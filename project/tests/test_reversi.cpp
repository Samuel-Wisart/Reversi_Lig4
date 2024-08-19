#include "doctest.h"
#include "Reversi.hpp"

TEST_CASE("Testar inicialização do tabuleiro Reversi") {
    Reversi jogo(8, 8);
    CHECK(jogo.getCasa(3, 3).getCor() == 'P');
    CHECK(jogo.getCasa(3, 4).getCor() == 'B');
    CHECK(jogo.getCasa(4, 3).getCor() == 'B');
    CHECK(jogo.getCasa(4, 4).getCor() == 'P');
}

TEST_CASE("Testar jogada válida no Reversi") {
    Reversi jogo(8, 8);
    CHECK(jogo.testarJogada('B', 2, 3) == "OK");
    CHECK(jogo.testarJogada('P', 5, 3) == "OK");
}

TEST_CASE("Testar jogada inválida no Reversi") {
    Reversi jogo(8, 8);
    CHECK(jogo.testarJogada('B', 3, 3) == "Casa ja ocupada");
    CHECK(jogo.testarJogada('P', 0, 0) == "Sem pecas para capturar");
}
