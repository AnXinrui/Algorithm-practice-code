#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#define ll long long
#define PII pair<int, int>

using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    int cnt = 0x3f3f3f3f;
    for (int i = 0; i <= m - n; i ++) {
        vector<int> res; 
        int num = 0;
        for (int j = 0; j < n; j ++) {
            if (a[j] != b[i + j]) {
                res.push_back(j + 1);
                ++ num;
            }
        }
        if (num < cnt) {
            cnt = num;
            ans = res;
        }
    }
    cout << cnt << endl;
    if (cnt) {
        for (int i: ans) {
            cout << i << " ";
        }
    }
    return 0;
}
