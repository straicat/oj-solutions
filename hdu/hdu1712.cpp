#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f7f
#define MAXN 105
#define MAXM 105
#define LL long long

int n, m, res;
int A[MAXN][MAXM];
int dp[MAXM];

void helper() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= m; k++) {
                if (k <= j) {
                    dp[j] = max(dp[j], dp[j - k] + A[i][k]);
                }
            }
        }
    }
    printf("%d\n", dp[m]);
}

int main() {
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
#endif
    while (true) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;
        helper();
    }
    return 0;
}
