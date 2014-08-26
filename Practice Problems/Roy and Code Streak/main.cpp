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

const int MAXN = 1000000 + 5;
int n;
bool vst[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		int res = -1, cnt = 0;
		memset(vst, 0, sizeof(vst));
		for (int i = 0; i < n; i++) {
			int S, R;
			scanf("%d%d", &S, &R);
			if (R == 0) {
				res = max(res, cnt);
				cnt = 0;
			} else {
				if (vst[S] == 0)
					cnt++;
				vst[S] = true;
			}
			res = max(res, cnt);
		}
		printf("%d\n", res);
	}
	return 0;
}

