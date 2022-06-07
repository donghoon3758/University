/*
l Take inputs from your keyboard.
l All inputs are (non array) just integer-type. (Do not use int array[] or string)
l You can only use +, -, *, mod (%), division (/) operators including ‘ W ’ and ‘ , ’
characters to change the amount of money into the above format described earlier.
*/

#include <iostream>

using namespace std;
#define SIBEOK 1000000000
#define BAEKMAN 1000000
#define CHEON 1000
#define ILL 1
class WonNotaion {
private:
	char comma = ',';
	char dollar = 'W';
public:
	void transform(int inputMoney) {
		cout << dollar;
		if ((inputMoney / SIBEOK) > 0 && (inputMoney / SIBEOK) < 1000) {
			cout << inputMoney / SIBEOK << comma << (inputMoney / BAEKMAN - (inputMoney / SIBEOK) * CHEON) << comma << (inputMoney / CHEON - ((inputMoney /
				BAEKMAN) * CHEON)) << comma << inputMoney % CHEON << endl;
		}
		else if ((inputMoney / BAEKMAN) > 0 && (inputMoney / BAEKMAN) < 1000) {
			cout << inputMoney / BAEKMAN << comma << (inputMoney / CHEON - (inputMoney / BAEKMAN) * CHEON) << comma << inputMoney % CHEON << endl;
		}
		else if ((inputMoney / CHEON) > 0 && (inputMoney / CHEON) < 1000) {
			cout << inputMoney / CHEON << comma << inputMoney % CHEON << endl;
		}
		else
			cout << inputMoney << endl;
	}
};
int main() {
	int money;
	cout << "가격을 입력하시오." << endl;
	cin >> money;
	WonNotaion won;
	won.transform(money);
	return 0;
}