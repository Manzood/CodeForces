#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX = 5005;

vector<int> fact(MX, 1);
void precompute() {
    for (int i = 2; i < MX; i++) fact[i] = fact[i - 1] * i;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<int> pos(n, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != -1) pos[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int mex = 1; mex < n + 1; mex++) {
            // find the rightmost index l such that you can place [0 ... mex -
            // 1] inside a[l..i]
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
