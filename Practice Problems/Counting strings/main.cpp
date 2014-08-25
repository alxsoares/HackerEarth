#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

LL solve(string str) {
	int n = str.size();
	LL ret = (LL)n * (n + 1) / 2;
	int last = -1, i = 0, len = 0;
	for (; i < n; i++) {
		if (str[i] == 'a' || str[i] == 'z') {
			len = i - last - 1;
			ret -= (LL)len * (len + 1) / 2;
			last = i;
		}
	}
	len = n - last - 1;
	ret -= (LL)len * (len + 1) / 2;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		string str;
		cin >> str;
		cout << solve(str) << endl;
	}
	return 0;
}

