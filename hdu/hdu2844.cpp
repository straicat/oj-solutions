#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define MAXM 100010

int n, m;
int A[MAXN], C[MAXN], dp[MAXM], num[MAXM];

void helper() {
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }
    int res = 0;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        memset(num, 0, sizeof(num));
        for (int j = A[i]; j <= m; j++) {
            if (!dp[j] && dp[j - A[i]] && num[j - A[i]] < C[i]) {
                dp[j] = 1;
                num[j] = num[j - A[i]] + 1;
                res++;
            }
        }
    }
    printf("%d\n", res);
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
