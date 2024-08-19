#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <vector>
#include <exception>
#include <filesystem> 

/**
 * @brief Classe que representa um jogador.
 * 
 * Armazena o nome, apelido e as estatísticas de vitórias, derrotas e empates nos jogos Reversi e Lig4.
 */
class Jogador
{
private:
    std::string nome;          ///< Nome do jogador.
    std::string apelido;       ///< Apelido do jogador.
    int vitoriasReversi = 0;   ///< Número de vitórias no jogo Reversi.
    int derrotasReversi = 0;   ///< Número de derrotas no jogo Reversi.
    int empatesReversi = 0;    ///< Número de empates no jogo Reversi.
    int vitoriasLig4 = 0;      ///< Número de vitórias no jogo Lig4.
    int derrotasLig4 = 0;      ///< Número de derrotas no jogo Lig4.
    int empatesLig4 = 0;       ///< Número de empates no jogo Lig4.

public:
    /**
     * @brief Construtor da classe Jogador.
     * 
     * Inicializa um jogador com nome e apelido.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     */
    Jogador(const std::string &nome, const std::string &apelido);

    /**
     * @brief Construtor da classe Jogador com estatísticas.
     * 
     * Inicializa um jogador com nome, apelido, e suas estatísticas de vitórias, derrotas e empates em dois jogos (Reversi e Lig4).
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     * @param vitoriasReversi Número de vitórias no jogo Reversi.
     * @param derrotasReversi Número de derrotas no jogo Reversi.
     * @param empatesReversi Número de empates no jogo Reversi.
     * @param vitoriasLig4 Número de vitórias no jogo Lig4.
     * @param derrotasLig4 Número de derrotas no jogo Lig4.
     * @param empatesLig4 Número de empates no jogo Lig4.
     */
    Jogador(const std::string &nome, const std::string &apelido, int vitoriasReversi, int derrotasReversi, int empatesReversi, int vitoriasLig4, int derrotasLig4, int empatesLig4);

    // Getters (sem comentários)

    std::string getNome() const;
    std::string getApelido() const;
    int getVitoriasReversi() const;
    int getDerrotasReversi() const;
    int getEmpatesReversi() const;
    int getVitoriasLig4() const;
    int getDerrotasLig4() const;
    int getEmpatesLig4() const;

    // Incrementadores

    /**
     * @brief Incrementa o número de vitórias do jogador no jogo Reversi.
     */
    void incrementarVitoriasReversi();

    /**
     * @brief Incrementa o número de derrotas do jogador no jogo Reversi.
     */
    void incrementarDerrotasReversi();

    /**
     * @brief Incrementa o número de empates do jogador no jogo Reversi.
     */
    void incrementarEmpatesReversi();

    /**
     * @brief Incrementa o número de vitórias do jogador no jogo Lig4.
     */
    void incrementarVitoriasLig4();

    /**
     * @brief Incrementa o número de derrotas do jogador no jogo Lig4.
     */
    void incrementarDerrotasLig4();

    /**
     * @brief Incrementa o número de empates do jogador no jogo Lig4.
     */
    void incrementarEmpatesLig4();
};

/**
 * @brief Classe que gerencia uma coleção de jogadores.
 */
class Jogadores
{
private:
    std::vector<Jogador> jogadores; ///< Vetor que armazena os jogadores cadastrados.

public:
    /**
     * @brief Construtor da classe Jogadores.
     * 
     * Inicializa a coleção de jogadores e carrega os dados dos jogadores a partir do arquivo.
     */
    Jogadores();

    /**
     * @brief Cadastra um novo jogador.
     * 
     * @param nome Nome do jogador.
     * @param apelido Apelido do jogador.
     */
    void cadastrarJogador(const std::string &nome, const std::string &apelido);

    /**
     * @brief Remove um jogador da coleção.
     * 
     * @param apelido Apelido do jogador a ser removido.
     */
    void removerJogador(const std::string &apelido);

    /**
     * @brief Lista todos os jogadores cadastrados.
     */
    void listarJogadores();

    /**
     * @brief Salva os dados dos jogadores em um arquivo.
     */
    void salvarJogadores();

    /**
     * @brief Carrega os dados dos jogadores a partir de um arquivo.
     */
    void carregarJogadores();

    /**
     * @brief Cria o arquivo de jogadores, se ainda não existir.
     */
    void criarArquivoJogadores();

    /**
     * @brief Imprime os dados dos jogadores cadastrados.
     */
    void imprimirJogadores();

    /**
     * @brief Busca um jogador pelo apelido.
     * 
     * @param apelido Apelido do jogador.
     * @return Jogador* Ponteiro para o jogador encontrado, ou nullptr se não encontrado.
     */
    Jogador* buscarJogadorPorApelido(const std::string &apelido);
};

/**
 * @brief Sobrecarga do operador de inserção em fluxo para a classe Jogador.
 * 
 * Exibe as informações do jogador no fluxo de saída.
 * 
 * @param os Fluxo de saída onde as informações serão escritas.
 * @param jogador Referência ao objeto Jogador cujas informações serão exibidas.
 * @return std::ostream& Referência ao fluxo de saída modificado.
 */
std::ostream& operator<<(std::ostream& os, const Jogador& jogador);

/**
 * @brief Exceção lançada quando o arquivo de jogadores não é encontrado.
 */
class ArquivoNaoEncontrado : public std::exception {
public:
    /**
     * @brief Retorna uma mensagem de erro descrevendo a exceção.
     * @return const char* Mensagem de erro.
     */
    const char* what() const noexcept override {
        return "O arquivo nao foi encontrado ou nao existe";
    }
};

#endif // JOGADOR_HPP
