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
    int val = 0;
    int cost = 0;
    vector<int> opening;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            if (s[i] == '(') {
                val++;
                opening.push_back(i);
            } else {
                val--;
                cost += i - opening.back();
                opening.pop_back();
            }
        } else {
            if (val) {
                s[i] = ')';
                val--;
                cost += i - opening.back();
                opening.pop_back();
            } else {
                s[i] = '(';
                val++;
                opening.push_back(i);
            }
        }
    }
    printf("%lld\n", cost);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
