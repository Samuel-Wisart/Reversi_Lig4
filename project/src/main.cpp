#include <iostream>
#include <thread>
#include <mutex>
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"
#include "Partida.hpp"

/**
 * @brief Exibe o menu principal e gerencia as interações com o usuário.
 * 
 * @param jogadores Referência ao objeto que gerencia os jogadores cadastrados.
 */
void menuPrincipal(Jogadores &jogadores);

/**
 * @brief Cadastra um novo jogador no sistema.
 * 
 * @param jogadores Referência ao objeto que gerencia os jogadores cadastrados.
 */
void cadastrarJogador(Jogadores &jogadores);

/**
 * @brief Remove um jogador cadastrado no sistema.
 * 
 * @param jogadores Referência ao objeto que gerencia os jogadores cadastrados.
 */
void removerJogador(Jogadores &jogadores);

/**
 * @brief Lista todos os jogadores cadastrados.
 * 
 * @param jogadores Referência ao objeto que gerencia os jogadores cadastrados.
 */
void listarJogadores(Jogadores &jogadores);

/**
 * @brief Inicia uma nova partida entre dois jogadores.
 * 
 * @param jogadores Referência ao objeto que gerencia os jogadores cadastrados.
 */
void iniciarPartida(Jogadores &jogadores);

/**
 * @brief Função principal que inicializa o sistema.
 * 
 * @return int Código de status da aplicação.
 */

int main() {
    Jogadores jogadores;

    menuPrincipal(jogadores);

    jogadores.salvarJogadores();

    return 0;
}

void menuPrincipal(Jogadores &jogadores) {
    int opcao = 0;

    while (true) { 
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Cadastrar Jogador\n";
        std::cout << "2. Remover Jogador\n";
        std::cout << "3. Listar Jogadores\n";
        std::cout << "4. Iniciar Partida\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarJogador(jogadores);
                break;
            case 2:
                removerJogador(jogadores);
                break;
            case 3:
                listarJogadores(jogadores);
                break;
            case 4:
                iniciarPartida(jogadores);
                break;
            case 5:
                std::cout << "Saindo...\n";
                return; 
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
        }
    }
}

void cadastrarJogador(Jogadores &jogadores) {
    std::string nome, apelido;
    std::cout << "Digite o nome do jogador: ";
    std::cin >> nome;
    std::cout << "Digite o apelido do jogador: ";
    std::cin >> apelido;

    jogadores.cadastrarJogador(nome, apelido);
    std::cout << "Jogador cadastrado com sucesso!\n";
    jogadores.salvarJogadores();
}

void removerJogador(Jogadores &jogadores) {
    std::string apelido;
    std::cout << "Digite o apelido do jogador a ser removido: ";
    std::cin >> apelido;

    jogadores.removerJogador(apelido);
    std::cout << "Jogador removido com sucesso!\n";
    jogadores.salvarJogadores();
}

void listarJogadores(Jogadores &jogadores) {
    std::cout << "\n--- Lista de Jogadores ---\n";
    jogadores.listarJogadores();
}

void iniciarPartida(Jogadores &jogadores) {
    std::string apelido1, apelido2;
    int escolhaJogo = 0;

    std::cout << "Digite o apelido do Jogador 1: ";
    std::cin >> apelido1;
    Jogador* j1 = jogadores.buscarJogadorPorApelido(apelido1);
    if (j1 == nullptr) {
        std::cout << "Jogador 1 nao encontrado.\n";
        return;
    }

    std::cout << "Digite o apelido do Jogador 2: ";
    std::cin >> apelido2;
    Jogador* j2 = jogadores.buscarJogadorPorApelido(apelido2);
    if (j2 == nullptr) {
        std::cout << "Jogador 2 nao encontrado.\n";
        return;
    }

    std::cout << "Escolha o jogo:\n";
    std::cout << "1. Lig4\n";
    std::cout << "2. Reversi\n";
    std::cout << "Escolha uma opcao: ";
    std::cin >> escolhaJogo;

    if (escolhaJogo == 1) {
        Lig4 lig4(7, 6);
        Partida partida(lig4, *j1, *j2);
        partida.executarPartida();
    } else if (escolhaJogo == 2) {
        Reversi reversi(8, 8);
        Partida partida(reversi, *j1, *j2);
        partida.executarPartida();
    } else {
        std::cout << "Opcao invalida. Partida nao iniciada.\n";
    }

    jogadores.salvarJogadores();
}
