#include <bits/stdc++.h>
using namespace std;

int N, M;
#define MAXN 1010
int fa[MAXN];
int cnt;
int x, y;

int Find(int x) {
    return x != fa[x] ? fa[x] = Find(fa[x]) : x;
}

void Union(int x, int y) {
    int a = Find(x), b = Find(y);
    if (a != b) {
        fa[a] = b;
        cnt--;
    }
}

void helper() {
    scanf("%d", &M);
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
    cnt = N;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &x, &y);
        Union(x - 1, y - 1);
    }
    printf("%d\n", cnt - 1);
}

int main() {
#ifdef LOCAL
    freopen("../in.txt", "r", stdin);
#endif
    for (;;) {
        scanf("%d", &N);
        if (N == 0) break;
        else helper();
    }
    return 0;
}
