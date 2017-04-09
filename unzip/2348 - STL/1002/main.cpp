#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
class SortableArray {
	private:
		vector<T> array;
		int maxSize;
	public:
		SortableArray (int);
		void pushBack (T);
		void sort (void);
		void printArray (void);
};

template<typename T>
SortableArray<T>::SortableArray (int m) {
	maxSize = m;
}

template<typename T>
void SortableArray<T>::pushBack (T a) {
	array.push_back(a);
}

template<typename T>
void SortableArray<T>::sort () {
	int n = array.size(), i, j;
	T temp;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (array[j] <= array[j - 1]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

template<typename T>
void SortableArray<T>::printArray () {
	typename vector<T>::iterator i;
	for (i = array.begin(); i != array.end(); i++) {
		if (i + 1 != array.end()) {
			cout<<(*i)<<" ";
		} else {
			cout<<(*i)<<" "<<endl;
		}
	}
}

