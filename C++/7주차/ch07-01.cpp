#include <iostream>

using namespace std;

class Motor {
public:
    void SwitchIgnition() {
        cout << "Ignition ON" << endl;
    }
    void PumpFuel() {
        cout << "Fuel in cylinders" << endl;
    }
    void FireCylinders() {
        cout << "Vroom" << endl;
    }
};
/*
class Car : private Motor {//Car class안에서만 접근 가능
public:
    void Move() {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};*/
class Car : protected Motor {//Car class안에서만 접근 가능
public:
    void Move() {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};
class SuperCar : protected Car {//Car class안에서만 접근 가능
public:
    void Move() {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
        FireCylinders();
        FireCylinders();
    }
};

int main()
{
    SuperCar myDreanCar;
    myDreanCar.Move();

    return 0;
}