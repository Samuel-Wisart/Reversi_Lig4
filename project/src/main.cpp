#include <iostream>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

int main() {
    Jogador jogadorManager;

    jogadorManager.cadastrarJogador("Nome1", "Apelido1");
    jogadorManager.cadastrarJogador("Nome2", "Apelido2");
    jogadorManager.listarJogadores();

    jogadorManager.salvarJogadores("jogadores.csv");
    jogadorManager.removerJogador("Apelido1");

    std::cout << "\nApós remoção:\n";
    jogadorManager.listarJogadores();

    jogadorManager.carregarJogadores("jogadores.csv");
    
    std::cout << "\nApós carregar do arquivo:\n";
    jogadorManager.listarJogadores();

    return 0;
}
