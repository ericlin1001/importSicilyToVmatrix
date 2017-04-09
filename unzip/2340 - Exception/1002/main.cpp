#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
class IllegalSubscriptException {
	public:
		IllegalSubscriptException(char* s) {}
};
class Date {
	private:
		int year;
		int month;
		int day;
	public:
		Date(int y=0, int m=1, int d=1) {
			this->year = y;
			this->month = m;
			this->day = d;
		}
		static bool leapyear(int year) {
			if(year % 400 == 0) {
				return true;
			} else if(year % 100 != 0 && year % 4 == 0) {
				return true;
			} else {
				return false;
			}
		}
		int getYear() const {
			return this->year;
		}
		int getMonth() const {
			return this->month;
		}
		int getDay() const {
			return this->day;
		}
		bool operator<(Date &d) {
			if(this->year < d.year) {
				return true;
			} else if(this->year == d.year && this->month < d.month) {
				return true;
			} else if((this->year == d.year) && (this->month == d.month) && (this->day < d.day)) {
				return true;
			} else {
				return false;
			}
		}
		bool operator<=(Date &d) {
			if(this->year < d.year) {
				return true;
			} else if(this->year == d.year && this->month < d.month) {
				return true;
			} else if((this->year == d.year) && (this->month == d.month )&& (this->day <= d.day)) {
				return true;
			} else {
				return false;
			}
		}
		bool operator==(Date &d) {
			if((this->year == d.year) && (this->month == d.month) && (this->day = d.day)) {
				return true;
			} else {
				return false;
			}
		}
		bool operator!=(Date &d) {
			return !(*this == d);
		}
		bool operator>(Date &d) {
			return !(*this <= d);
		}
		bool operator>=(Date &d) {
			return !(*this < d);
		}
		int &operator[](const string &s) {
			if(s == "year" || s == "month" || s == "day") {
				if(s == "year") {
					return this->year;
				} else if(s == "month") {
					return this->month;
				} else {
					return this->day;
				}
			} else {
				throw IllegalSubscriptException("Illegal Subscript Exception");
			}
		}

};

