#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    array<vector<string>, 6> f;
    while (n --) {
        string s;
        cin >> s;
        f[s.size()].push_back(s);
    }
    long long ans = 0;
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 5; j ++)
            if ((i + j) % 2 == 0) {
                array<int, 100> cnt{};
                int h = (i + j) / 2;
                for (auto x: f[i]) {
                    int s = 50;
                    for (int k = 0; k < i; k ++) {
                        if (k < h)
                            s += x[k] - '0';
                        else
                            s -= x[k] - '0';
                    }
                    cnt[s] ++;
                }
                for (auto x: f[j]) {
                    int s = 50;
                    for (int k = 0; k < j; k ++) {
                        if (i + k < h)
                            s -= x[k] - '0';
                        else
                            s += x[k] - '0';
                    }
                    ans += cnt[s];
                }

            }

    cout << ans << "\n";
    return 0;
}