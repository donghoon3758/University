
/*
Add the CountFrequencyLetters() member method to the MyString class that we
discussed in the class.
The CountFrequencyLetters() member method finds the frequency of characters in
the
MyString.
The CountFrequencyLetters() member method will use ASCII Code (or Character)
gap
(i.e, differences) to calculate the frequency of characters in the MyString.
Frequency of characters in the MyString is the number of times they occur in a
string.
*/
#include <iostream>
using namespace std;
class MyString {
private:
	char str[100] = "I am in good shape";
	int l[100];
	int i = 0, alphabet[52] = { 0 }, j, k = 0, n = 0, o = 0;
public:
	void CountFrequencyLetters() {
		while (str[i] != '\0') {
			if (str[i] >= 'A' && str[i] <= 'z') {
				j = str[i] - 'A';
				++alphabet[j];
			}
			++i;
		}
		while (str[k] != '\0') {
			if (str[k] >= 'A' && str[k] <= 'z') {
				j = str[k] - 'A';
				l[n] = alphabet[j];
				n++;
			}
			++k;
		}
		for (int m = 0; m < 18; m++) {
			if (str[m] != ' ') {
				cout << str[m] << " : " << l[o] << endl;
				o++;
			}
		}
	}
};
int main() {
	MyString CountLetters;
	CountLetters.CountFrequencyLetters();
	return 0;
}
