#include <iostream>
#include <string>

using namespace std;

class monsterDB {
private:
    ~monsterDB() {};
public:
    static void DestroyInstance(monsterDB* pInstance) {
        delete pInstance;
    }
};

int main()
{
    monsterDB* myDatabase = new monsterDB();
    monsterDB::DestroyInstance(myDatabase);
 
    return 0;
}
