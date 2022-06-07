#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Human
{
public:
	//Human();
	
	//Human() {//constructor

	//}
	Human(string HumanName="None") : name(HumanName) {
		//name = HumanName;
	}
	~Human() {
		cout << "bye" << endl;
	}
public:
	string name;
	//void introduceSelf();
	
	void introduceSelf() {
		cout << "haha" << endl;
	};
};
/*
Human::Human() {

}
void Human::introduceSelf() {
	cout << "haha" << endl;
}*/
class myString
{
private:
	char* Buffer;
public:
	myString(const char* initialInput) {
		if (initialInput != NULL) {
			Buffer = new char[strlen(initialInput) + 1];
			strcpy_s(Buffer, strlen(initialInput) + 1,initialInput);
		}
	}
	~myString() {
		cout << "invoking destructor, clearing up" << endl;
		if (Buffer != NULL)
			delete[] Buffer;
	}
};
int main()
{
	myString SayHello("Hello from String class");
	Human Tom; //stack 생성
	cout << Tom.name << endl;
	Human Jane("Jane"); //stack 생성
	cout << Jane.name << endl;
	Tom.name = "Tom";//직접 acess
	Tom.introduceSelf();
	Human* pTom = new Human();//동적할당 (포인터) heap 생성
	//(*pTom).name = "Tom";//간접 acess
	pTom->name = "Tom";
	pTom->introduceSelf();;

	delete pTom; // heap 영역

	return 0; //stack영역
}