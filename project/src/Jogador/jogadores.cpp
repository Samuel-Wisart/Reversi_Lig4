#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string arquivoJogadores = "../data/jogadores.csv";

Jogadores::Jogadores() {
    carregarJogadores();
}

void Jogadores::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    for (const auto& jogador : jogadores) {
        if (jogador.getApelido() == apelido) {
            std::cout << "ERRO: jogador repetido\n";
            return;
        }
    }

    Jogador novoJogador(nome, apelido);
    jogadores.push_back(novoJogador);
    std::cout << "Jogador " << apelido << " cadastrado com sucesso\n";
}

void Jogadores::removerJogador(const std::string& apelido) {
    for (auto it = jogadores.begin(); it != jogadores.end(); ++it) {
        if (it->getApelido() == apelido) {
            jogadores.erase(it);
            std::cout << "Jogador " << apelido << " removido com sucesso\n";
            return;
        }
    }
    std::cout << "ERRO: jogador inexistente\n";
}

void Jogadores::listarJogadores() {
    for (const auto& jogador : jogadores) {
        std::cout << jogador;
    }
}

void Jogadores::salvarJogadores() {
    std::ofstream file(arquivoJogadores);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para escrita\n";
        return;
    }

    for (const auto& jogador : jogadores) {
        file << jogador.getNome() << "," << jogador.getApelido() << ","
             << jogador.getVitoriasReversi() << "," << jogador.getDerrotasReversi() << ","
             << jogador.getVitoriasLig4() << "," << jogador.getDerrotasLig4() << "\n";
    }

    file.close();
}

void Jogadores::carregarJogadores() {
    std::ifstream file(arquivoJogadores);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para leitura\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        std::string nome;
        std::string apelido;
        int vitoriasReversi;
        int derrotasReversi;
        int vitoriasLig4;
        int derrotasLig4;

        std::getline(iss, nome, ',');
        std::getline(iss, apelido, ',');
        std::getline(iss, token, ',');
        vitoriasReversi = std::stoi(token);
        std::getline(iss, token, ',');
        derrotasReversi = std::stoi(token);
        std::getline(iss, token, ',');
        vitoriasLig4 = std::stoi(token);
        std::getline(iss, token, ',');
        derrotasLig4 = std::stoi(token);

        Jogador jogador(nome, apelido, vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4);

        jogadores.push_back(jogador);
    }

    file.close();
}
