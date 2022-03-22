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
    string s;
    cin >> s;
    int ind = -1;
    int sum = 0;
    char p;
    bool lt = false;
    int ops = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            sum++;
        } else {
            sum--;
        }
        if (sum == 0 && !lt) {
            ops++;
            ind = i;
        } else if (sum < 0) {
            lt = true;
        }
        if (i == ind + 1) {
            p = s[i];
        } else if (ind != i) {
            if (s[i] == p) {
                ind = i;
                sum = 0;
                lt = false;
                ops++;
            }
        }
    }
    int ans = n - 1 - ind;
    printf("%lld %lld\n", ops, ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
