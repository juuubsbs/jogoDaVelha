#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>

void comoJogar(){

    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std:: cout << "   Bem vind@ ao jogo da velha! O objetivo do jogo é completar uma sequência de três \n";
    std:: cout << "caracteres com a sua letra, caso você seja o Jogador 1 (primeiro a começar) sua letra \n";
    std:: cout << "será 'X', senão, sua letra será 'O'. A cada vez você irá digitar a linha e a coluna onde você \n";
    std:: cout << "deseja posicionar sua letra.\n";

    std:: cout << "   Sua sequência de caracteres pode ser na diagonal principal, secundária, uma linha completa ou \n";
    std:: cout << "ou uma coluna completa.\n";

    std:: cout << "   O primeiro jogador que completar vence o jogo! Caso sejam realizadas 9 (nove) jogadas \n";
    std:: cout << "o jogo irá dar a mensagem 'Vixe, deu velha' e será encerrado. Tenha um bom jogo! \n";
    std:: cout << "               pressione enter para coninuar...";
    std:: cin.ignore();
    std:: cin.get();

};

void cores(){

    std:: cout << "   Neste jogo utilizamos o cógigo ANSI para representar as cores dos jogadores e das mensagens \n";
    std:: cout << "de erro, caso esteja interessad@, o nome do arquivo é ANSIcolors.md .\n";
    std:: cout << "               pressione enter para continuar...";
    std:: cin.ignore();
    std:: cin.get();
}


bool menuRodando = true;
void menu(){
    while(menuRodando == true ){

        system("cls");

        std:: cout << " \n\n .--------..-----..-----..--.--. \n";
             std:: cout << " |        ||  -__||     ||  |  | \n";
             std:: cout << " |__|__|__||_____||__|__||_____| \n\n\n";

        std:: cout << "     1- Como Jogar?\n";
        std:: cout << "     2- Sobre as cores...\n";
        std:: cout << "     3- Jogar!\n";
        std:: cout << "     0- Sair\n";
        std:: cout << "digite aqui: ";
        std:: string x; std:: cin >> x;

        int numero;

        numero = x[0] - 48;

        switch (numero)
        {
        case 1:
                comoJogar();
            break;
        
        case 2:
                cores();
            break;
                
            case 3:
            menuRodando = false;
            break;

            case 0:
            std:: cout << "Você está saindo do jogo...";
            exit(0);
            break;

        default:
        std:: cout << "\e[0;31mOpção inválida, pressione enter para continuar...\e[0m";
        std:: cin.ignore();
        std:: cin.get();
        menuRodando = true;
            break;
        }

        system("cls");
    }
}