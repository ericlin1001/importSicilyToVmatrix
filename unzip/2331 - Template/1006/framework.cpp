#include <iostream>
#include <string>
#include "source.cpp"
using namespace std;

int main()
{
  //freopen("result.txt","w",stdout);
  int v1 = 1;
  int v2 = 2;
  swapVar(v1, v2);
  cout << v1 << " " << v2 << endl;

  double d1 = 1.1;
  double d2 = 2.5;
  swapVar(d1, d2);
  cout << d1 << " " << d2 << endl;

  string str1="aa";
  string str2="abc";
  swapVar(str1,str2);
  cout<< str1 <<" "<< str2 << endl;

  char c1='a';
  char c2='b';
  swapVar(c1,c2);
  cout<< c1 <<" "<< c2 << endl;


  return 0;
}
