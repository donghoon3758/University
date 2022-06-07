#include <iostream>
#include <string>

using namespace std;

class fish {
protected:
    bool freshWaterFish;
public:
    fish(){}
    fish(bool isFreshWater) : freshWaterFish(isFreshWater) {};
    void swim() {
        if (freshWaterFish)
            cout << "Swims in lake" << endl;
        else
            cout << "Swims in sea" << endl;
    }
};
class tuna : public fish {
public:
    tuna() : fish(false) {}
    void swim() {
        cout << "Tuna swims real fast" << endl;
        fish::swim();
    }

};
class carp : public fish {
public:
    carp() {
        freshWaterFish = true;
    }
    void swim() {
        cout << "Carp swims real slow" << endl;
    }
};
int main()
{
    carp myLunch;
    tuna myDinner;

    myLunch.swim();
    myDinner.swim();
    myDinner.fish::swim();
    return 0;
}
