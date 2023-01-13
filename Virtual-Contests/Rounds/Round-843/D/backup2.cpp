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
int bfs(int s, int t, vector<vector<int>>& adj,
        vector<vector<int>>& adj_primes) {
    vector<int> prev(N, -1), dist(N, INF), dist_primes(N, INF);
    vector<bool> vis(N, false), vis_prime(N, false);
    queue<pair<int, int>> q;
    dist[s] = 0;
    vis[s] = true;
    int cur = s;
    q.push({cur, 0});
    while (!(cur == t || q.empty())) {
        auto [tmp, color] = q.front();
        cur = tmp;
        q.pop();
        // dist_primes
        if (color) {
            for (auto u : adj_primes[cur]) {
                if (!vis[u]) {
                    dist[u] = min(dist[u], dist_primes[cur] + 1);
                    vis[u] = true;
                    prev[u] = prev[cur];
                    q.push({u, 0});
                }
            }
        } else {
            for (auto u : adj[cur]) {
                if (!vis_prime[u]) {
                    dist_primes[u] = min(dist_primes[u], dist[cur] + 1);
                    vis_prime[u] = true;
                    prev[u] = cur;
                    q.push({u, 1});
                }
            }
        }
    }
    if (cur == t) {
        while (cur != -1) {
            path.push_back(cur);
            cur = prev[cur];
        }
    }
    reverse(path.begin(), path.end());
    return dist[t] / 2;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> mp(N, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i + 1;
    }
    int s, t;
    scanf("%d%d", &s, &t);
    if (a[s - 1] == a[t - 1]) {
        if (s == t) {
            printf("1\n%d\n", s);
        } else if (s != t && a[s - 1] == 1) {
            printf("-1\n");
        } else {
            printf("2\n");
            printf("%d %d\n", s, t);
        }
        return;
    }
    vector<vector<int>> adj(N), adj_primes(N);
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        for (int j : primes_list) {
            if (j * j > cur) break;
            if (cur % j == 0) {
                adj[a[i]].push_back(j);
                adj_primes[j].push_back(a[i]);
                while (cur % j == 0) cur /= j;
            }
        }
        if (cur > 1) {
            adj[a[i]].push_back(cur);
            adj_primes[cur].push_back(a[i]);
        }
    }
    int dist = bfs(a[s - 1], a[t - 1], adj, adj_primes);
    // debug(path);
    if (dist == INF / 2) {
        printf("-1\n");
    } else {
        printf("%d\n", dist + 1);
        assert(dist + 1 == (int)path.size());
        for (int i = 0; i < (int)path.size(); i++) {
            if (i == 0)
                printf("%d ", s);
            else if (i + 1 == (int)path.size())
                printf("%d ", t);
            else
                printf("%d ", mp[path[i]]);
        }
        printf("\n");
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
