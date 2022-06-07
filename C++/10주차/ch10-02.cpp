#include <iostream>

using namespace std;

class A {
public:
    int i;
public:
    A() {
    }
    A(int i) {
        this->i = i;
    }
    void Display() {
        cout << "this address : " << this << endl;
    }
    A* returnA() {
        return this;
    }
    int getI() {
        return i;
    }
    A& returnThis() {
        return *this;
    }
    /*
    A returnThis() {
        return this; // this 는 포인터 타입이라서 에러 발생
    }*/
};

int main()
{
    A a;
    a.Display();
    A& refThis = a.returnThis();
    refThis.Display();


    /*
    A myA;
    cout << "myA address : " << &myA << endl;
    myA.Display();
    cout << "returnA(): "<< myA.returnA() << endl;
    A myA2(3);
    cout << myA2.getI() << endl;

    int num = 111;
    int* pNum = &num;
    int &refp = *pNum;//&타입일때는 값을 넘겨줘야한다.
    int* (&refp2) = pNum;///*일때는 주소값을 넘겨줘야한다.
    cout << "pNum's address: " << pNum << endl;
    cout << "refp's address: " << &refp << endl;
    cout << "refp's value: " << refp << endl;
    cout << "refp2's address: " << &refp2 << endl;//pNum의 주소와 같다.
    cout << "pNum's address: " << &pNum << endl;//
    cout << "refp2's address: " << refp2 << endl;
    cout << "refp's value: " << *refp2 << endl;
    */


    return 0;
}
