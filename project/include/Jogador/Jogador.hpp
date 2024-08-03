#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

class Jogador {
public:
    std::string nome;
    std::string apelido;
    int vitoriasReversi = 0;
    int derrotasReversi = 0;
    int vitoriasLig4 = 0;
    int derrotasLig4 = 0;
    
    void cadastrarJogador(const std::string& nome, const std::string& apelido);
    void removerJogador();
    void listarJogadores();
};

#endif // JOGADOR_HPP
