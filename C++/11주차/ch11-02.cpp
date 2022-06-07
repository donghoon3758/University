#include <iostream>


using namespace std;

template <typename T>
class smart_pointer {
private:
    T* m_pRawPointer;
public:
    smart_pointer(T* pData) : m_pRawPointer(pData) { // pData는 지역변수
    }
    ~smart_pointer() {
        delete m_pRawPointer;
    }
    T& operator* () const {// * 값을 넘겨준다. 그래서 type T& const로 인해 내부를 고칠 수 없다.
        return *m_pRawPointer;
    }
    T* operator-> () const {//-> 주소값 넘겨준다. 그래서 type T*
        return m_pRawPointer;
    }
};
class Date {

private:
    int Day;
    int Month;
    int Year;

public:
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {};

    void DisplayDate() {
        cout << Day << " / " << Month << " / " << Year << endl;
    }
};
class MyClass {
private:
    int counter;
public:
    void foo()  {
        counter = 0; //const해주면 에러발생
    }
    void foo() const {
        Bar(); // 같은 const가 되어있는것 끼리만 선언가능
    }
    /*
    void Bar() {

    }*/
    void Bar() const {

    }
};


int main()
{
    smart_pointer<int> pDynamic(new int(42));
    //smart_pointer pDynamicInt;
    cout << "Integer: " << *pDynamic << endl;
    smart_pointer<Date> pDate(new Date(11, 5, 2021));
    pDate->DisplayDate();
    return 0;
}