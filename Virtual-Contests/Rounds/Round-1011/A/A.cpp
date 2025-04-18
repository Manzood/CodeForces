#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    set<char> l;
    for (auto c : s) {
        l.insert(c);
    }
    if (s < rev) {
        printf("YES\n");
        return;
    }
    if (k > 0 && (int)l.size() > 1) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
