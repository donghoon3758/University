#include <iostream>
#include <string>

using namespace std;

class human {
public:
    human(string inputName = "Tom", int inputAge=25) {
        name = inputName;
        age = inputAge;
    }
    void setAge(int humanAge) {
        this->age = humanAge;
    }
private:
    string name;
    int age;
    friend void displayAge(const human& person);
};
void displayAge(const human& person) {
    cout << person.age << endl;
    cout << person.name << endl;
}
int main()
{
    human Tom("Jane",20);
    displayAge(Tom);
   // Tom.setAge(20);
   // cout << Tom.age << endl;
 
    return 0;
}