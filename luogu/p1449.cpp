// 手写栈
#include <iostream>

using namespace std;

int stk[100010], tt = -1;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int tmp = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] >= '0' && s[i] <= '9')
            tmp = tmp * 10 + (s[i] - '0');
        else if (s[i] == '.') {
            stk[++ tt] = tmp;
            tmp = 0;
        }
        else if (s[i] == '+') {
            int b = stk[tt --];
            int a = stk[tt --];
            stk[++ tt] = a + b;
        }
        else if (s[i] == '-') {
            int b = stk[tt --];
            int a = stk[tt --];
            stk[++ tt] = a - b;
        }
        else if (s[i] == '*') {
            int b = stk[tt --];
            int a = stk[tt --];
            stk[++ tt] = a * b;
        }
        else if (s[i] == '/') {
            int b = stk[tt --];
            int a = stk[tt --];
            stk[++ tt] = a / b;
        }
        else break;
    }
    cout << stk[tt];

    return 0;
}

/*  ***********************************************************************  */
// STL版本

#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;

int main() {
    string s;
    cin >> s;
    int tmp = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= '0' && s[i] <= '9')
            tmp = tmp * 10 + (s[i] - '0');
        else if (s[i] == '.') {
            stk.push(tmp);
            tmp = 0;
        }
        else if (s[i] == '+') {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            stk.push(a + b);
        }
        else if (s[i] == '-') {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            stk.push(a - b);
        }
        else if (s[i] == '*') {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            stk.push(a * b);
        }
        else if (s[i] == '/') {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            stk.push(a / b);
        }
        else break;
    }
    cout << stk.top();

    return 0;
}
