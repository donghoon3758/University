#include <iostream>

using namespace std;
template <typename objectType>
const objectType GetMax(const objectType& value1,const objectType& value2) {//&붙이게 되면 상수를 넘겨줄 수 없다 const를 해주면 상수도 가능.
	if (value1 > value2)
		return value1;
	else
		return value2;   
}
//objectType앞 const는 compiler가 결과에 손 못대게 할려고 사용
int main()
{
	int i = 1, j = 2;
	cout << GetMax<int>(i, j) << endl;
	cout << GetMax<double>(1.5, 2.6) << endl; //const로 해줘서 상수도 가능

	int outcome = GetMax<int>(1, 2);
	cout << outcome << endl;
	return 0;
}