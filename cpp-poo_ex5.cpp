#include <iostream>
#include <string>

class Vehicle{
    protected:
        std::string brand;
        std::string model;
    public:
        Vehicle( std::string bn, std::string md):brand(bn), model(md){}
        virtual void showData() = 0;
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

void displayVehicleDetails(Vehicle* v){
    v->showData();
}

int main(){
    Car c1("Toyota", "Corolla", 4);
    Vehicle* c2 = new Car("Fiat", "Strada", 2);

    displayVehicleDetails(&c1);
    std::cout<<std::endl;
    displayVehicleDetails(c2);

    delete c2;
    return 0;  
}