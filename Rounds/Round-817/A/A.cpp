#include <algorithm>

#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string temp = "Timur";
    string inp;
    cin >> inp;
    vector<int> perm(5, 0);
    iota(perm.begin(), perm.end(), 0);
    bool ans = false;
    do {
        string cur;
        for (int i = 0; i < 5; i++) {
            cur += temp[perm[i]];
        }
        if (cur == inp) ans = true;
    } while (next_permutation(perm.begin(), perm.end()));
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
