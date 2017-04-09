#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>

using namespace std;

class Rational {
	public:
		Rational();
		Rational(long n, long d) {
			if (n == 0) {
				numerator = 0;
				denominator = 1;
			}
			if(n < 0 && d < 0) {
				numerator = -n;
				denominator = -d;
			} else {
				numerator = n;
				denominator = d;
			}
			long m = gcd(n, d);
			numerator /= m;
			denominator /= m;
		}
		long getNumerator() {
			return numerator;
		}
		long getDenominator() {
			return denominator;
		}
		Rational add(Rational &secondRational) {
			Rational a;
			a.numerator = this->numerator * secondRational.denominator +  this->denominator*secondRational.numerator;
			a.denominator = this->denominator * secondRational.denominator;
			long d = gcd(a.denominator , a.numerator );
			a.denominator  /= d;
			a.numerator  /= d;
			return a;
		}
		Rational subtract(Rational &secondRational) {
			Rational a;
			a.numerator = this->numerator * secondRational.denominator -  this->denominator*secondRational.numerator;
			a.denominator = this->denominator * secondRational.denominator;
			long d = gcd(a.denominator , a.numerator );
			a.denominator  /= d;
			a.numerator  /= d;
			return a;
		}
		Rational multiply(Rational &secondRational) {
			Rational a;
			a.numerator  = this->numerator * secondRational.numerator;
			a.denominator  =  this->denominator * secondRational.denominator;
			long d = gcd(a.denominator , a.numerator );
			a.denominator  /= d;
			a.numerator  /= d;
			return a;
		}
		Rational divide(Rational &secondRational) {
			Rational a;
			a.numerator =  this->numerator * secondRational.denominator;
			a.denominator  = this->denominator * secondRational.numerator;
			long d = gcd(a.denominator , a.numerator );
			a.denominator  /= d;
			a.numerator  /= d;
			return a;
		}
		/* Returns an int value -1, 0, or 1 to indicate whether this rational
		   number is less than, equal to, or greater than the specified number.
		*/
		int compareTo(Rational &secondRational);
		bool equals(Rational &secondRational) {
			if(compareTo(secondRational) == 0)
				return 1;
			else
				return 0;
		}
		int intValue() {
			return (int)numerator/denominator;
		}
		double doubleValue() {
			return 1.0*numerator/denominator;
		}
		string toString();

	private:
		long numerator; //分子.
		long denominator; //分母，不能为0.
		static long gcd(long n, long d) {
			if(n == 0) {
				return 1;
			}
			long i, gcd = 1;
			for(i = 1; i <= n && i <= d; i++) {
				if(n%i == 0 && d%i == 0) {
					gcd = i;
				}
			}
			if(gcd > 0)
				return gcd;
			else
				return -gcd;
		}

};

int Rational::compareTo(Rational &secondRational) {
	long a = gcd(numerator, denominator), b = gcd(secondRational.numerator, secondRational.denominator);
	numerator /= a;
	denominator /= a;
	secondRational.numerator /= b;
	secondRational.denominator /= b;
	if(subtract(secondRational).numerator == 0)
		return 0;
	else if(subtract(secondRational).numerator < 0)
		return -1;
	else
		return 1;
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

