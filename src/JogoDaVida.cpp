#include "JogoDaVida.hpp"
#include <fstream>
#include <iostream>

using namespace std;

JogoDaVida::JogoDaVida(){}

int** JogoDaVida::inicializa_matriz_original() {
    matriz_original = new int*[linha];
        
    for (int i = 0; i < linha; ++i) {
        matriz_original[i] = new int[coluna];
        
        for (int j = 0; j < coluna; ++j) {
            matriz_original[i][j] = 0;
        }
    }
    return matriz_original;
}

int** JogoDaVida::inicializa_matriz_copia() {
    matriz_copia = new int*[linha];
        
    for (int i = 0; i < linha; ++i) {
        matriz_copia[i] = new int[coluna];
        
        for (int j = 0; j < coluna; ++j) {
            matriz_copia[i][j] = 0;
        }
    }
    return matriz_copia;
}

void JogoDaVida::setLinha() {
    
    ifstream arquivo;

    arquivo.open("datasets/input.mps");
    
    int l;
    
    if(arquivo.is_open()){
        arquivo >> l;
    }
    
    linha = l;
    
    arquivo.close();
}

void JogoDaVida::setColuna(){
    
    ifstream arquivo;

    arquivo.open("datasets/input.mps");
    
    int c;
    
    if(arquivo.is_open()){
        arquivo >> c;
    }
    
    coluna = c;
    
    arquivo.close();
}

void JogoDaVida::setGeracoes(){
    
   int g;
   cout << "Quantas geracoes deseja gerar? " << endl;
   cin >> g;
   
   geracoes = g;
   
}


void JogoDaVida::leitura_arquivo(){
    
    ifstream arquivo;
    
    arquivo.open("datasets/input.mps");
    
    //Descarta a primeira linha do arquivo
    string a;
    getline(arquivo, a);
    
    if(arquivo.is_open()){
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
              arquivo >> matriz_original[i][j];
            }
        }
    }
    
    arquivo.close();
}

int JogoDaVida::conta_vizinhos(int pos_linha, int pos_coluna){

int vizinhos = 0;

for(int i = pos_linha - 1; i<= pos_linha + 1; i++){
    for(int j = pos_coluna - 1; j <= pos_coluna + 1; j++){
        if (i >= 0 && i < linha && j >= 0 && j < coluna && (i != pos_linha || j != pos_coluna)) {
            if (matriz_original[i][j] == 1) {
                vizinhos++;
            }
        }
    }
}

return vizinhos;

}

void JogoDaVida::tratamento(){
    
    int vizinhos;
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna ; j++){
            
            vizinhos = conta_vizinhos(i,j);
            
            if(matriz_original[i][j] == 1 && (vizinhos == 2 || vizinhos == 3)){
                matriz_copia[i][j] = 1;
             }
            else if(matriz_original[i][j] == 0 && vizinhos == 3){
                matriz_copia[i][j] = 1;
             }
            else{
             matriz_copia[i][j] = 0;
             }
        
        }
    }
}

void JogoDaVida::copia_matriz(){
  
  for(int i = 0; i < linha; i++){
    for(int j = 0; j  < coluna; j++){
        matriz_original[i][j] = matriz_copia[i][j];
    }
  }
}

void JogoDaVida::imprime_matriz_original(){
    
    ofstream resultado;
    
    resultado.open("datasets/geracoes.mps");
    resultado << "Matriz Original: " << endl;
    
     for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            resultado << matriz_original[i][j] << " ";
        }
        resultado << endl;
    }
    resultado << endl;
}

void JogoDaVida::imprime_matriz(){
    
    ofstream resultado;

    resultado.open("datasets/geracoes.mps", std::ios::app);
    resultado << "Geracao: "<< num << endl;
    num++;
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            resultado << matriz_copia[i][j] << " ";
        }
        resultado << endl;
    }
    resultado << endl;
    
    resultado.close();
}

void JogoDaVida::executar(){
    
   setGeracoes();
   setLinha();
   setColuna();
   
   inicializa_matriz_original();
   inicializa_matriz_copia();
   leitura_arquivo();
   
   imprime_matriz_original();
   
   for (int i = 0; i < geracoes; i++){
       cout <<"Criando Geracao " << i + 1 << endl;
        tratamento();
        copia_matriz();
        imprime_matriz();
        verifica_exterminio();
   }
}

void JogoDaVida::verifica_exterminio(){
    
    int contador = 0;
    
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (matriz_original[i][j] == 0){
                contador++;
            }
        }
    }
    
    if (contador == linha * coluna){
        cout << "A Humanidade foi Exterminada!" << endl;
        exit(0);
    }
}

