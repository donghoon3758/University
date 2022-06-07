#include <iostream>

using namespace std;

template<typename T1=int, typename T2=double>

class HoldPair {
private:
	T1 Value1;
	T2 Value2;
public:
	HoldPair(const T1& value1, const T2& value2) {
		Value1 = value1;
		Value2 = value2;
	}
	const T1& GetFirstValue() const {
		return Value1;
	}
	const T2& GetSecondValue() const {
		return Value2;
	}
};
int main()
{
	HoldPair<> mIntFloatFair(300, 10.09);
	cout << mIntFloatFair.GetFirstValue() << endl;
	cout << mIntFloatFair.GetSecondValue() << endl;

	/*
	HoldPair<short, char*> mIntFloatFair2(25, "C++");
	cout << mIntFloatFair2.GetFirstValue() << endl;
	cout << mIntFloatFair2.GetSecondValue() << endl;
	*/ //error발생 왜 발생하는지 잘 모르겠음. 교수님은 발생 X
	return 0;
}
