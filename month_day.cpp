#include <iostream>

using namespace std;

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: 根据月份和日期设置一年中的第几天 */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

/* month_day: 根据一年中的第几天设置月份和日期 */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}

int main() {
    int year = 2023;
    int month = 10;
    int day = 3;

    // 测试 day_of_year 函数
    int dayOfYear = day_of_year(year, month, day);
    cout << "Year: " << year << ", Month: " << month << ", Day: " << day << " is the " << dayOfYear << "th day of the year." << endl;

    // 测试 month_day 函数
    int monthResult, dayResult;
    int yearday = 276; // 假设是一年中的第 276 天
    month_day(year, yearday, &monthResult, &dayResult);
    cout << "Year: " << year << ", Yearday: " << yearday << " corresponds to Month: " << monthResult << ", Day: " << dayResult << "." << endl;

    return 0;
}
