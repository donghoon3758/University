#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class CDisplay
{
public:
	void operator () (string Input) const {
		cout << Input << endl;
	}
};

int main()
{
	CDisplay mDisplayFuncObject;

	mDisplayFuncObject("Display this String!!");
	mDisplayFuncObject.operator()("Display this String!!");
	return 0;
}
