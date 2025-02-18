#include <iostream>
#include <string>

class Vehicle{
    protected:
        std::string brand;
        std::string model;
    public:
        Vehicle( std::string bn, std::string md):brand(bn), model(md){}
        virtual void showData() = 0;
        virtual ~Vehicle(){}
};

class Car:public Vehicle{
    private:
        int doorsNumber;
    public:
        Car(std::string bn, std::string md, int dn):Vehicle(bn, md), doorsNumber(dn){}
        void showData() override {
            std::cout<<"Marca.......: "<<brand<<std::endl
                     <<"Modelo......: "<<model<<std::endl;
            std::cout<<"Nº de Portas: "<<doorsNumber<<std::endl;
        }
};

class Eletronic{
    public:
        std::string B_brand; //Marca da bateria
        int memory;
        Eletronic(std::string ebn, int mr): B_brand(ebn), memory(mr){}
};

class EletricCar:public Vehicle, public Eletronic{
    private:
        int doorsNumber;
    public:
        EletricCar(std::string bn, std::string md, std::string ebn, int mr, int dn):
            Vehicle(bn, md), Eletronic(ebn, mr), doorsNumber(dn){}
        void showData() override {
            std::cout<<"Marca.......: "<<brand<<std::endl
                     <<"Modelo......: "<<model<<std::endl
                     <<"Nº de Portas: "<<doorsNumber<<std::endl
                     <<"Bateria.....: "<<B_brand<<std::endl
                     <<"Memória.....: "<<memory<<std::endl;
        }
};

void displayVehicleDetails(Vehicle* v){
    v->showData();
}

int main(){
    Car c1("Toyota", "Corolla", 4);
    Vehicle* c2 = new Car("Fiat", "Strada", 2);
    EletricCar c3("BYD", "Seal", "Qualcoon", 256, 2);

    displayVehicleDetails(&c1);
    std::cout << std::endl;
    displayVehicleDetails(c2);
    std::cout << std::endl;
    displayVehicleDetails(&c3);

    delete c2;
    return 0;  
}