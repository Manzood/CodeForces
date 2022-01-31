#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int total = 1000;
const int inf = 1e18;

vector <int> moves(total + 1, inf);
void precompute() {
    moves[1] = 0;
    for (int i = 1; i <= total; i++) {
        for (int j = 1; j <= i; j++) {
            int val = i / j;
            if (i + val > total) continue;
            moves[i + val] = min(moves[i + val], moves[i] + 1);
        }
    }
}

int knapSack(int W, vector <int>& wt, vector <int>& val, int n) {
    vector <int> dp(W + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = moves[b[i]];
    }
    int W = min(k, 12000LL);
    // a -> wt
    // c -> val
    int answer = knapSack(W, a, c, n);
    printf("%lld\n", answer);
}

int32_t main() {
    precompute();
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
