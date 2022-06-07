#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

class Date{
private:
    int Day;
    int Month;
    int Year;
    string DateInString;
public:
    Date(int InputDay, int InputMonth, int InputYear)
        : Day(InputDay), Month(InputMonth), Year(InputYear) {};
    void DisplayDate() {
        cout << Day << " / " << Month << " / " << Year << endl;
    }

    Date& operator ++() {// & 붙이는게 좋지만 안붙여도 가능 안붙이면 copy가 일어나 새로 공간이 할당되어 된다.
        ++Day;//this가 생략 ++(this->Day);
        return *this;
    }
    Date& operator --() { 
        --Day;
        return *this;
    }
    Date& operator ++(int) {//위에는 prefix 지금부터는 postfix
        Date Copy(Day,Month,Year);//copy로 값을 저장 후 copy를 return 그것울 위해 instance 생성
        ++Day;
        return Copy;
    }
    Date& operator --(int) {//위에는 prefix 지금부터는 postfix
        Date Copy(Day, Month, Year);//copy로 값을 저장 후 copy를 return 그것울 위해 instance 생성
        --Day;
        return Copy;
    }
    operator const char* () {
        ostringstream formattedDate;
        formattedDate << Day << " / " << Month << " / " << Year;
        DateInString = formattedDate.str();
        return DateInString.c_str();//int형 -> string -> const char*
    }
};

int main()
{



    unique_ptr<int> pDynamicAllocInteger(new int);
    *pDynamicAllocInteger = 42;
    cout << "Integer value is: " << *pDynamicAllocInteger << endl;

    unique_ptr<Date> pHoliday(new Date(19, 5, 2021));
    pHoliday->DisplayDate();
    //unique_ptr << delete로 해제를 해주지 않아도 저게 알아서 해준다.
    return 0;
}