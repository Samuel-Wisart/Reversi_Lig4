#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>

class Jogador {
public:
    std::string nome;
    std::string apelido;
    int vitoriasReversi = 0;
    int derrotasReversi = 0;
    int vitoriasLig4 = 0;
    int derrotasLig4 = 0;
    
    void cadastrarJogador(const std::string& nome, const std::string& apelido);
    void removerJogador(const std::string& apelido);
    void listarJogadores();
    void salvarJogadores(const std::string& filename);
    void carregarJogadores(const std::string& filename);

private:
    std::vector<Jogador> jogadores;
};

#endif // JOGADOR_HPP
