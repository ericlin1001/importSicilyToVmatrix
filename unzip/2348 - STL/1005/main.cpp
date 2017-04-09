#include <iostream>
#include <cstring>
#include <string>
using namespace std;


bool my_equal(const char*, const char*);
bool my_equal(const int*, const int*);
bool my_equal(const float*, const float*);
bool my_equal(const double*, const double*);
bool my_equal(const int a, const int b) {
	return a == b;
}
bool my_equal(const string a, const string b) {
	return a == b;
}
bool my_equal(const float a, const float b) {
	return a == b;
}
bool my_equal(const double a, const double b) {
	return a == b;
}
bool my_equal(const string* a, const string* b) {
	return *a == *b;
}

template<class T>
bool cmp(const T a, const T b) {
	return my_equal(a, b);
}

bool my_equal(const char* s1, const char* s2) {
	if (strcmp(s1, s2) == 0)
		return true;
	else
		return false;
}

bool my_equal(const int* a, const int* b) {
	return *a == *b;
}

bool my_equal(const float* a, const float* b) {
	return *a == *b;
}

bool my_equal(const double* a, const double* b) {
	return *a == *b;
}

