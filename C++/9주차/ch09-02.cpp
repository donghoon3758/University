#include <iostream>

using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal Constructor" << endl;
    }
    int Age;
};
class Mammal : public virtual Animal
{
};


class Reptile : public virtual Animal
{
};

class Bird : public  virtual Animal
{
};

class Platypus : public Mammal, public Reptile, public Bird
{
};
int main()
{
    Platypus realFreak;

    return 0;
}

//multiple 상속은 좋지않다 base class의 constructor가 여러번 선언된다. virtual로 한번만 선언할 수 있다.
