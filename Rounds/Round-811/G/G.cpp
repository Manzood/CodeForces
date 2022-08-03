#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> pref;
vector<int> ans;
void dfs(int node, int tot, vector<vector<int>>& adj, vector<int>& p,
         vector<int>& a, vector<int>& b) {
    int sum = 0;
    if (node != 0) sum = pref.back();
    pref.push_back(b[node] + sum);
    tot += a[node];
    // get answer for current
    int ind = upper_bound(pref.begin(), pref.end(), tot) - pref.begin();
    ans[node] = ind;
    for (auto u : adj[node]) {
        if (u != p[node]) {
            dfs(u, tot, adj, p, a, b);
        }
    }
    pref.pop_back();
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> p(n);
    vector<int> a(n), b(n);
    a[0] = 0;
    b[0] = 0;
    p[0] = -1;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld%lld", &p[i], &a[i], &b[i]);
        p[i]--;
        adj[p[i]].push_back(i);
    }
    pref.resize(0);
    ans.resize(n, -1);
    dfs(0, 0, adj, p, a, b);
    for (int i = 1; i < n; i++) {
        printf("%lld ", ans[i] - 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
