#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getchain(int node, vector<vector<int>>& p, vector<bool>& visited,
             vector<int>& chain) {
    if (visited[node]) return chain[node];
    visited[node] = true;
    for (auto u : p[node]) chain[node] += getchain(u, p, visited, chain);
    return chain[node];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    vector<bool> is_final(n, false), visited(n, false);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cur = i;
            vector<int> current_chain;
            while (cur >= 0 && cur < n && !visited[cur]) {
                current_chain.push_back(cur);
                visited[cur] = true;
                if (cur + a[cur] >= 0 && cur + a[cur] < n)
                    p[cur + a[cur]].push_back(cur);
                cur = cur + a[cur];
            }
            if (!(cur >= 0 && cur < n) || is_final[cur])
                for (auto x : current_chain) is_final[x] = true;
        }
    }
    vector<int> chain(n, 1);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) getchain(i, p, visited, chain);
    int final_count = 0, source_count = 0;
    for (int i = 0; i < n; i++) final_count += is_final[i];
    vector<bool> is_source(n, false);
    int cur = 0;
    visited.assign(n, false);
    while (cur >= 0 && cur < n && !visited[cur]) {
        visited[cur] = true;
        is_source[cur] = true;
        source_count++;
        cur = cur + a[cur];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!is_source[i]) {
            ans += (2 * n + 1) * is_final[0];
        } else {
            ans += (final_count - chain[i] * is_final[0] + n + 1);
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
