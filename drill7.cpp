                                                        //CHAPTER NO 9
                                               //Part 1 The version from 9.4.1


#include "std_lib_facilities.h"
using namespace std;
struct Date {
        int year;
        int month;
        int day;
};
void init_day(Date& dd, int year, int month, int day)
{
        if(month < 1 || month > 12 )
                error("Invalid month");
        if(day <1 || day > 31)
                error("Invalid day");
        dd.year=year;
        dd.month=month;
        dd.day=day;
}
void add_day(Date& dd, int x)
{
        dd.day +=x;
        if(dd.day>31)
        {
                dd.day=1;
                ++dd.month;
        }
        if(dd.month>12)
        {
                dd.month=1;
                ++dd.year;
        }
}
ostream& operator<<(ostream& os, Date& d)
{
        return os << d.year << "-" << d.month << "-" << d.day << endl;
}
void f()
{
        try{
                Date today;
                init_day(today, 1978,6,25);
                //Date baddate;
                //init_day(baddate, 2004.13,-5)
          
                Date tomorrow = today;
                add_day(tomorrow, 1);

                cout << "Today's date: " << today << endl;
                cout << "Tomorrow's date: " << tomorrow << endl;
        }
        catch(exception& e)
        {
                cerr << e.what() << endl;
        }
}
int main()
{
        f();
        return 0;
}

                                                     // Part 2 The version from 9.4.2


#include "std_lib_facilities.h"
using namespace std;
struct Date
{
        int year,month,day;

        Date(int year, int month, int day);

        void add_day(int x);
};
//defining outside the class
Date::Date(int y, int m, int d)
{
        year = y;
        month = m;
        day = d;

        if(month < 1 || month > 12 )
                error("Invalid month");
        if(day <1 || day > 31)
                error("Invalid day");
}
void Date::add_day(int x)
{
        day+=x;
        if(day>31)
        {
                day=1;
                ++month;
        }
        if(month>12)
        {
                month=1;
                ++year;
        }
}
ostream& operator<<(ostream& os, Date& d)
{
        return os << d.year << "-" << d.month << "-" << d.day << endl;
}
void f()
{
        try{
                Date today(1978, 6, 25);
                //Date invalid_date(2004,13,-5);
                Date tomorrow = today;

                tomorrow.add_day(1);

                cout << "Today's date: " << today << endl;

                cout << "Tomorrow's date: " << tomorrow << endl;
        }
        catch(exception& e)
        {
                cerr << e.what() << endl;
        }
}
int main()
{
        f();
        return 0;
}

                                                         //Part 3 The version from 9.4.3

#include "std_lib_facilities.h"
using namespace std;
class Date
{
int y, m, d;
public:
Date(int y, int m, int d);
  
void add_day(int x);
int month() {
        return m;
}
int day() {
        return d;
}
int year() {
        return y;
}
};
Date::Date(int yy, int mm, int dd)
{
        y = yy;
        m = mm;
        d = dd;
  
        if(m < 1 || m > 12 )
                error("Invalid month");
        if(d < 1 || d > 31)
                error("Invalid day");
}
void Date::add_day(int x)
{
        d+=x;
        if(d>31)
        {
                d=1;
                ++m;
        }
        if(m>12)
        {
                m=1;
                ++y;
        }
}
ostream& operator<<(ostream& os, Date& d)
{
        return os << d.year() << "-" << d.month() << "-" << d.day() << endl;
}
void f()
{
        try
        {
                Date today(1978, 6, 25);
                //Date invalid_date(2004, 13, -5);

                Date tomorrow = today;
                tomorrow.add_day(1);
          
                cout << "Today's date: " << today << endl;
                cout << "Tomorrow's date: " << tomorrow << endl;
        }
        catch(exception& e)
        {
                cerr << e.what() << endl;
        }
}
int main()
{
        f();
        return 0;
}
