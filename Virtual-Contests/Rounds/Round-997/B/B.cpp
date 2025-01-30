#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<string> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (adj[i][j] == '1') {
                cnt++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] == '0') {
                cnt++;
            }
        }
        p[cnt] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", p[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
