clude <iostream>

using namespace std;

class Base {

};
class Derived : public Base {

};
class CUnrelated{

};
class SomeClass {
public:
	//void DisplayMembers() const {};//방법 1 (하지만 안에 값 X)
	void DisplayMembers() {

	}
};
void DisplayAllData(const SomeClass& mData) {//const로 받는 경우 
	SomeClass& refData = const_cast<SomeClass&>(mData);//방법2
	refData.DisplayMembers(); //const reference에서  non-const member 선언 할 수 없다.
}
void DisplayAllData(const SomeClass* pData) {//const SomeClass*로 받을 경우
	SomeClass* pCastedData = const_cast<SomeClass*>(pData);
	pCastedData->DisplayMembers(); 
}
int main()
{
	Base* pBase = new Base();
	//CUnrelated* pUnrelated = static_cast<CUnrelated*>(pBase); 사용하고 싶다면 reinterpret_cast 사용
	CUnrelated* pUnrelated = reinterpret_cast<CUnrelated*>(pBase);

	return 0;
}