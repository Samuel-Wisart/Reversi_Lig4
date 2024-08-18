#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string arquivoJogadores = "../data/jogadores.csv";

Jogadores::Jogadores()
{
    try
    {
        carregarJogadores();
    }
    catch (const ArquivoNaoEncontrado &e)
    {
        criarArquivoJogadores();
    }
}

void Jogadores::criarArquivoJogadores()
{
    std::ofstream file(arquivoJogadores);
    if (!file.is_open())
    {
        std::cerr << "Erro ao criar arquivo\n";
        return;
    }

    file.close();
}

void Jogadores::cadastrarJogador(const std::string &nome, const std::string &apelido)
{
    for (const auto &jogador : jogadores)
    {
        if (jogador.getApelido() == apelido)
        {
            std::cout << "ERRO: jogador repetido\n";
            return;
        }
    }

    Jogador novoJogador(nome, apelido);
    jogadores.push_back(novoJogador);
}

void Jogadores::removerJogador(const std::string &apelido)
{
    for (auto it = jogadores.begin(); it != jogadores.end(); ++it)
    {
        if (it->getApelido() == apelido)
        {
            jogadores.erase(it);
            return;
        }
    }
    std::cout << "ERRO: jogador inexistente\n";
}

void Jogadores::listarJogadores()
{
    for (const auto &jogador : jogadores)
    {
        std::cout << jogador;
    }
}

void Jogadores::salvarJogadores()
{
    std::ofstream file(arquivoJogadores);
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir arquivo para escrita\n";
        return;
    }

    for (const auto &jogador : jogadores)
    {
        file << jogador.getNome() << "," << jogador.getApelido() << ","
             << jogador.getVitoriasReversi() << "," << jogador.getDerrotasReversi() << "," << jogador.getEmpatesReversi() << ","
             << jogador.getVitoriasLig4() << "," << jogador.getDerrotasLig4() << "," << jogador.getEmpatesLig4() << "\n";
    }

    file.close();
}

void Jogadores::carregarJogadores()
{
    std::ifstream file(arquivoJogadores);
    if (!file.is_open())
    {
        throw ArquivoNaoEncontrado();
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;

        std::string nome;
        std::string apelido;
        int vitoriasReversi;
        int derrotasReversi;
        int empatesReversi;
        int vitoriasLig4;
        int derrotasLig4;
        int empatesLig4;

        if (std::getline(iss, token, ','))
        {
            nome = token;
        }
        if (std::getline(iss, token, ','))
        {
            apelido = token;
        }
        if (std::getline(iss, token, ','))
        {
            vitoriasReversi = std::stoi(token);
        }
        if (std::getline(iss, token, ','))
        {
            derrotasReversi = std::stoi(token);
        }
        if (std::getline(iss, token, ','))
        {
            empatesReversi = std::stoi(token);
        }
        if (std::getline(iss, token, ','))
        {
            vitoriasLig4 = std::stoi(token);
        }
        if (std::getline(iss, token, ','))
        {
            derrotasLig4 = std::stoi(token);
        }
        if (std::getline(iss, token, ','))
        {
            empatesLig4 = std::stoi(token);
        }

        Jogador jogador(nome, apelido, vitoriasReversi, derrotasReversi, empatesReversi, vitoriasLig4, derrotasLig4, empatesLig4);

        jogadores.push_back(jogador);
    }

    file.close();
}

Jogador *Jogadores::buscarJogadorPorApelido(const std::string &apelido)
{
    for (auto &jogador : jogadores)
    {
        if (jogador.getApelido() == apelido)
        {
            return &jogador;
        }
    }
    return nullptr;
}

void Jogadores::imprimirJogadores()
{
    for (const auto &jogador : jogadores)
    {
        std::cout << jogador;
    }
}
