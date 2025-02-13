#include <iostream>
#include <string>

class Pessoa{
    private:
        std::string nome;
        int idade;
    public:
        Pessoa(std::string n, int i):nome(n), idade(i){}
        std::string getNome()const{
            return nome;
        }
        int getIdade()const{
            return idade;
        }
        void exibirDados()const{
            std::cout<<"Nome : "<<getNome()<<std::endl;
            std::cout<<"Idade: "<<getIdade()<<std::endl; 
        }
        void setDados(std::string n){
            nome = n;
        }
        void setDados(std::string n, int i){
            nome = n; idade = i;
        }
};
 
int main(){

    Pessoa p1("Jonas", 25);
    int option;

    while(true){
        std::cout<<"\nInsira a opção que deseja:\n";
        std::cout<<"( 1 | Exibir os Dados          )\n"
                 <<"( 2 | Fechar o Programa        )\n"
                 <<"( 3 | Alterar apenas o Nome    )\n"
                 <<"( 4 | Alterar o Nome e a Idade )\n"
                 <<"Resposta: ";

        if(!(std::cin>>option)){
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(1000, '\n'); // Ignora caracteres inválidos
            std::cout << "\nEntrada inválida! Digite um número.\n";
            continue;
        }
        
        std::cin.ignore();

        if(option == 1){
            std::cout<<"\n";
            p1.exibirDados();
        }else if(option == 2){
            break;
        }else if(option == 3){
            std::string novoNome;

            std::cout<<"\nDigite o novo nome: ";
            std::getline(std::cin, novoNome);
            p1.setDados(novoNome);
            std::cout<<"\nAgora o novo nome é "<<p1.getNome()<<std::endl;
        }else if(option == 4){
            std::string novoNome;
            int novaIdade;
            
            std::cout<<"\nDigite o novo nome: ";
            std::getline(std::cin, novoNome);
            std::cout<<"\nDigite a nova idade: ";
                while(!(std::cin>>novaIdade)){
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout<<"A idade deve ser um número!\nDigite a nova idade: ";
                }
            p1.setDados(novoNome, novaIdade);
            std::cout<<"Agora o novo nome é "<<p1.getNome()
                     <<" e a nova idade é "<<p1.getIdade()
                     <<std::endl;
        }else{
            std::cout<<"\nOpção inválida, tente novamente!\n";
        }
    }   
}