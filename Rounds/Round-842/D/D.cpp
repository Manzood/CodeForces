#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> visited;
vector<int> values;
void dfs(int node, vector<int>& nxt) {
    if (visited[node]) return;
    values.push_back(node);
    visited[node] = true;
    dfs(nxt[node], nxt);
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), nxt(n, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i]--;
        nxt[i] = a[i];
    }
    visited.assign(n, false);
    int cycles = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cycles++;
            dfs(i, nxt);
        }
        if ((int)values.size()) {
            sort(values.begin(), values.end());
            for (int j = 1; j < (int)values.size(); j++) {
                if (values[j] == values[j - 1] + 1) found = true;
            }
            values.clear();
        }
    }
    int ans = found ? n - cycles - 1 : n - cycles + 1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
