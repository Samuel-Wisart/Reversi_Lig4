#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

int main() {

    Jogadores jogadorManager;

    jogadorManager.cadastrarJogador("Nome1", "Apelido1");
    jogadorManager.cadastrarJogador("Nome2", "Apelido2");
    jogadorManager.listarJogadores();

    jogadorManager.salvarJogadores();
    jogadorManager.removerJogador("Apelidxo1");

    std::cout << "\n\nApós remoção:\n\n";
    jogadorManager.listarJogadores();

    jogadorManager.salvarJogadores();

    return 0;
}
