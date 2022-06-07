#include <iostream>

using namespace std;

void returnSqure(int& Number)
{
	Number *= Number;
}

void calulateSquare(const int& Number, int& Result)
{
	Result = Number * Number;
}

void pointtest(int* pa, int* pb)
{
	*pa = *pb;
	*pb = *pb * 3;
}

int main()
{
	int i, x = 1, y = 2, z[10] = { 0 };
	int* px, * py;
	px = &x;
	py = &y;

	*px += 5;
	*py = *px * 10;
	cout << "*px: " << *px << endl;
	cout << "*py: " << *py << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	pointtest(&x, &y);
	cout << "*px: " << *px << endl;
	cout << "*py: " << *py << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	pointtest(px, py);
	cout << "*px: " << *px << endl;
	cout << "*py: " << *py << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	for (i = 0; i < 10; i++) 
		z[i] = i;
	px = &z[0];
	py = &z[0];
	*(px + 1) = *(py + 3) * 2;
	*py++;
	*py = *px + 10;
	for (i = 0; i < 10; i++)
		cout << z[i] << endl;

	int original = 30;
	const int& constRef = original;
	//constRef = 40; 에러 발생 !!!
	const int& ref2 = constRef;
	int Number = 10;
	int Square = 0;
	calulateSquare(Number, Square);
	cout << Number << "^2 = " << Square << endl;
	/*
	int original = 30;
	cout << "Original = " << original << endl;
	cout << "Original is at address: " << &original << endl;

	int& ref = original;
	cout << "Ref: " << ref << endl;
	cout << "Ref: " << &ref << endl;

	int& ref2 = ref;
	cout << "Ref2: " << ref2 << endl;
	cout << "Ref: " << &ref2 << endl;
	
	int Number = 10;
	returnSqure(Number);
	cout << "Squre is :" << Number << endl;
	*/
	return 0;