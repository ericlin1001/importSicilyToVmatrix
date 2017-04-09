#include <iostream>
#include<string>
using namespace std;

class Person {
	public:
		Person() {
			cout << "Construct Person" << endl;
		}
		~Person() {
			cout << "Destruct Person" << endl;
		}
	public:
		string name;      //person?¡¥s name
		int sex;           //1--male, 0?afemale
};

class Student : public Person {
	public:
		string sno;
		Student () {
			cout << "Construct Student" << endl;
		}
		~Student () {
			cout << "Destruct Student" << endl;
		}
};

class Worker : public Person {
	public:
		string wno;
		Worker () {
			cout << "Construct Worker" << endl;
		}
		~Worker () {
			cout << "Destruct Worker" << endl;
		}
};

class InService: public Student, public Worker {
	public:
		InService () {
			cout << "Construct InService" << endl;
		}
		~InService () {
			cout << "Destruct InService" << endl;
		}
};
