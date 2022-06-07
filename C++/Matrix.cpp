#include <iostream>
#include <random>
#include <iomanip>
#include <string>
using namespace std;
template <typename T>
class matrix {
protected:
	T** Arr;
	int Column, Row;
	string matrixName;
public:
	matrix<T>() {
		Arr = new T * [0];
		for (int i = 0; i < 0; ++i) {
			Arr[i] = new T[0];
		}
		Arr = { 0 };
	}
	matrix<T>(string Name) {
		matrixName = Name;
	}
	matrix<T>(int row, int column) {
		Column = column;
		Row = row;
		Arr = new T * [Row];
		for (int i = 0; i < Row; ++i) {
			Arr[i] = new T[Column];
		}
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Column; ++j) {
				Arr[i][j] = 0;
			}
		}
	}
	matrix<T>(int column, int row, string Name) {
		Column = column;
		Row = row;
		matrixName = Name;
		Arr = new T * [Row];
		for (int i = 0; i < Row; ++i) {
			Arr[i] = new T[Column];
		}
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Column; ++j) {
				Arr[i][j] = 0;
			}
		}
	}
	void randomize() {
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<> distr(0, 1000);
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Column; ++j) {
				Arr[i][j] = (T)distr(eng);
			}
		}
	}
	matrix<T>(const matrix<T>& copy) {
		Row = copy.Row;
		Column = copy.Column;
		matrixName = copy.matrixName;
		Arr = copy.Arr;
	}
	int getRow() {
		return Row;
	}
	int getColumn() {
		return Column;
	}
	T& getArr(int row, int column) {
		return Arr[row][column];
	}
	matrix<int> operator + (const matrix<T>& AddMatrix) {
		matrix<int> copyMatrix(Row, Column);
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Column; ++j) {
				copyMatrix.getArr(i, j) = Arr[i][j] + AddMatrix.Arr[i][j];
			}
		}
		return copyMatrix;
	}
	matrix<T> operator * (const matrix<T>& MuxMatrix) {
		matrix<T> copyMatrix(Row, MuxMatrix.Column);
		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Column; ++j) {
				copyMatrix.getArr(i, j) = Arr[i][j] * MuxMatrix.Arr[i][j];
			}
		}
		return copyMatrix;
	}
	friend ostream& operator << (ostream& os, const matrix& printMatrix) {
		os << "[";
		for (int i = 0; i < printMatrix.Row; ++i) {
			for (int j = 0; j < printMatrix.Column; ++j) {
				os << printMatrix.Arr[i][j] << " ";
			}
			if (i == printMatrix.Row - 1) {
				os << "]";
			}
			else
				os << "\n";
		}
		os << "\n";
		return os;
	}/*
	~matrix() {
	for (int i = 0; i <Column; ++i) {
	delete[] Arr[i];
	}
	delete[] Arr;
	}*/
	//중요한 destructor 구현 실패했습니다.
};
int main() {
	matrix<float> A(4, 4, "myAMatrix");
	matrix<float> B(4, 4, "myBMatrix");
	A.randomize();
	B.randomize();
	matrix<float> C(4, 4, "myCMatrix");
	C = A;
	matrix<float> D("myDMatrix");
	D = A * B;
	matrix<int> E("myEMatrix");
	E = A + B;
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << D << endl;
	cout << E << endl;
	return 0;
}