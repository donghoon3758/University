#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class myString
{
private:
	char* Buffer;
public:
	myString() {

	}
	myString(const char* initialInput) {
		if (initialInput != NULL) {
			Buffer = new char[strlen(initialInput) + 1];
			strcpy_s(Buffer, strlen(initialInput) + 1,initialInput);
			cout << "Buffer Pointer: " << (unsigned int*)Buffer << endl;
		}
	}
	myString(const myString& copySource) {
		cout << "Copy constructor: copy from myString" << endl;
		if(copySource.Buffer != NULL){
			Buffer = new char[strlen(copySource.Buffer) + 1];
			strcpy_s(Buffer, strlen(copySource.Buffer) + 1, copySource.Buffer);
			cout << "copySource Buffer Pointer: " << (unsigned int*)Buffer << endl;
		}
	}
	~myString() {
		cout << "invoking destructor, clearing up" << endl;
		if (Buffer != NULL)
			delete[] Buffer;
	}
	int getLength() {
		return strlen(Buffer);
	}
	const char* getString() {
		return Buffer;
	}
};
void useMyString(myString input) {
	cout << "String buffer in myString is " << input.getLength();
	cout << "characters long " << endl;
	cout << "Buffer contains: " << input.getString() << endl;
	return;
}
int main()
{
	myString SayHello("Hello from String class");
	cout << SayHello.getLength() << endl;
	cout << SayHello.getString() << endl;
	useMyString(SayHello);

	return 0; //stack영역 return을 지워도 가능 ,exit도 가능
}