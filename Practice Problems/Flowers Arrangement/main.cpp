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

string solve(string flower) {
	int n = flower.size();
	if (flower[0] != 'R') return "NO";
	for (int i = 1; i < n; i++) {
		if (flower[i] != 'R' && flower[i] != 'Y') return "NO";
		if (i > 2 && flower[i] == 'Y' && flower[i - 1] == 'Y' && flower[i - 2] == 'Y')
			return "NO";
	}
	return "YES";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		string flower;
		cin >> flower;
		cout << solve(flower) << endl;
	}
	return 0;
}

