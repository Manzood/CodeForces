#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = 0;
pair <int, int> dfs(int node, vector <vector <int>>& adj, string& colors) {
    pair <int, int> retval = {0, 0};
    colors[node] == 'B' ? retval = {1, 0} : retval = {0, 1};
    for (auto u: adj[node]) {
        pair <int, int> temp = dfs (u, adj, colors);
        retval.first += temp.first;
        retval.second += temp.second;
    }
    if (retval.first == retval.second) ans++;
    return retval;
}

void solve([[maybe_unused]] int test) {
    ans = 0;
    int n;
    scanf("%lld", &n);
    vector <int> a(n, -1);
    vector <vector <int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        adj[a[i]].push_back(i);
    }
    string s;
    cin >> s;
    dfs(0, adj, s);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
