#include <iostream>

using namespace std;

int main()
{
	int age = 30;
	int* pInteger = &age;
	int** pp;
	int*** ppp;
	const double pi = 3.1416;

	pp = &pInteger;
	ppp = &pp;

	cout << "Age at: " << &age << endl;
	cout << "pInteger at: " << &pInteger<< endl;
	cout << "pInteger at: " << pInteger << endl;
	cout << "pp: " << pp << endl;
	cout << "ppp: " << ppp << endl;
	cout << "pInteger at: " << *pInteger << endl;
	cout << "pp: " << **pp << endl;
	cout << "ppp: " << ***ppp << endl;
	return 0;

}