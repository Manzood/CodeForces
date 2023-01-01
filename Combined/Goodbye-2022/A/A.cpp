#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n), b(m);
    priority_queue<int, vector<int>, greater<int> > p;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        p.push(a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        p.pop();
        p.push(b[i]);
    }
    int sum = 0;
    while ((int)p.size()) {
        sum += p.top();
        p.pop();
    }
    printf("%lld\n", sum);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
