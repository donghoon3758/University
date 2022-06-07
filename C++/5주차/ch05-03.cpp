#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class myString
{
public:
	string Buffer;
public:
	myString() {

	}
	myString(const char* initialInput) {
		cout << "Constructor myString" << endl;
		cout << "Buffer Pointer: " << (void*)&Buffer << endl;
		Buffer = initialInput;

	}

	~myString() {
		cout << "invoking destructor, clearing up" << endl;

	}
};
	void useMyString(myString input) {
		cout << "String buffer in myString is " << input.Buffer.length();
		cout << "characters long " << endl;
		cout << "Buffer contains: " << input.Buffer.c_str() << endl;
		cout << "useMyString Buffer Pointer: " << (void*)&input.Buffer << endl;
		return;
	}
int main()
{
	myString SayHello("Hello from String class");
	useMyString(SayHello);
	
	return 0; //stack영역 return을 지워도 가능 ,exit도 가능
}
