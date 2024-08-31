#include <iostream>
#include <string>
#include <locale.h>
#include "menu.hpp"

int main()
{

/*  talvez colocar tempo?
    adicionar padding para centralizar*/ 

    // .-.   .-..----. .-.    .-. .-.   .--.
    //  \ \_/ / } |__} } |    { {_} |  / {} \
    //   \   /  } '__} } '--. | { } } /  /\  \
    //    `-'   `----' `----' `-' `-' `-'  `-'

    // configurando a localização para aceitar acentos e demais caracteres especiais
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    //menu
    menu();


    // função de criação da tabela.
    char matrizTaboleiro[3][3]; 
    int contadorLinha, contadorColuna;
    for (contadorLinha = 0; contadorLinha < 3; contadorLinha++){
        for( contadorColuna = 0; contadorColuna < 3; contadorColuna++){
            matrizTaboleiro[contadorLinha][contadorColuna] = {'-'};
            std:: cout << matrizTaboleiro[contadorLinha][contadorColuna] << " ";
        }
        std:: cout << "\n";
    }


//início do jogo
int i, j, jogadas = 0;
char simbolo; 
std:: string jogador, iString, jString; 

//início da função jogo rodando, vira 'false' somente quando o jogador vence
bool jogoRodando = true;
do{
    //troca de jogadores
    if ( jogadas % 2 == 0){
        jogador = "\e[0;35mJogador 1\e[0m";
        simbolo = 'X';
    }
    else{
        jogador = "\e[0;32mJogador 2\e[0m"; 
        simbolo = 'O';
    }

    //loop para erros de inserção
    bool jogadaInvalida = true;
    while ( jogadaInvalida == true){
        std:: cout << "Digite a coordenada da linha, " << jogador << ": ";
        std:: cin >> iString;
        std:: cout << "Digite a coordenada da coluna, " << jogador << ": ";
        std:: cin >> jString;

        i = iString[0] - 48 ;
        j = jString [0] - 48 ;

        //ERROS:
        //fora da matriz
        if (iString.size() != 1 || jString.size() != 1){
            jogadaInvalida = true;
        }
        else if ( i > 3 || j > 3 || i < 1 || j < 1){
            jogadaInvalida = true;
        }

        //reinscrição 
        else if ( matrizTaboleiro[i-1][j-1] == 'X' || matrizTaboleiro[i-1][j-1] == 'O'){
            jogadaInvalida = true;
            std:: cout << "Este espaço já foi tomado!\n";
        }

        //sai do loop caso nenhum erro seja encontrado
        else jogadaInvalida = false;

        //mensagem de erro
        if (jogadaInvalida == true){
            std:: cout << "    \e[0;31mJogada Inválida! Tente Novamente...\e[0m" << std:: endl;
        }
    }
    
    //após verificação, adiciona uma nova jogada
    jogadas++;
  
   for (contadorLinha = 0; contadorLinha < 3; contadorLinha++){
        for( contadorColuna = 0; contadorColuna < 3; contadorColuna++){
            if (contadorLinha + 1 == i && contadorColuna + 1 == j){
               matrizTaboleiro[contadorLinha][contadorColuna] = simbolo;
               std:: cout << matrizTaboleiro[contadorLinha][contadorColuna] << " ";
            }
            else{
                std:: cout << matrizTaboleiro[contadorLinha][contadorColuna] << " ";
            }  
        }
        std:: cout << "\n";
    }
  

    //CONDIÇÕES PARA GANHAR:
    //diagonal principal
    if ( matrizTaboleiro[0][0] == simbolo && matrizTaboleiro[1][1] == simbolo && matrizTaboleiro[2][2] == simbolo ){
        jogoRodando = false;
    }
    //diagonal secundária
    if ( matrizTaboleiro[0][2] == simbolo && matrizTaboleiro[1][1] == simbolo && matrizTaboleiro[2][0] == simbolo ){
            jogoRodando = false;
    }
    //linhas iguais ou colunas iguais
    for ( int linha = 0, coluna = 0; linha <= 3; linha ++, coluna++){
            if ( matrizTaboleiro [linha][0] == simbolo && matrizTaboleiro [linha][1] == simbolo && matrizTaboleiro [linha][2] == simbolo ){
                jogoRodando = false;
            }
            if ( matrizTaboleiro [0][coluna] == simbolo && matrizTaboleiro [1][coluna] == simbolo && matrizTaboleiro [2][coluna] == simbolo){
                jogoRodando = false;  
            }
    }

    //PARAR O JOGO
    //velha (todas as casas ocupadas)
    if (jogadas == 9 && jogoRodando == true){
        std:: cout << "\e[0;33mVixe, deu velha, tente novamente :).\e[0m";
        jogoRodando = false;
    }
}
while( jogoRodando == true);

if ( jogadas < 9){
    std:: cout << "Você venceu, " << jogador << "!" << std::endl;
    std:: cout << "O número total de jogadas foi: " << jogadas;
}



    return 0;
}