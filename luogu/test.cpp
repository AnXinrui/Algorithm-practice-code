#include <iostream>
//#include <string>
#include <sstream> 
//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//#include <set>
//#include <map>
#define ll long long
#define PII pair<int, int>

using namespace std;

//const int N = 1e6 + 10;


int main()
{
	string s = "this student is studious";
	stringstream ss;
	ss << s;
	cout << ss <<' '<<ss.str() << endl;
	string w;
	cout << (ss >> w)<<' '<<w << endl;
	cout << (ss >> w)<<' '<<w << endl;
	cout << (ss >> w)<<' '<<w << endl;
	cout << (ss >> w)<<' '<<w << endl;
	cout << (ss >> w)<<' '<<w << endl;
    
    stringstream sss;
    sss << "first"<<"second";
    cout << sss.str()<<endl;
    sss.str("");
    cout << sss.str()<<endl;
    
    return 0;
}
