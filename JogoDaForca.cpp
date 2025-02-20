#include <iostream>
#include <string>
#include <vector>



void gamePlay(){

    //Inicialização de variáveis constantes
    std::string palavra;
    int i = 0;
    int tamanho;
    int vidas = 6;
    char palpite;
    std::vector<char> seguranca;

    //Escaneia a palavra secreta, salva seu tamanho 
    //e cria a resposta com 0 acertos
    std::cout<<"Escreva a palavra secreta: ";
    std::cin>>palavra;
    tamanho = palavra.size();
    std::vector<char> resposta(tamanho, '-');

     std::cout << "\033[2J\033[H";

    while(true){
        //std::cout << "\033[2J\033[H";

        //Imprime as condições atuais do jogo(Vidas e acertos)
        std::cout<<"Vidas restantes: "<<vidas<<std::endl;
        std::cout<<"Palavra Secreta: ";
            for (char c : resposta) {
            std::cout << c;
            }

        std::cout<<std::endl;
        
        //Escaneia o palpite do usuário
        std::cout<<"Dê o seu palpite: ";
        std::cin>>palpite;

        //Verifica se o palpite dado já foi digitado anteriormente
        //Se sim, reinicia a rodada. Se não, continua a rodada.
        bool jaFoiDigitado = false;
            for(char c : seguranca){
                if(c == palpite){
                    jaFoiDigitado = true;
                }
            }
            if(jaFoiDigitado){
                std::cout<<"Você já tentou essa letra antes!"<<std::endl;
                continue;
            }
        
        //Adiciona o palpite no vetor seguranca, que indica todos os
        //caracteres já digitados
        seguranca.push_back(palpite);

        //Verifica se o palpite é uma das lettras da palavra secreta.
        //Se for, adiciona esse palpite na resposta e indica o acerto
        bool acertou = false;
            for (int i = 0; i < tamanho; i++) {
                if (palpite == palavra[i]) {
                    resposta[i] = palavra[i];
                    acertou = true;
                }
            }

        //caso erre, diminui as vidas em 1
        if (acertou == false){
            vidas = vidas - 1;
        }
        
        //Verifica se as vidas acabaram. Se for o caso, finaliza o jogo.
        if(vidas == 0){
            std::cout<<"\nVocê perdeu!\n"
                     <<"A resposta era "<<palavra<<std::endl;
            break;
        }

        //converte a string 'palavra' em um vector e verifica se 
        //este vector é igual ao vector resposta.
        if (resposta == std::vector<char>(palavra.begin(), palavra.end())) {
            std::cout << "Palavra Secreta: ";
            for (char c : resposta) {
                std::cout << c;
            }
            std::cout << "\nVocê acertou!!!!\n" << std::endl;
            break;
        }
    }

    
}

int main(){

    int select=0;

    std::cout<<"_______________________________\n"
             <<"||                           ||\n"
             <<"||       JOGO DA FORCA       ||\n"
             <<"_______________________________\n\n"
             <<"( 1 | Iniciar jogo    )\n"
             <<"( 2 | Fechar programa )\n"<<std::endl;
    
    while(true){

        std::cout<<"Entre com a opção que deseja: ";

        if(!(std::cin>>select)){
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(1000, '\n'); // Ignora caracteres inválidos
            std::cout << "\nEntrada inválida! Digite um número.\n";
            continue;
        }
        if(select == 1){
            gamePlay();
            std::cout<<"( 1 | Jogar novamente )\n"
                     <<"( 2 | Fechar programa )\n"<<std::endl;
            continue;
        }else if(select == 2){
            break;
        }else{
            std::cout<<"\nEntrada inválida, tente novamente.\n"<<std::endl;
        }
    }
return 0;
}
