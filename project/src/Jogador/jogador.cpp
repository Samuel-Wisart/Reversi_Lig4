#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Jogador::Jogador(const std::string &nome, const std::string &apelido): nome(nome), apelido(apelido){};
Jogador::Jogador(const std::string &nome, const std::string &apelido, int vitoriasReversi, int derrotasReversi, int empatesReversi, int vitoriasLig4, int derrotasLig4, int empatesLig4) : nome(nome), apelido(apelido), vitoriasReversi(vitoriasReversi), derrotasReversi(derrotasReversi), empatesReversi(empatesReversi), vitoriasLig4(vitoriasLig4), derrotasLig4(derrotasLig4), empatesLig4(empatesLig4) {}

std::ostream& operator<<(std::ostream& os, const Jogador& jogador) {
    os << jogador.getApelido() << " " << jogador.getNome() << "\n"
    << "REVERSI - V: " << jogador.getVitoriasReversi() << " D: " << jogador.getDerrotasReversi() << " E: " << jogador.getEmpatesReversi() << "\n"
    << "LIG4 - V: " << jogador.getVitoriasLig4() << " D: " << jogador.getDerrotasLig4() << " E: " << jogador.getEmpatesLig4() << "\n";
    
    return os;
}

// Getters
std::string Jogador::getNome() const { return nome; }

std::string Jogador::getApelido() const { return apelido; }

int Jogador::getVitoriasReversi() const { return vitoriasReversi; }

int Jogador::getDerrotasReversi() const { return derrotasReversi; }

int Jogador::getEmpatesReversi() const { return empatesReversi; }

int Jogador::getVitoriasLig4() const { return vitoriasLig4; }

int Jogador::getDerrotasLig4() const { return derrotasLig4; }

int Jogador::getEmpatesLig4() const { return empatesLig4; }

// Incrementadores

void Jogador::incrementarVitoriasReversi() { vitoriasReversi++; }

void Jogador::incrementarDerrotasReversi() { derrotasReversi++; }

void Jogador::incrementarEmpatesReversi() { empatesReversi++; }

void Jogador::incrementarVitoriasLig4() { vitoriasLig4++; }

void Jogador::incrementarDerrotasLig4() { derrotasLig4++; }

void Jogador::incrementarEmpatesLig4() { empatesLig4++; }