#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n --) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0] == s[1] && s[1] == s[2] && s[2] != s[3] || s[0] != s[1] && s[1] == s[2] && s[2] == s[3])
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}