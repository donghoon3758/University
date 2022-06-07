#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class myString
{
private:
	char* Buffer=NULL;
public:
	myString() {

	}
	myString(const char* initialInput) {
		if (initialInput != NULL) {
			Buffer = new char[strlen(initialInput) + 1];
			if (Buffer != NULL) {
				strcpy_s(Buffer, strlen(initialInput) + 1, initialInput);
				cout << "Buffer Pointer: " << (unsigned int*)Buffer << endl;
			}
			else
				Buffer = NULL;
		}
		else
			Buffer = NULL;
	}
	myString(const myString& copySource) {
		cout << "Copy constructor: copy from myString" << endl;
		if (copySource.Buffer != NULL) {
			Buffer = new char[strlen(copySource.Buffer) + 1];
			strcpy_s(Buffer, strlen(copySource.Buffer) + 1, copySource.Buffer);
			cout << "copySource Buffer Pointer: " << (unsigned int*)Buffer << endl;
		}
		else
			Buffer = NULL;
	}
	myString& operator = (const myString& CopySource) {
		cout << " Copy assignment is called" << endl;
		if ((this != &CopySource )&&(CopySource.Buffer != NULL)) {
			if (Buffer != NULL) {
				delete[] Buffer;
			}
			Buffer = new char[strlen(CopySource.Buffer) + 1];
			strcpy_s(Buffer, strlen(CopySource.Buffer) + 1, CopySource.Buffer);
		}
		else
			Buffer = NULL;
		return (*this);
	}
	const char& operator [] (int index) const {
		if (index < getLength()) {
			return Buffer[index];
		}
		else
			return ' ';
	}
	~myString() {
		cout << "invoking destructor, clearing up" << endl;
		if (Buffer != NULL)
			delete[] Buffer;
	}
	int getLength() const{
		return strlen(Buffer);
	}
	const char* getString() {
		return Buffer;
	}
	operator const char* () {
		return Buffer;
	}
};

int main()
{
	myString String1("Hello");
	myString String2("World");
	
	String2 = String1; //compiler가 자동으로 =해주면 error발생 shallow copy로 같은 주소공간을 가리키고 delete할 때 한번 delete한 공간을 다시 delete해서 문제 발생.

	cout << String1 << endl;
	cout << String2 << endl;
	String1 = "aaa"; //compiler가 자동으로 =해주면 error발생 shallow copy로 같은 주소공간을 가리키고 delete할 때 한번 delete한 공간을 다시 delete해서 문제 발생.

	cout << String1 << endl;
	cout << String2 << endl;

	for (int i = 0; i < String1.getLength(); i++) {
		cout << String1[i] << ' ';
	}
	cout << endl;
	
	return 0; //stack영역 return을 지워도 가능 ,exit도 가능
}