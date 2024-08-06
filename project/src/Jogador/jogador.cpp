#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Jogador::Jogador(const std::string &nome, const std::string &apelido): nome(nome), apelido(apelido){};
Jogador::Jogador(const std::string &nome, const std::string &apelido, int vitoriasReversi, int derrotasReversi, int vitoriasLig4, int derrotasLig4): nome(nome), apelido(apelido), vitoriasReversi(vitoriasReversi), derrotasReversi(derrotasReversi), vitoriasLig4(vitoriasLig4), derrotasLig4(derrotasLig4){};

std::ostream& operator<<(std::ostream& os, const Jogador& jogador) {
    os << jogador.getApelido() << " " << jogador.getNome() << "\n"
    << "REVERSI - V: " << jogador.getVitoriasReversi() << " D: " << jogador.getDerrotasReversi() << "\n"
    << "LIG4 - V: " << jogador.getVitoriasLig4() << " D: " << jogador.getDerrotasLig4() << "\n";
    
    return os;
}

// Getters
std::string Jogador::getNome() const {
    return nome;
}

std::string Jogador::getApelido() const {
    return apelido;
}

int Jogador::getVitoriasReversi() const {
    return vitoriasReversi;
}

int Jogador::getDerrotasReversi() const {
    return derrotasReversi;
}

int Jogador::getVitoriasLig4() const {
    return vitoriasLig4;
}

int Jogador::getDerrotasLig4() const {
    return derrotasLig4;
}

// Incrementadores
void Jogador::plusVitoriasReversi() {
    this->vitoriasReversi++;
}

void Jogador::plusDerrotasReversi() {
    this->derrotasReversi++;
}

void Jogador::plusVitoriasLig4() {
    this->vitoriasLig4++;
}

void Jogador::plusDerrotasLig4() {
    this->derrotasLig4++;
}