#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> st;

int main() {
    int n;
    cin >> n;
    while (n --)
    {
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;

    return 0;
}