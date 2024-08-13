#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Tabuleiro.hpp"
#include <vector>
#include <utility>
#include <string>

class Reversi : public Tabuleiro {
public:
    Reversi(int altura, int largura);
    virtual ~Reversi();

    void fazerJogada(char time, int x, int y) override;
    std::string testarJogada(char time, int x, int y) override;
    char testarCondicaoVitoria(char time) override;

private:
    std::vector<std::pair<int, int>> selecionarPecasAlteradas(char time, int x, int y);
    std::vector<std::pair<int, int>> selecionarPecasAlteradas(char time, int x, int y, void (direcionador)(int&, int&));

};

bool mudarCor(Casa *casa);

template <typename V>
std::vector<V>& operator+=(std::vector<V>& vec1, const std::vector<V>& vec2) {
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    return vec1;
}

#endif // REVERSI_HPP
