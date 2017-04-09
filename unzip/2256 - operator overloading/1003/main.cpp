#include <iostream>
#include <string>

using namespace std;


class String {
    string s;
  public:
    String() {
        s = "";
    }
    String(const char* a) {
        s = a;
    }
    String(const String& a) {
        s = a.s;
    }
    String& operator=(const char * a) {
        s = a;
        return *this;
    }
    String& operator=(const String& a) {
        s = a.s;
        return *this;
    }
    String operator+(String a) {
        String b;
        b.s = s + a.s;
        return b; 
    }
    char& operator[](int i) {
        return s[i];
    }
    char operator[](int i) const {
        return s[i];
    }
    int size() const {
        return s.size();
    }
    String& operator+=(const String& a) {
        s += a.s;
        return *this;
    }
    String& operator+=(const char* a) {
        s += a;
        return *this;
    }
    friend ostream& operator<<(ostream& out, const String& a) {
        out << a.s;
        return out;
    }
    friend istream& operator>>(istream& in, String& a) {
        in >> a.s;
        return in;
    }
    friend bool operator==(const String& x, const char* s) {
        if (x.s == s) {
            return 1;
        }
        else {
            return 0;
        }
    }
    friend bool operator==(const String& x, const String& y) {
        if (x.s == y.s) {
            return 1;
        }
        else {
            return 0;
        }
    }
    friend bool operator!=(const String& x, const char* s) {
        if (x.s != s) {
            return 1;
        }
        else {
            return 0;
        }
    }
    friend bool operator!=(const String& x, const String& y) {
        if (x.s != y.s) {
            return 1;
        }
        else {
            return 0;
        }
    } 
};                                 

