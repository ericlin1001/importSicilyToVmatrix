#include<iostream>
#include"source.cpp"
using namespace std;
String f1(String a, String b)
{
	a[2] = 'x';
	char c = b[2];
	cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
	return b;
}

void f2(String s, const String& r)
{
	char c1 = s[1];	// c1 = s.operator[](1).operator char()
	s[1] = 'c';		// s.operator[](1).operator=('c')

	char c2 = r[1];	// c2 = r.operator[](1)
//	r[1] = 'd';		// error: assignment to non-lvalue char, r.operator[](1) = 'd'
}

void f()
{
	String x, y, s;
	cout << "Please enter two strings\n";
	cin >> x >> y;
	cout << "x= " << x << " , y = " << y << '\n';

    y = f1(x,y);
    cout << y << endl;
    
    f2(x,y);

	cout << "s = \"" << s << "\"" << endl;
	s = "abc";
	cout << "s = \"" << s << "\"" << endl;

    cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
	String z = x;
	if (x != z) cout << "x corrupted!\n";
	x[0] = '!';
	if (x == z) cout << "write failed!\n";
	cout << "exit: " << x << ' ' << z << '\n';	

    z = s;
	if (s != z) cout << "s corrupted!\n";
	s[0] = '!';
	if (s == z) cout << "write failed!\n";
	cout << "exit: " << s << ' ' << z << '\n';	

}

int main()
{
  f();
}
