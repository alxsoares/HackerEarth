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

const int MAXN = 105;
int n, m;
int A[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		int ret = 1;
		dp[1][1] = 1;
		for (int i = 2; i <= n; i++) {
			if (dp[i - 1][1] == 0) continue;
			if (A[i][1] > A[i - 1][1]) dp[i][1] = dp[i - 1][1] + 1;
			ret = max(ret, dp[i][1]);
		}
		for (int j = 2; j <= m; j++) {
			if (dp[1][j - 1] == 0) continue;
			if (A[1][j] > A[1][j - 1]) dp[1][j] = dp[1][j - 1] + 1;
			ret = max(ret, dp[1][j]);
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (dp[i - 1][j] != 0 && A[i][j] > A[i - 1][j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
				}
				if (dp[i][j - 1] != 0 && A[i][j] > A[i][j - 1]) {
					dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
				}
				ret = max(ret, dp[i][j]);
			}
		}
		printf("%d\n", ret);
 	}
	return 0;
}

