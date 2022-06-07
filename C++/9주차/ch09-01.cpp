#include <iostream>

using namespace std;

class Fish {
public:
    Fish() {
        cout << "Constructed Fish" << endl;
    }
    virtual ~Fish() {
        cout << "Deconstructed Fish" << endl;//virtual 사용하지 않으면 Fish만 해제
    }

};

class Tuna : public Fish {
public:
    Tuna() {
        cout << "Constructed Tuna" << endl;
    }
    ~Tuna() {
        cout << "Deconstructed Tuna" << endl;
    }

};
void DeleteFishMemory(Fish* pFish) {
    delete pFish;
}

int main()
{
    cout << "Allocating a Tuna on the free store" << endl;
    Tuna* pTuna = new Tuna;
    DeleteFishMemory(pTuna);
    aTuna a;
    return 0;
}
