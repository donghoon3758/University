#include <iostream>

using namespace std;

class A {
public:
	virtual void foo() {
		cout << "A foo" << endl;
	}
};
class AA1 : public A {
public:
	void foo() {
		cout << "AA1 foo" << endl;
	}
};
class AA2 : public A {
public:
	void foo() {
		cout << "AA2 foo" << endl;
	}
};
void DetectAType(A* InputA) {
	AA1* pIsAA1 = dynamic_cast<AA1*>(InputA);
	if (pIsAA1) {
		cout << "Detect AA1" << endl;
		pIsAA1->foo();
	}
	AA2* pIsAA2 = dynamic_cast<AA2*>(InputA);
	if (pIsAA2) {
		cout << "Detect AA2" << endl;
		pIsAA2->foo();
	}
}

int main()
{
	AA1 myAA1;
	AA2 myAA2;

	DetectAType(&myAA1);
	DetectAType(&myAA2);

	return 0;
}