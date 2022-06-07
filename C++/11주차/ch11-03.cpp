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

    Date operator + (int DaysToAdd) {//원본을 바꾸지 않기 위해 this 사용 X
        Date newDate(Day + DaysToAdd, Month, Year);
        return newDate;
    }
    Date operator - (int DaysToAdd) {//원본을 바꾸지 않기 위해 this 사용 X
        Date newDate(Day - DaysToAdd, Month, Year);
        return newDate;
    }
};
int main()
{
    Date Holiday(5, 5, 2021);

    Holiday.DisplayDate();

    Date NextHoliday(Holiday + 14);
    cout << "Next holiday on: ";
    NextHoliday.DisplayDate();

    Date PreviousHoliday(Holiday - 1);
    cout << "Previous holiday on: ";
    PreviousHoliday.DisplayDate();
    return 0;
}
