#include <iostream>

using namespace std;

class Base {
	
};
class Derived : public Base {

};
class CUnrelated {

};
int main()
{
	typedef unsigned short BOOL;
	BOOL i;

	const char* pzString = "Hello World!";
	int* pBuf = (int*)pzString;

	Base* pBase = new Derived();
	Derived* pDerived = static_cast<Derived*>(pBase);//불가능한데 이걸 사용해야 한다면 static_cast사용
	//CUnrelated* pUnrelated = static_cast<CUnrealted*>(pBase); isA 관계가 아니면 성립이 불가하다.사용하고 싶다면 reinterpret_cast 사용
	CUnrelated* pUnrelated = reinterpret_cast<CUnrelated*>(pBase);//사용권장 X
	double dPi = 3.14159265;
	int Num = static_cast<int>(dPi);

	return 0;
}
