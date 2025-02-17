#include <iostream>
#include <string>

class Vehicle{
    protected:
        std::string brand;
        std::string model;
    public:
        Vehicle( std::string bn, std::string md):brand(bn), model(md){}
        void showData()const{
            std::cout<<"Marca.......: "<<brand<<std::endl
                     <<"Modelo......: "<<model<<std::endl;
        }
};

class Car:public Vehicle{
    private:
        int doorsNumber;
    public:
        Car(std::string bn, std::string md, int dn):Vehicle(bn, md), doorsNumber(dn){}
        void showData()const{
            Vehicle::showData();
            std::cout<<"Nº de Portas: "<<doorsNumber<<std::endl;
        }
};

int main(){
    Car c1("Toyota", "Corolla", 4);
    Car c2("Fiat", "Strada", 2);
    Car c3("BYD", "Dolphin", 4);

    c1.showData();
    std::cout<<std::endl;
    c2.showData();
    std::cout<<std::endl;
    c3.showData();
}