#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

struct Human {
	Human(const char* inName, int inAge, const char* inDob) : age(inAge) {
		strcpy_s(name, inName);
		strcpy_s(DOB, inDob);
		//age = inAge;
	}
	char name[30];
	int age;
	char DOB[20];
};
int main()
{
	/*
	ofstream myFile;
	myFile.open("HelloFile.txt", ios_base::out);

	if (myFile.is_open()) {
		cout << "File open successful" << endl;
		myFile << "PNU CSE manse!!" << endl;
		myFile << "Hello file! ";

		cout << "Finishing writing to file, will close now" << endl;
		myFile.close();
	}
	ifstream myFile2;
	myFile2.open("HelloFile.txt", ios_base::in);
	if (myFile2.is_open()) {
		cout << "File open successful" << endl;
		string fileContents;
		while (myFile.good()) {
			getline(myFile2, fileContents);
			cout << fileContents << endl;
		}
		cout << "Finishing writing to file, will close now";
		myFile2.close();
	}
	else cout << "open failed" << endl;
	*/
	//Human input2        << error 발생! 변수가 없는 생성자가 없기 때문에 위에서 선언한 생성자는 변수3개가 필요.
	cerr << "error" << endl;

	stringstream convertStream;
	int  myNum = 10;
	convertStream << myNum;
	string strInput;
	convertStream >> strInput;

	cout << myNum << endl;
	cout << strInput << endl;
	Human input("PNU CSE", 101, "March 2021");
	Human input2("PNU CSE", 102, "April 2021");
	cout << input.age << endl;
	ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);
	if (fsOut.is_open()) {
		fsOut.write(reinterpret_cast<const char*>(&input), sizeof(input));
		fsOut.write(reinterpret_cast<const char*>(&input2), sizeof(input2));//input struct타입이기 때문에 에러발생  
		fsOut.close();
	}
	return 0;

}