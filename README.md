# Jogo de Tabuleiro - Reversi e Lig4

Aluno: Samuel Lucca Viana Miranda
Matricula: 2022043566
Link: https://github.com/Samuel-Wisart/Reversi_Lig4/tree/main

Este projeto implementa dois jogos clássicos de tabuleiro: Reversi e Lig4. Ele foi desenvolvido em C++ utilizando uma arquitetura orientada a objetos, onde cada jogo é uma derivação de uma classe base `Tabuleiro`. Os jogadores podem disputar partidas em um tabuleiro virtual, e as estatísticas de vitória, derrota e empate são atualizadas automaticamente após cada jogo.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- **Casa:** Representa uma posição no tabuleiro, com coordenadas (x, y) e uma cor que indica o estado da casa.
- **Tabuleiro:** Classe abstrata que define a interface para os jogos de tabuleiro. Reversi e Lig4 herdam desta classe.
- **Reversi:** Implementa as regras e a lógica do jogo Reversi.
- **Lig4:** Implementa as regras e a lógica do jogo Lig4.
- **Jogador:** Armazena as informações e estatísticas de um jogador.
- **Partida:** Controla o fluxo de uma partida entre dois jogadores.

## Classes Principais

### `Casa`

Classe que representa uma casa no tabuleiro com as seguintes funcionalidades:
- **Coordenadas:** `getX()`, `getY()`
- **Cor da Casa:** `getCor()`, `setCor()`
- **Impressão da Posição:** `imprimirPosicao()`

### `Tabuleiro`

Classe abstrata que define as funções base para um tabuleiro:
- **Atributos:** Altura, largura, e uma matriz de casas.
- **Métodos Abstratos:** `fazerJogada()`, `testarJogada()`, `checarSeDaPraJogar()`, `testarCondicaoVitoria()`, `coletarJogada()`
- **Método de Impressão:** `imprimirTabuleiro()`

### `Reversi`

Classe derivada de `Tabuleiro` que implementa o jogo Reversi:
- **Implementa:** `fazerJogada()`, `testarJogada()`, `checarSeDaPraJogar()`, `testarCondicaoVitoria()`, `coletarJogada()`
- **Função Extra:** `selecionarPecasAlteradas()`

### `Lig4`

Classe derivada de `Tabuleiro` que implementa o jogo Lig4:
- **Implementa:** `fazerJogada()`, `testarJogada()`, `checarSeDaPraJogar()`, `testarCondicaoVitoria()`, `coletarJogada()`
- **Funções Extras:** `soltarPeca()`, `testarVitoriaPorLigacao()`

### `Jogador`

Classe que armazena as informações e estatísticas de um jogador:
- **Atributos:** Nome, apelido, estatísticas de vitórias, derrotas e empates em Reversi e Lig4.
- **Métodos de Incremento:** Para cada estatística.

### `Partida`

Classe que controla o fluxo de uma partida entre dois jogadores:
- **Execução da Partida:** `executarPartida()`
- **Atualização de Estatísticas:** `atualizarEstatisticas()`, `atualizarEstatisticasReversi()`, `atualizarEstatisticasLig4()`

## Como Usar

### Compilação

Compile o projeto utilizando o makefile com um compilador de c++ com a versao C++11 ou superior:

```bash
make
```

Para compilar e executar os testes use o comando:

```bash
make test
```