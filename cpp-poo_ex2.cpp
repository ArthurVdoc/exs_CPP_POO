#include <iostream>
#include <string>

class Pessoa{
    private:
        std::string nome;
        int idade;
    public:
        Pessoa(std::string n, int i):nome(n), idade(i){}
        std::string getNome(){
            return nome;
        }
        int getIdade(){
            return idade;
        }
        void exibirDados();
};
    void Pessoa::exibirDados(){
        std::cout<<"Nome : "<<getNome()<<std::endl;
        std::cout<<"Idade: "<<getIdade()<<std::endl;
    }


int main(){

    Pessoa p1("Jonas", 25);
    int option;

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