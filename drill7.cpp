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


                                                        //Part 4 The version from 9.7.1

#include"std_lib_facilities.h"
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month returnMonth(int month);
class Date
{
private:
	int y,d;
	Month m;
public:
	Date(int y, Month m, int d);
	void add_day(int n);

	int year() { return y; }
	Month month() { return m; }
	int day() { return d; }
	
};

Date today(1978, Month::jun, 25);
Date tomorrow(today);

Date::Date(int y, Month m, int d) {
	if (y < 1900 || y>2018)
		cout << "Error, Invalid Year!" << endl;
	else if (static_cast<int>(m) < 1 || static_cast<int>(m) > 12)
		cout << "Error, Invalid Month!" << endl;
	else if (d < 1 || d > 31)
		cout << "Error, Invalid Date!" << endl;
	else {
		Date::y = y;
		Date::m = m;
		Date::d = d;
	}
	return;
}
void Date::add_day(int n) {
	bool lastDay = false;
	bool endyear = false;
	for (int i = 0; i < n; ++i)
	{
		if (Date::d == 31)
			lastDay = true;
		Date::d = (Date::d == 31) ? 1 : ++Date::d;
		if (lastDay)
		{
			lastDay = false;
			int mon = (static_cast<int>(Date::m) == 12) ? 1 : (static_cast<int>(Date::m) + 1);
			Date::m = returnMonth(mon);
			if (static_cast<int>(Date::m) == 12)
				endyear = true;
			if (endyear)
			{			
				endyear = false;
				++Date::y;
			}
		}
	}
}
Month returnMonth(int month)
{
	switch (month)
	{
	case 1:
		return Month::jan;
		break;
	case 2:
		return Month::feb;
		break;
	case 3:
		return Month::mar;
		break;
	case 4:
		return Month::apr;
		break;
	case 5:
		return Month::may;
		break;
	case 6:
		return Month::jun;
		break;
	case 7:
		return Month::jul;
		break;
	case 8:
		return Month::aug;
		break;
	case 9:
		return Month::sep;
		break;
	case 10:
		return Month::oct;
		break;
	case 11:
		return Month::nov;
		break;
	case 12:
		return Month::dec;
		break;
	default:
		cout << "Bad month" << endl;
	}
}
ostream& operator<<(ostream& os, Date& d)
{
	return os << d.day() << ", " << static_cast<int>(d.month()) << ", " << d.year() << endl;
}
int main() {
	//increase day by one
	tomorrow.add_day(10);

	//print out results
	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;
  
	keep_window_open();
	return 0;
}

                                                              //Part 5 The version from 9.7.2
#include "std_lib_facilities.h"

enum class Month {
	jan = 1, feb, mar, apr, may, june, jul, aug, sept, oct, nov, dec
};

class Date {

public:
	Date(int y, Month m, int d);
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }
private:
	int y, d;
	Month m;
};
Date::Date(int yy, Month mm, int dd) {
	int yearMin(1900), yearMax(3000);
	if (yy > yearMax || yy < yearMin)
		cout << "Invalid year!" << endl;
	if (int(mm) > 12 || int(mm) < 1)
		cout << "Invalid Month!" << endl;
	if (dd > 31 || dd < 1)
		cout << "Invalid date!" << endl;
	else {
		y = yy; m = mm; d = dd;
	}
}
void Date::add_day(int n) {
	if ((d += n) > 31) {
		d = d-31;
		int NextM = int(m) + 1;
		if (NextM > 12) {
			add_month(1);
		}
		else {
			m = Month(NextM);
		}
	}
}
void Date::add_month(int n) {
	int NextM = 0;
	if ((NextM = int(m) + n) > 12) {
		int x = NextM - 12;
		m = Month(x);	
		add_year(1);
	}
	else
		m = Month(NextM);
}
void Date::add_year(int n) {
	y += n;
	if (y > 3000) {
		cout << "It is not the year 3000! Busted" << endl;
		y -= n;
	}
}
ostream& operator<<(ostream& os, const Date& d) {
	return os << "" << d.year() << "," << int(d.month()) << "," << d.day() << "";
}
int main()
{
	Date today(1978, Month::jan, 30);
	Date tomorrow(today);
	tomorrow.add_day(0);
	tomorrow.add_month(12);
	tomorrow.add_year(0);

	cout << "\nToday=" << today << endl;
	cout << "\nTomorrow=" << tomorrow << endl;

	//invalid date
	Date invalidDate{ 1300, Month::dec, -4 };
  
	keep_window_open();
	return 0;
}
