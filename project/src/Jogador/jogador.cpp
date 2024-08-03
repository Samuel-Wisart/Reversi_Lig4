#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Jogador::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    for (const auto& jogador : jogadores) {
        if (jogador.apelido == apelido) {
            std::cout << "ERRO: jogador repetido\n";
            return;
        }
    }

    Jogador novoJogador;
    novoJogador.nome = nome;
    novoJogador.apelido = apelido;
    jogadores.push_back(novoJogador);
    std::cout << "Jogador " << apelido << " cadastrado com sucesso\n";
}

void Jogador::removerJogador(const std::string& apelido) {
    for (auto it = jogadores.begin(); it != jogadores.end(); ++it) {
        if (it->apelido == apelido) {
            jogadores.erase(it);
            std::cout << "Jogador " << apelido << " removido com sucesso\n";
            return;
        }
    }
    std::cout << "ERRO: jogador inexistente\n";
}

void Jogador::listarJogadores() {
    for (const auto& jogador : jogadores) {
        std::cout << jogador.apelido << " " << jogador.nome << "\n";
        std::cout << "REVERSI - V: " << jogador.vitoriasReversi << " D: " << jogador.derrotasReversi << "\n";
        std::cout << "LIG4 - V: " << jogador.vitoriasLig4 << " D: " << jogador.derrotasLig4 << "\n";
    }
}

void Jogador::salvarJogadores(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para escrita\n";
        return;
    }

    for (const auto& jogador : jogadores) {
        file << jogador.nome << "," << jogador.apelido << ","
             << jogador.vitoriasReversi << "," << jogador.derrotasReversi << ","
             << jogador.vitoriasLig4 << "," << jogador.derrotasLig4 << "\n";
    }

    file.close();
}

void Jogador::carregarJogadores(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo para leitura\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        Jogador jogador;

        std::getline(iss, jogador.nome, ',');
        std::getline(iss, jogador.apelido, ',');
        std::getline(iss, token, ',');
        jogador.vitoriasReversi = std::stoi(token);
        std::getline(iss, token, ',');
        jogador.derrotasReversi = std::stoi(token);
        std::getline(iss, token, ',');
        jogador.vitoriasLig4 = std::stoi(token);
        std::getline(iss, token, ',');
        jogador.derrotasLig4 = std::stoi(token);

        jogadores.push_back(jogador);
    }

    file.close();
}
