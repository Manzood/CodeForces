#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
// #define int long long

vector<int> primes_list;
vector<bool> is_prime;

const int N = (int)3e5 + 5;
constexpr int INF = (int)1e9 + 7;

void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    primes_list.clear();
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (long long j = (long long)i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        primes_list.push_back(i);
    }
}

vector<int> path;
int bfs(int source, vector<vector<int>>& adj, vector<int>& dest,
        vector<vector<int>>& mp) {
    int n = (int)adj.size();
    queue<int> q;
    vector<int> dist(n, INF), prev(n, -1), val(n, -1);
    vector<bool> visited(n, false);
    q.push(source);
    dist[source] = 0;
    visited[source] = true;
    int ind = -1;
    while (!q.empty()) {
        int cur = q.front();
        bool found = false;
        for (auto x : dest) {
            if (cur == x) {
                ind = x;
                found = true;
            }
        }
        if (found) break;
        q.pop();
        for (int i = 0; i < (int)adj[cur].size(); i++) {
            int u = adj[cur][i];
            if (!visited[u]) {
                dist[u] = min(dist[u], dist[cur] + 1);
                prev[u] = cur;
                val[u] = mp[cur][i];
                visited[u] = true;
                q.push(u);
            }
        }
    }
    int cur = ind;
    while (cur != -1) {
        path.push_back(val[cur]);
        cur = prev[cur];
    }
    reverse(path.begin(), path.end());
    return ind > -1 ? dist[ind] : INF;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int s, t;
    scanf("%d%d", &s, &t);
    s--;
    t--;
    if (s == t) {
        printf("1\n%d\n", s + 1);
        return;
    }
    vector<vector<int>> adj(N);
    vector<int> sources, dest;
    vector<vector<int>> mp(N);
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        vector<int> current_list;
        for (int j = 2; j * j <= cur; j++) {
            if (cur % j == 0) {
                current_list.push_back(j);
                while (cur % j == 0) {
                    cur /= j;
                }
            }
        }
        if (cur > 1) current_list.push_back(cur);
        for (auto x : current_list) {
            for (auto y : current_list) {
                if (x == y) continue;
                adj[x].push_back(y);
                adj[y].push_back(y);
                mp[x].push_back(i);
                mp[y].push_back(i);
            }
        }
        if (i == s) {
            sources = current_list;
        }
        if (i == t) {
            dest = current_list;
        }
    }
    int ans = INF;
    vector<int> best_path;
    for (auto source : sources) {
        path.clear();
        int val = bfs(source, adj, dest, mp);
        if (val < ans) {
            ans = val;
            best_path = path;
        }
    }
    assert(ans <= INF);
    printf("%d\n", ans == INF ? -1 : ans + 2);
    if (ans != INF) {
        // get the best path
        for (int i = 0; i < (int)best_path.size(); i++) {
            if (i == 0) best_path[i] = s;
            printf("%d ", best_path[i] + 1);
        }
        printf("%d\n", t + 1);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    sieve(N);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
