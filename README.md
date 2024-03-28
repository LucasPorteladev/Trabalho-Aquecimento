# Trabalho de Aquecimento - Algoritmo e Estrutura de Dados

## Objetivo do Projeto

Este projeto tem como objetivo principal revisar os conceitos de manipulação de matrizes, controle de fluxo e lógica de jogo.

Neste jogo, teremos uma matriz contendo diversos elementos variando entre 0 ou 1:

* [0] - Células Mortas
* [1] - Células Vivas

Nosso objetivo é criar um código que seja capaz de interpretar qualquer matriz inserida pelo usuário e retornar o resultado do jogo seguindo as regras abaixo:

* Uma célula viva com menos de dois vizinhos morre (solidão).
* Uma célula viva com mais de três vizinhos morre (superpopulação).
* Uma célula viva com dois ou três vivos sobrevive.
* Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).

## Instruções do Projeto

* Crie uma matriz N x N para representar um tabuleiro.
* Inicialize a matriz com valores (0) ou 1.
* Implemente uma função para gerar um relatório de execução, salvando a evolução do jogo em um arquivo.
  
## Arquivos do Projeto

* main.cpp
* JogoDaVida.cpp
* JogoDaVida.hpp
* input.mps (Contém a matriz de entrada do usuário)
* geracoes.mps (Armazenará as matrizes de saída do programa)

# JogoDaVida.hpp

## Atributos

* linha: Salva o número de linhas da matriz inserida.
* coluna: Salva o número de colunas da matriz inserida.
* matriz_original: Salva a matriz inserida.
* matriz_copia: Armazenará as futuras gerações do projeto.
* geracoes: Salva o número de gerações que desejam ser criadas.
* num: Apenas uma variável auxiliar do código.

## Funções

JogoDaVida(): Construtor da classe

void leitura_arquivo(): Função responsável por passar a matriz do arquivo "input.mps" para o atributo matriz_original

int conta_vizinhos(): Função responsável por contar quantos "1" tem ao redor de um espaço específico da matriz.

void tratamento(): Função responsável por aplicar todas as regras do projeto para a criação da próxima geração.

void copia_matriz(): Função responsável por copiar a matriz_copia para a matriz_original.

void imprime_matriz(): Função responsável por imprimir a matriz gerada no arquivo "geracoes.mps".

void verifica_exterminio(): Função responsável por verificar se a matriz gerada contém apenas "0"; se sim, o código é finalizado.

void executar(): Função responsável por executar todas as funções necessárias para o funcionamento do código.

# JogoDaVida.cpp

void leitura_arquivo()
Começa sua execução abrindo o arquivo para leitura e descarta a primeira linha. Logo após, entra em um ciclo for passando todos os valores presentes no arquivo para a matriz_original.

void tratamento()
Começa sua execução declarando uma variável "vizinhos" que será importante. Logo após, entra em dois ciclos for e chama a função "conta_vizinhos". Após a função retornar um valor para a variável "vizinhos", temos 3 if's que têm como objetivo garantir o cumprimento das regras do trabalho.

int vizinhos()
Começa sua execução declarando uma variável "vizinhos", depois entra em dois ciclos for que têm como objetivo ver todos os vizinhos do espaço de matriz analisado e incrementar o contador a cada "1" encontrado.

void copia_matriz()
Começa sua execução entrando em dois ciclos for que têm como objetivo passar a matriz_copia para a matriz_original.

void imprime_matriz()
Começa sua execução abrindo o arquivo "geracoes.mps" para escrita, escreve qual a geração gerada e entra em dois ciclos for utilizados para escrever toda a matriz no arquivo.

void executar()
A função segue o seguinte fluxo de execução:

* Seta valores para atributos essenciais para o restante do código.
* Inicializa as matrizes.
* Abre o arquivo "input.mps" para leitura e passa o conteúdo do arquivo para a matriz.
* Abre o arquivo "geracoes.mps" para escrita e passa o conteúdo da matriz original para o arquivo.
* Entra em um loop for que será executado até todas as gerações serem criadas ou o jogo zerar completamente.
* Insere a matriz original para tratamento, ou seja, aplicação das regras para a criação da próxima geração.
* Copia a matriz_copia para a matriz_original.
* Abre o arquivo "geracoes.mps" e escreve a geração criada.
* Verifica se houve extermínio, caso haja, encerra o processo.
  
##                             Formatacao do Arquivo

Para o codigo funcionar e necessario que o arquivo "input.mps" siga uma formatacao padrao, exemplo abaixo:

![Captura de tela de 2024-03-27 13-15-32](https://github.com/LucasPorteladev/Trabalho-Aquecimento/assets/112915278/f078137b-cb98-4c32-a45c-31ff093c15c6)

#                           Resultados Esperados

## Matriz Inserida

![Captura de tela de 2024-03-28 14-50-45](https://github.com/LucasPorteladev/Trabalho-Aquecimento/assets/112915278/c4c02bf2-6e8d-4809-a1ee-9e5c0f5a823b)


## Resultado

![Captura de tela de 2024-03-28 14-50-26](https://github.com/LucasPorteladev/Trabalho-Aquecimento/assets/112915278/19f2f32d-22c5-42d7-a191-82254e21209d)


#                            Compilacao e Execucao

O código que simula o jogo: Jogo da Vida disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                      |                     
| -----------------------| ---------------------------- |
|  `make r`              | Compilar o codigo            |
