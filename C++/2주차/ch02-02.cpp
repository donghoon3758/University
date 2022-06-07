#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	//int number[100];
	int* pNumber = new int;
	int* pNumbers = new int[10];
	int* pAge = new int;
	/*
	cout << "Enter your dog's age: ";
	cin >> *pAge;

	cout << "Age: " << *pAge << " is located at " << pAge << endl;
	
	string name;
	cin >> name;
	cout << "Name: " << name << endl;

	int CHarsToAllocate = name.length() + 1;
	char* copyOfName = new char[CHarsToAllocate];
	strcpy_s(copyOfName, CHarsToAllocate, name.c_str());
	cout << "Copy of name: " << copyOfName << endl;
	*/
	int N = 10;
	int* pN = new int[N];
	int* pCopy = pN;

	for (int i = 0; i < N; i++) {
		*(pN + i) = i;
	}
	for (int i = 0; i < N; i++) {
		//cout << *(pN + i) << endl;
		//cout << *(pN++) << endl;
		cout << *(++pN) << endl;
	}
	
	int HoursInDay = 24;
	const int* pInteger = &HoursInDay;
	
	//*pInteger = 12;
	HoursInDay = 20;
	delete pNumber;
	delete[] pNumbers;
	//delete[] copyOfName;
	


	return 0;