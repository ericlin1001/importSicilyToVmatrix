#include <iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

class Int {
		int i;
	public:
		Int() {
		}
		Int(double n): i((int)n) {}
		int getI() {
			return i;
		}
		Int& operator=(double n) {
			i = (int)n;
			return *this;
		}
		operator int() const {
			return i;
		}
		friend ostream & operator<<(ostream & os, const Int & a) {
			os << a.i;
			return os;
		}
		friend istream & operator>>(istream & is, Int & a) {
			is >> a.i;
			return is;
		}

		Int& operator+=(double n) {
			i = (int)(i + n);
			return *this;
		}
		Int& operator-=(double n) {
			i = (int) (i - n);
			return *this;
		}

		double operator+(double n) {
			double a;
			a = i + n;
			return a;
		}

		Int operator+(const Int& n) {
			Int a;
			a.i = i + n.i ;
			return a;
		}

		double operator-(double n) {
			double a;
			a = i - n;
			return a;
		}

		Int operator-(const Int& n) {
			Int a;
			a.i = i - n.i ;
			return a;
		}

		Int operator-() {
			Int a;
			a.i  = -i;
			return a;
		}

		Int& operator*=(double n) {
			i = (int) (i * n);
			return *this;
		}
		double operator*(double n) {
			double a;
			a =  i * n;
			return a;
		}

		Int operator*(const Int& n) {
			Int a;
			a.i = i * n.i ;
			return a;
		}

		Int& operator/=(double n) {
			i = (int) (i / n);
			return *this;
		}
		double operator/(double n) {
			double a;
			a = i / n;
			return a;
		}

		Int operator/(const Int& n) {
			Int a;
			a.i = i / n.i ;
			return a;
		}

		Int operator%(double n) {
			Int a;
			a.i = i % (int)n;
			return a;
		}
		friend  Int operator%(double n, const Int& b) {
			Int a;
			a.i =(int)n %  b.i;
			return a;
		}
		Int operator%(const Int& n) {
			Int a;
			a.i = i % n.i ;
			return a;
		}

		Int& operator++() {
			i++;
			return *this;
		}
		Int& operator--() {
			i--;
			return *this;
		}
		Int operator++(int) {
			Int i2 = *this;
			i++;
			return i2;
		}
		Int operator--(int) {
			Int i2 = *this;
			i--;
			return i2;
		}

		//add any member function needed here
};

