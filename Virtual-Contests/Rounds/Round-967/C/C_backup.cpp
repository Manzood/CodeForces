#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x - 1;
}

void queryPath(int a, int b, vector<vector<bool>>& found,
               vector<vector<int>>& adj) {
    if (a == b || found[a][b]) {
        return;
    }
    int x = query(a, b);
    if (x == a || x == b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    } else {
        queryPath(a, x, found, adj);
        queryPath(x, b, found, adj);
    }
    found[a][b] = true;
    found[b][a] = true;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<vector<bool>> found(n, vector<bool>(n, false)),
        printed(n, vector<bool>(n, false));
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        queryPath(0, i, found, adj);
    }
    int cnt = 0;
    cout << "! ";
    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            if (printed[i][x]) continue;
            printed[i][x] = true;
            printed[x][i] = true;
            cout << i + 1 << " " << x + 1 << " ";
            cnt++;
        }
    }
    cout << endl;
    assert(cnt == n - 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
