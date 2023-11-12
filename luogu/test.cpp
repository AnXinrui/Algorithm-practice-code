#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;



int main() {
	int a,b,c,d,m;
	cin >> a >> b >> c >> d >> m;
	int s1 = 5 * c;
	if (s1<=m) {
		cout << max(0, s1-20*(b-d));
	}
	else
		cout << max(0, s1+20*d-20*(b-d));
	
	return 0; 
}

