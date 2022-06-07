#include <iostream>
#include <vector>
#include <functional>

using namespace std;


int main()
{
	bool AlwaysOnTop = false;

	const char* UserSelection = "yes";
	bool DeleteFile = (UserSelection == "yes");

	cout << AlwaysOnTop << endl;
	cout << DeleteFile << endl;
	auto flag = true;
	cout << flag << endl;

	int MyNumber[] = { 2011, 2052, -525 };

	vector<int> DynArrNums(3);

	DynArrNums[0] = 365;
	DynArrNums[1] = -421;
	DynArrNums[2] = 789;

	DynArrNums.push_back(20);
	cout << DynArrNums.size() << endl;
	cout << DynArrNums[3] << endl;

	int n = [](int x, int y) {return x + y; }(5, 4);
	cout << n << endl;
	//Assign the lambda expression that adds two numbers to an auto variable
	//auto f1 = [](int x, int y) {return x + y; };
	//Assign the same lambda expression to a function object
	function<int(int, int)> f2 = [](int x, int y) {return x + y; };;
	int i = 3;
	int j = 5;

	function<int(void)> f = [&i, &j] {return i + j; };

	cout << f() << endl;

	i = 22;
	j = 44;
	cout << f() << endl;
	auto f1 = [](int x, int y) {return x + y; };
	cout << f1(21,12) << endl;
	cout << f2(21, 12) << endl;
	return 0;

}