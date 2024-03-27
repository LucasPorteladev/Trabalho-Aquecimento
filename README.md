#                        Trabalho de Aquecimento - Algoritmo e Estrutura de Dados

## Objetivo do Projeto

Este projeto tem como objetivo principal revisar os conceitos de manipulação de matrizes, controle
de fluxo e lógica de jogo.

Nesse jogo teremos uma matriz contendo diversos elemento variando entre 0 ou 1:

* 0 - Celulas Mortas
* 1 - Celulas Vivas

Nosso objetivo e criar um codigo que seja capaz de interpretar qualquer matriz inserida pelo usuario e retorna o resultado do jogo seguindo as regras abaixo:

* Uma celula viva com menos de dois vizinho morre (solidao).
* Uma celula viva com mais de tres vizinhos morre (superpopulacao).
* Uma celula viva com dois ou tres vivos sobrevive.
* Uma celula morta com exatamente tres vizinhos vivos se torna viva (reproducao).

## Instrucoes do Projeto

* Crie uma matriz N x N para representar um tabuleiro.
* Inicialize a matriz com valores (0) ou 1.
* Implemente uma funcao para gerar um relatorio de execucao, salvando a evolucao do jogo em um arquivo.

##                                       Arquivos do Projeto

* main.cpp
* JogoDaVida.cpp
* JogoDaVida.hpp
* input.mps (Contem a matriz de entrada do usuario)
* geracoes.mps (Armazenara as matrizes de saida do programa)

##                                     Conteudo das Classes

##                                        JogoDaVida.hpp

## Atributos

* linha: Salva o numero de linhas da matriz inserida.
* coluna: Salva o numero de colunas da matriz inserida.
* matriz_original: Salva a matriz inserida.
* matriz_copia: Armazenara as futuras geracoes do projeto.
* geracoes: Salva o numero de geracoes que desejam ser criadas.
* num: Apenas uma variavel auxiliar do codigo.

## Funcoes

JogoDaVida(): Construtor da classe

void leitura_arquivo(): Funcao responsavel por passar a matriz do arquivo "input.mps" para o atributo matriz_original

int conta_vizinhos(): Funcao responsavel por contar quantos "1" tem ao redor de um espaco especifico da matriz.

void tratamento(): Funcao responsavel por aplicar todas as regras do projeto para a criacao da proxima geracao

void copia_matriz(): Funcao responsavel por copiar a matriz_copia para a matriz_original

void imprime_matriz(): Funcao responsavel por imprimir a matriz gerada no arquivo "geracoes.mps"

void verifica_exterminio(): Funcao responsavel por verificar se a matriz gerada contem apenas "0", se sim, o codigo e finalizado

void executar(): Funcao responsavel por executar todas as funcoes necessarias para o funcionamento do codigo

##                                        JogoDaVida.cpp

## void leitura_arquivo()

Comeca sua execucao abrindo o arquivo para leitura e descarta a primeira linha, logo apos entra em um ciclo for passando todos os valores presentes no arquivo para a matriz_original.

## void tratamento()

Comeca sua execucao declarando uma variavel "vizinhos" que sera importante, logo apos entra em dois ciclos for e chama a funcao "conta_vizinhos". Apos a funcao retornar um valor para a variavel "vizinhos", temos 3 if`s que tem como objetivo garantir o cumprimento das regras do trabalho.

## int vizinhos()

Comeca sua execucao declarando uma variavel "vizinhos", depois entra em dois ciclos for que tem como objetivo ver todos os vizinhos do espaco de matriz analisado e incrementar o contador a cada "1" encontrado.

## void copia_matriz()

Comeca sua execucao entrando em um dois ciclos for que tem como objetivo, passar a matriz_copia para a matriz_original.

## void imprime_matriz()

Comeca sua execucao abrindo o arquivo "geracoes.mps" para escrita, escreve qual a geracao gerada e entra em dois ciclos for utilizados para escrever toda a matriz no arquivo.

## void executar()

A funcao segue o seguinte fluxo de execucao:

* Seta valores para atributos essenciais para o restante do codigo.
* Inicializa as matrizes
* Abre o arquivo "input.mps" para leitura e passa o conteudo do arquivo para a matriz.
* Abre o arquivo "geracoes.mps" para escrita e passa o conteudo da matriz original para o arquivo.
* Entra em um loop for que sera executado ate todas as geracoes serem criadas ou o jogo zerar completamente.
* Insere a matriz original para tratamento, ou seja, aplicacao das regras para a criacao da proxima geracao.
* Copia a matriz_copia para a matriz_original
* Abre o arquivo "geracoes.mps" e escreve a geracao criada.
* Verifica se houve exterminio, caso haja, encerra o processo.

##                             Formatacao do Arquivo

Para o codigo funcionar e necessario que o arquivo "input.mps" siga uma formatacao padrao, exemplo abaixo:

5 5 = Numero de linhas e colunas, respectivamente.
1 0 0 0 1
0 1 0 1 0
1 0 1 0 0
0 1 0 1 0
0 0 1 0 1

##                            Compilacao e Execucao

O código que simula o jogo: Jogo da Vida disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                      |                     
| -----------------------| ---------------------------- |
|  `make r`              | Compilar o codigo            |
