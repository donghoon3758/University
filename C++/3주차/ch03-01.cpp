#include <iostream>

using namespace std;
/*
void foo(char *a) {

}*/
/*
void foo(char a[10]) {

}*/
void foo(char a[],int length) {

}
void CalcArea(const double* const ppi,const double* const pRadius, double* const parea) {
	if (ppi && pRadius && parea) {
		*parea = (*ppi) * (*pRadius) * (*pRadius);
	}
}
int main()
{
	int DaysInMonth = 30;
	int* const pDayInMonth = &DaysInMonth;
	*pDayInMonth = 31;
	int DaysInLunarMonth = 28;
	//pDaysInMonth = &DaysInLunarMonth; //위에서 const로 주소값을 상수화해서 바꿀 수 없음

	char temp[10];

	foo(temp,strlen(temp));

	const double pi = 3.1416;
	double Radius = 10;
	double area = 0;
	CalcArea(&pi,&Radius,&area);
	cout << "Area: " << area << endl;

	int MyNumbers[5];

	int* pNumbers = MyNumbers;
	cout << MyNumbers << endl;
	cout << pNumbers << endl;
	cout << &MyNumbers[0] << endl;
	/*
	int* pNumbers = new int[5];  <<할당한 주소를 기억못해 지우지 못함
	pNumbers = new int[5]; <<뒤에 할당받은 주소만 기억  이러한 현상을 Memory leak
	

	int Temperature;
	int* pTemparature;
	pTemparature = &Temperature;

	delete[] pNumbers;
	*pNumbers = 1;
	*/
	try {
		int* pAge = new int[536870911];
		delete[] pAge;
	}
	catch (bad_alloc) {
		cout << "Out of Memory" << endl;
	}
	int* pAge = new(nothrow) int[536870911];
	if (pAge)
	{
		delete[] pAge;
	}else
		cout << "Out of Memory" << endl;

	return 0;

}