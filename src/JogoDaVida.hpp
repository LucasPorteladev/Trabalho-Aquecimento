#ifndef JOGO_DA_VIDA_HPP
#define JOGO_DA_VIDA_HPP

class JogoDaVida {
private:
    int linha;
    int coluna;
    int** matriz_original;
    int** matriz_copia;
    int geracoes;
    int num = 1;

public:
    JogoDaVida(); // Construtor
    int** inicializa_matriz_original();
    int** inicializa_matriz_copia();
    
    // Métodos set para linha e coluna
    void setLinha();
    void setColuna();
    void setGeracoes();
    
    //Métodos da classe
    void leitura_arquivo();
    int conta_vizinhos(int pos_linha, int pos_coluna);
    void tratamento();
    void copia_matriz();
    void imprime_matriz_original();
    void imprime_matriz();
    void executar();
    void verifica_exterminio();
};

#endif // JOGO_DA_VIDA_HPP
