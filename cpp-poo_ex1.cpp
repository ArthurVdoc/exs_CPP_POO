#include <iostream>
#include <string>

class Pessoa{
    private:
        std::string nome;
        int idade;
    public:
        void setDados(std::string n, int i){
            nome = n;
            idade = i;
        } 
        void exibirDados();
};
    void Pessoa::exibirDados(){
        std::cout<<"Nome : "<<nome<<std::endl;
        std::cout<<"Idade: "<<idade<<std::endl;
    }

int main(){

    Pessoa p1;
    int option;

    p1.setDados("Jonathan", 21);

    while(1){
        std::cout<<"\nInsira a opção que deseja:\n";
        std::cout<<"( 1 | Exibir os dados )\n"
                 <<"( 2 | Fechar programa )\n"
                 <<"Resposta: ";

        if(!(std::cin>>option)){
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(1000, '\n'); // Ignora caracteres inválidos
            std::cout << "\nEntrada inválida! Digite um número.\n";
            continue;
        }
        if(option == 1){
            std::cout<<"\n";
            p1.exibirDados();
        }else if(option == 2){
            break;
        }else{
            std::cout<<"\nOpção inválida, tente novamente!\n";
            continue;
        }
    }   
}