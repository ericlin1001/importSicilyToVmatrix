#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
class Rational {
	public:
		Rational();
		Rational(long numerator, long denominator);
		long getNumerator();
		long getDenominator();
		Rational add(Rational &secondRational);
		Rational subtract(Rational &secondRational);
		Rational multiply(Rational &secondRational);
		Rational divide(Rational &secondRational);
		int compareTo(Rational &secondRational);
		bool equals(Rational &secondRational);
		int intValue(); //Returns the numerator/denominator
		double doubleValue(); //Returns 1.0*numberator/denominator
		string toString();
		bool operator<(Rational &secondRational);
		bool operator<=(Rational &secondRational);
		bool operator>(Rational &secondRational);
		bool operator>=(Rational &secondRational);
		bool operator!=(Rational &secondRational);
		bool operator==(Rational &secondRational);
		Rational operator+(Rational &secondRational);
		Rational operator-(Rational &secondRational);
		Rational operator*(Rational &secondRational);
		Rational operator/(Rational &secondRational);
		Rational operator+=(Rational &secondRational);
		Rational operator-=(Rational &secondRational);
		Rational operator*=(Rational &secondRational);
		Rational operator/=(Rational &secondRational);
		Rational operator++();
		Rational operator--();
		Rational operator++(int dummy);
		Rational operator--(int dummy);
		Rational operator+();
		Rational operator-();
		long& operator[] (int );
		friend ostream &operator<<(ostream &stream, Rational &rational);
		friend istream &operator>>(istream &stream, Rational &rational);
		operator double();
	private:
		long numerator; //¡¤?¡Á¨®.
		long denominator; //¡¤???¡ê?2??¨¹?a0.
		static long gcd(long n, long d);
};
long& Rational :: operator [](int k) {
	if (k == 0) return numerator;
	if (k == 1) return denominator;
}
ostream &operator<<(ostream &output, Rational &k) {
	output << k.toString();
	return output;
}
istream &operator>>(istream &input, Rational &k) {
	string s;
	int i = 0;
	input >> s;
	while (s[i] != '/') k.numerator = k.numerator * 10 + s[i] - '0';
	++i;
	while (i < s.length()) k.denominator = 10 * k.denominator + s[i] - '0';
	return input;
}

Rational :: operator double() {
	return numerator * 1.0 / denominator;
}



Rational Rational :: operator++() {
	Rational t(1, 1);
	*this+= t;
	return *this;
}
Rational Rational  :: operator--() {
	Rational t(1, 1);
	*this-= t;
	return *this;
}

Rational Rational :: operator++(int dummy) {
	Rational t(1, 1), r = *this;
	*this+= t;
	return r;
}
Rational Rational :: operator--(int dummy) {
	Rational t(1, 1), r = *this;
	*this-= t;
	return r;
}
Rational Rational :: operator+() {
	return *this;
}
Rational Rational :: operator-() {
	numerator*= -1;
	return *this;
}

Rational Rational :: operator+(Rational &k) {
	return add(k);
}
Rational Rational :: operator-(Rational &k) {
	return subtract(k);
}
Rational Rational :: operator*(Rational &k) {
	return multiply(k);
}
Rational Rational :: operator/(Rational &k) {
	return divide(k);
}
Rational Rational :: operator+=(Rational &k) {
	*this = add(k);
	return *this;
}
Rational Rational :: operator-=(Rational &k) {
	*this = subtract(k);
	return *this;
}
Rational Rational :: operator*=(Rational &k) {
	*this = multiply(k);
	return *this;
}
Rational Rational :: operator/=(Rational &k) {
	*this = divide(k);
	return *this;
}

bool Rational::operator < (Rational &k) {
	if (compareTo(k) < 0) return true;
	else return false;
}
bool Rational::operator <= (Rational &k) {
	if (compareTo(k) <= 0) return true;
	else return false;
}
bool Rational::operator > (Rational &k) {
	if (compareTo(k) > 0) return true;
	else return false;
}
bool Rational::operator >= (Rational &k) {
	if (compareTo(k) >= 0) return true;
	else return false;
}
bool Rational::operator!= (Rational &k) {
	if (compareTo(k) != 0) return true;
	else return false;
}
bool Rational::operator == (Rational &k) {
	if (compareTo(k) == 0) return true;
	else return false;
}

long Rational :: gcd(long a, long b) {
	long temp = 0;
	while (a % b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}

Rational::Rational(long num, long de) {
	numerator = num;
	denominator = de;
	int i = gcd(fabs(numerator), fabs(denominator));
	numerator/= i;
	denominator/= i;
	if (denominator < 0) {
		denominator*= -1;
		numerator*= -1;
	}
}
long Rational::getNumerator() {
	return numerator;
}
long Rational::getDenominator() {
	return denominator;
}

Rational Rational :: add(Rational &k) {
	Rational temp;
	long i;
	temp.numerator = numerator * k.denominator + denominator*k.numerator;
	temp.denominator = denominator * k.denominator;
	i = gcd(fabs(temp.numerator), fabs(temp.denominator));
	temp.numerator/= i;
	temp.denominator/= i;
	if (temp.denominator < 0) {
		temp.denominator*= -1;
		temp.numerator*= -1;
	}
	return temp;
}
Rational Rational::subtract(Rational &k) {
	Rational temp;
	long i;
	temp.numerator = numerator*k.denominator - denominator*k.numerator;
	temp.denominator = denominator * k.denominator;
	i = gcd(fabs(temp.numerator), fabs(temp.denominator));
	temp.numerator/= i;
	temp.denominator/= i;
	if (temp.denominator < 0) {
		temp.denominator*= -1;
		temp.numerator*= -1;
	}
	return temp;
}

Rational Rational::multiply(Rational &k) {
	Rational temp;
	long i;
	temp.numerator = numerator * k.numerator;
	temp.denominator = denominator * k.denominator;
	i = gcd(fabs(temp.numerator), fabs(temp.denominator));
	temp.numerator/= i;
	temp.denominator/= i;
	if (temp.denominator < 0) {
		temp.denominator*= -1;
		temp.numerator*= -1;
	}
	return temp;
}
Rational Rational::divide(Rational &k) {
	Rational temp;
	long i;
	if (k.numerator == 0) return *this;
	temp.numerator = numerator * k.denominator;
	temp.denominator = denominator * k.numerator;
	i = gcd(fabs(temp.numerator), fabs(temp.denominator));
	temp.numerator/= i;
	temp.denominator/= i;
	if (temp.denominator < 0) {
		temp.denominator*= -1;
		temp.numerator*= -1;
	}
	return temp;
}
int Rational::intValue() {
	return numerator / denominator;
}
double Rational::doubleValue() {
	return  1.0 * numerator / denominator;
}
int Rational::compareTo(Rational &k) {
	if (numerator== k.numerator && denominator == k.denominator) return 0;
	if (1.0 * numerator / denominator - 1.0 * k.numerator / k.denominator > 0) return 1;
	else return -1;
}
bool Rational::equals(Rational &k) {
	if (numerator== k.numerator && denominator == k.denominator) return true;
	else return false;
}

Rational::Rational() {
	numerator = 0;
	denominator = 1;
}

string Rational::toString() {
	char s[50];
	if ( denominator == 1) {
		sprintf(s,"%ld",numerator);
	} else {
		sprintf(s,"%ld/%ld",numerator,denominator);
	}
	return string(s);
}

