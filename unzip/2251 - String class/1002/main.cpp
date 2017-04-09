#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        s = "_" + s + "_";
        int bPos = s.find("_");
        int ePos = s.length();
        while (1) {
            if (bPos != string::npos) {
                int pos = s.find("_", bPos+1);
                if (pos != string::npos) {
                    ePos = pos;
                } else {
                    ePos = s.length();
                }
            }
            reverse(s.begin()+bPos+1, s.begin()+ePos);
            bPos = ePos;
            if (bPos == s.length()) break;
        }
        cout << s.substr(1, s.length()-2) << endl;
    }
    return 0;
}                                 

