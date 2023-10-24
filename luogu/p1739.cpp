#include <iostream>

using namespace std;

int stk[100010], tt = -1;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '(')
            tt ++;
        else if (s[i] == ')') {
            if (tt == -1) {
                cout << "NO";
                return 0;
            }
            tt --;
        }
    }
    if (tt == -1) cout << "YES";
    else
        cout << "NO";
    return 0;
}