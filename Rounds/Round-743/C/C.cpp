#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> visited;
vector <int> answer;
bool possible = true;
vector <bool> visiting;
int dfs (int node, vector <vector <int>>& adj) {
    if (visited[node]) return answer[node];
    if (!possible) return answer[node];
    visited[node] = true;
    visiting[node] = true;
    int ret = 1;
    for (auto u: adj[node]) {
        if (visiting[u] == true) {
            possible = false;
            return answer[node];
        }
        if (u < node) ret = max (ret, dfs(u, adj));
        else ret = max (ret, dfs(u, adj) + 1);
    }
    answer[node] = ret;
    visiting[node] = false;
    return ret;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <vector <int>> adj(n);
        bool zerofound = false;
        int ans = -1;
        possible = true;
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%lld", &k);
            if (k == 0) zerofound = true;
            for (int j = 0; j < k; j++) {
                int temp;
                scanf("%lld", &temp);
                temp--;
                adj[i].push_back(temp);
            }
        }

        visited.resize(n, false);
        visited.assign(n, false);
        visiting.resize(n, false);
        visiting.assign(n, false);
        answer.resize(n, 1);
        answer.assign(n, 1);

        if (zerofound && possible) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    ans = max (ans, dfs(i, adj));
                }
                ans = max (ans, answer[i]);
                // debug (answer[i]);
            }
        }

        if (!possible) ans = -1;

        printf("%lld\n", ans);
    }
}
