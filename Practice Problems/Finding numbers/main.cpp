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

LL solve(LL n, LL m, LL z) {
	LL ret = 0;
	for (LL x = 1; x <= (LL)sqrt(z); x++) {
		if (z % x == 0) {
			LL y = z / x;
			if (x <= n && y <= m) {
				ret++;
			}
			if (x <= m && y <= n && x != y) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		LL n, m, z;
		cin >> z >> n >> m;
		cout << solve(n, m, z) << endl;
	}
	return 0;
}

