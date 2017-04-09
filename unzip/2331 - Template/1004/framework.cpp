#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#include "source.cpp"

int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);


	{
		char arr[] = "pqwridkfendkfnccsdsafsfsf";
		cout<<max(arr,strlen(arr))<<endl;
	}
	{
		double arr[] = { 2.1, 3.4, 5.6, 3.3, 5.1, 10.2 };
		cout<<max(arr,sizeof(arr)/sizeof(double))<<endl;
	}
	{
		int arr[] = { 2, 3, 5, 3, 5, 10, 1, 1005, 532 };
		cout<<max(arr,sizeof(arr)/sizeof(int))<<endl;
	}
	{
		string arr[3] = { "hello", "hi", "haha" };
		cout<<max(arr,3)<<endl;
	}

	return 0;
}