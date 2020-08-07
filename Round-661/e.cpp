#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, s;
        scanf("%d", &n, &s);
        vector <vector <int> > adj(n);
        vector <int> w(n-1);
        vector <int> edge(n);
        for (int i = 0; i < n-1; i++) {
            // find a good way to store edges
            int u, v;
            scanf("%d%d%d", &u, &v, &w[i]);
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u); 
            
    }
}   