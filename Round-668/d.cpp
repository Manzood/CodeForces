#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

vector <vector <int>> adj;
vector <bool> visited;
vector <int> distfroma;
int dfs (int node, int dist) {
    if (visited[node]) return 0;
    visited[node] = true;
    int ret = 0;
    for (auto x: adj[node]) {
        if (!visited[x]) {
            ret = max(ret, dfs(x, dist+1)+1);
        }
    }
    return ret;
}
void dfs2 (int node, int dist) {
    if (visited[node]) 
        return;
    visited[node] = true;
    distfroma[node] = dist;
    for (auto x: adj[node]) {
        dfs2(x, dist+1);
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, a, b, da, db;
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        adj.resize(n);
        visited.resize(n);
        distfroma.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            distfroma[i] = 0;
            vector <int> temp;
            adj[i] = temp;
        }
        for (int i = 0; i < n-1; i++) {
            int u, v; 
            scanf("%d%d", &u, &v);
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mx = dfs(0, 0);
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        dfs2(a-1, 0);
        // sort and then check if there is a continuous set of repeats
        bool ans = true;
        if (a == b || distfroma[b-1] <= da) {
            ans = false;
        }
        if (db < 2*da + 1) {
            ans = false;
        }
        if (mx < 2*da + 1) {
            ans = false;
        }
        if (ans) {
            printf("Bob\n");
        }
        else {
            printf("Alice\n");
        }
    }
}