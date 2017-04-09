#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1, s2, s3;
    int n;
    cin >> n;
    while(n--){
        int i, j;
        cin >> s1 >> s2 >> s3;
        i = s1.find(s2, 0);
        while(i != string::npos){ 
            j = s2.length();
            s1.replace(i, j, s3);
            i = s1.find(s2, 0);
        }
        cout  << s1 << endl;
    }
}                                 

