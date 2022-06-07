#include <iostream>

using namespace std;

class A {
public:
    void fooA() {
        cout << "fooA()" << endl;
     }
};

class AA : public A {
public:
    void fooAA() {
        cout << "fooAA()" << endl;
    }
};

int main()
{

    AA myAA;
    A myA = myAA;//주소는 AA를 가지지만 TYPE은 A

    myA.fooA();
  //  myA.fooAA();//A클래스에 존재하지 않는 method

    return 0;
}