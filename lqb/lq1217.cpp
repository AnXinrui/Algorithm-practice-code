#include <iostream>
#include <cmath>

using namespace std;

const int eps = 1e-12;

int main() {
	int t;
	cin >> t;
	while (t --) {
		double n;
		scanf("%lf", &n);
		double l = 0, r = 1e5;
		double res;
		while (l < r) {
			double mid = (l + r) / 2;
			if (fabs(mid * mid * mid - n) <= eps) {
				res = mid;
				break;
			}
			if (mid * mid * mid > n) {
				r = mid - 1e-4;
				
			}
		}
	}
	
	return 0;
} 
