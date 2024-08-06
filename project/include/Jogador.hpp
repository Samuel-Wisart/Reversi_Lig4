#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>


class Jogador
{
private:
    std::string nome;
    std::string apelido;
    int vitoriasReversi = 0;
    int derrotasReversi = 0;
    int vitoriasLig4 = 0;
    int derrotasLig4 = 0;

public:
    Jogador(const std::string &nome, const std::string &apelido);
    Jogador(const std::string &nome, const std::string &apelido, int vitoriasReversi, int derrotasReversi, int vitoriasLig4, int derrotasLig4);

    // Get
    std::string getNome() const;
    std::string getApelido() const;
    int getVitoriasReversi() const;
    int getDerrotasReversi() const;
    int getVitoriasLig4() const;
    int getDerrotasLig4() const;

    // Incrementadores
    void plusVitoriasReversi();
    void plusDerrotasReversi();
    void plusVitoriasLig4();
    void plusDerrotasLig4();
};

class Jogadores
{
private:
    std::vector<Jogador> jogadores;

public:
    Jogadores();
    void cadastrarJogador(const std::string &nome, const std::string &apelido);
    void removerJogador(const std::string &apelido);
    void listarJogadores();
    void salvarJogadores();
    void carregarJogadores();
};

std::ostream& operator<<(std::ostream& os, const Jogador& jogador);

#endif // JOGADOR_HPP
