#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;

int main() {
    string s;
    cin >> s;
    int tmp = 0;
    int tag = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] <= '9' && s[i] >= '0')
            tmp = tmp * 10 + (s[i] - '0');
        else if (s[i] == '+') {
            stk.push(tmp % 10000);
            tmp = 0;
            if (tag == 1) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a * b % 10000);
                tag = 0;
            }
        }
        else if (s[i] == '*')
        {
            stk.push(tmp % 10000);
            tmp = 0;
            if (tag == 1) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(a * b % 10000);
                tag = 0;
            }
            tag = 1;
        }

    }
    if (tmp)    stk.push(tmp);
        if (tag == 1) {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a * b % 10000);
        }
        int ans = 0;
        while (!stk.empty()) {
            int n = stk.top();
            stk.pop();
            ans = (ans + n) % 10000;
        }
    cout << ans;

    return 0;
}