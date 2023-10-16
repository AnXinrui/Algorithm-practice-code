#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;
    while (q --) {
        string s;
        cin >> s;
        int t = 1;
        for (int i = 0; i < int(s.size()); i ++) {
            if (s[i] == 'L')
                t = t * 2 - 1;
            else
                t = t * 2;
        }
        cout << t << endl;
    }

    return 0;
}