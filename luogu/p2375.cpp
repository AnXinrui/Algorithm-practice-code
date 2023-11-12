#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

// v 表示有几个前缀
long long ne[N], v[N];
int main() {
    int t;
    cin >> t;
    while (t --) {
        memset(ne, 0, sizeof ne);
        memset(v, 0, sizeof v);
        char s[N];
        cin >> s + 1;
        int n = strlen(s + 1);
        v[1] = 1;
        for (int i = 2, j = 0; i <= n; i ++)
        {
            while (j && s[i] != s[j + 1])
                j = ne[j];
            if (s[i] == s[j+1]) {
                j ++;
            }
            ne[i] = j;
            v[i] = v[j] + 1;
        }
        long long ans = 1;
        for(int i=1,j=0;i<=n;i++)
        {
            while(j&&s[i]!=s[j+1])j=ne[j];
            if(s[i]==s[j+1])
            {
                j++;
            }

            while(j&&(j*2>i))j=ne[j];

            ans=ans*(v[j]+1)%mod;
        }
        cout << ans << endl;
    }

    return 0;
}