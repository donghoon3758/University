#include <iostream>
#include <string>
#include <sstream>
#include <memory>
using namespace std;

class Date {

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
    void operator += (int DaysToAdd) {//나 자신을 바꾸기 때문에 return을 할 필요가 없다.
        Day = Day + DaysToAdd; //this도 생략가능    
    }
    void operator -= (int DaysToAdd) {
        Day = Day - DaysToAdd;    
    }
    bool operator == (const Date& compareTo) {
        return (Day == compareTo.Day) && (Month == compareTo.Month) && (Year == compareTo.Year);
    }
    bool operator != (const Date& compareTo) {
        return !(this->operator==(compareTo));
    }
};
int main()
{
    Date Holiday(5, 5, 2021);

    Holiday.DisplayDate();

    Holiday += 10;
    cout << " Holiday += : ";
    Holiday.DisplayDate();

    Date Holiday1(25, 12, 2024);
    Date Holiday2(5,5,2025);
    if (Holiday1 == Holiday2) {
        cout << "Same" << endl;
    }
    else {
        cout << "Different" << endl;
    }
    if (Holiday1 != Holiday2) {
        cout << "Different" << endl;
    }
    else {
        cout << "Same" << endl;
    }

    Date AnotherHoliday(1, 1, 2010);
    AnotherHoliday = Holiday; // = operator를 만들어주지 않아도 default copy =를 제공해준다 하지만 shallow copy
    cout << " AnotherHoliday : ";//각각의 field값만 들어가기 때문에 
    AnotherHoliday.DisplayDate();

    return 0;
}