#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(vector<vector<bool>>& visited, vector<string>& s) {
    for (int i = 0; i < (int)visited[0].size(); i++) {
        if ((s[0][i] == 'B' && !visited[0][i]) ||
            (s[1][i] == 'B' && !visited[1][i]))
            return false;
    }
    return true;
}

void dfs(int i, int j, vector<string>& s, vector<vector<bool>>& visited) {
    if (visited[i][j]) return;
    if (s[i][j] != 'B') return;
    visited[i][j] = true;
    int m = (int)visited[0].size();
    if (i == 0) {
        if (s[1][j] == 'B' && !visited[1][j])
            dfs(1, j, s, visited);
        else if (j < m - 1) {
            dfs(0, j + 1, s, visited);
        }
    } else {
        if (s[0][j] == 'B' && !visited[0][j])
            dfs(0, j, s, visited);
        else if (j < m - 1) {
            dfs(1, j + 1, s, visited);
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<string> s(2);
    cin >> s[0] >> s[1];
    bool ans = false;
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    dfs(0, 0, s, visited);
    ans |= check(visited, s);
    visited.assign(2, vector<bool>(n, false));
    dfs(1, 0, s, visited);
    ans |= check(visited, s);
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
