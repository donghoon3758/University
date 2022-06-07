include <iostream>
#include <string>

using namespace std;

class President {
private:
    President() {};
    President(const President&);
    const President& operator= (const President&);
    string name;
public:
    static President& getInstance() {
        static President onlyInstance;

        return onlyInstance;
    }
    string getName() {
        return name;
    }
    void setName(string inputName) {
        name = inputName;
    }
};

void DoSomething(President clone) {
    cout << "I am a clone" << endl;
}

int main()
{
    President& onlyPresident = President::getInstance();
    onlyPresident.setName("Abraham Lincoln");

    cout << "The name of the president is: ";
    cout << onlyPresident.getName() << endl; 
    cout << President::getInstance().getName() << endl;
    //President OurPresident;
    //DoSomething(OurPresident);
   // President clone;
   // clone = OurPresident;

    return 0;
}