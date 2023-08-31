#include <bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f7f
#define MAXN 510
#define LL long long

int T, E, F, N, p, w;
int P[MAXN], W[MAXN];

void helper() {
    scanf("%d %d", &E, &F);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p, &w);
        P[i] = p;
        W[i] = w;
    }

    vector<int> dp(F - E + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= F - E; i++) {
        for (int j = 0; j < N; j++) {
            if (i - W[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - W[j]] + P[j]);
        }
    }
    if (dp[F - E] == INF) {
        printf("This is impossible.\n");
    } else {
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[F - E]);
    }
}

int main() {
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    for (int i = 0; i < T; i++) helper();
    return 0;
}