#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>
#include <exception>


class Jogador
{
private:
    std::string nome;
    std::string apelido;
    int vitoriasReversi = 0;
    int derrotasReversi = 0;
    int empatesReversi = 0;
    int vitoriasLig4 = 0;
    int derrotasLig4 = 0;
    int empatesLig4 = 0;

public:
    Jogador(const std::string &nome, const std::string &apelido);
    Jogador(const std::string &nome, const std::string &apelido, int vitoriasReversi, int derrotasReversi, int empatesReversi, int vitoriasLig4, int derrotasLig4, int empatesLig4);

    // Get
    std::string getNome() const;
    std::string getApelido() const;
    int getVitoriasReversi() const;
    int getDerrotasReversi() const;
    int getEmpatesReversi() const;
    int getVitoriasLig4() const;
    int getDerrotasLig4() const;
    int getEmpatesLig4() const;

    // Incrementadores
    void incrementarVitoriasReversi();
    void incrementarDerrotasReversi();
    void incrementarEmpatesReversi();
    void incrementarVitoriasLig4();
    void incrementarDerrotasLig4();
    void incrementarEmpatesLig4();
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
    void criarArquivoJogadores();
    void imprimirJogadores();
};

std::ostream& operator<<(std::ostream& os, const Jogador& jogador);

class ArquivoNaoEncontrado : public std::exception {
public:
    const char* what() const noexcept override {
        return "O arquivo nao foi encontrado ou nao existe";
    }
};


#endif // JOGADOR_HPP
