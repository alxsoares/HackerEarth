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
int S[MAXN], R[MAXN];
int dp[MAXN], pre[MAXN], st[MAXN];
bool vst[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		int res = -1;
		memset(vst, 0, sizeof(vst));
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));
		memset(st, -1, sizeof(st));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", S + i, R + i);
			if (i == 0) {
				if (R[i] == 1) {
					dp[i] = 1;
					pre[S[i]] = i;
					st[i] = 0;
				}
			} else {
				if (R[i] == 1) {
					st[i] = R[i - 1] == 1 ? st[i - 1] : i;
					dp[i] = dp[i - 1] + (pre[S[i]] < st[i]);
					pre[S[i]] = i;
				}
			}
			res = max(res, dp[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}

