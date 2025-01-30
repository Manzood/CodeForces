#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// 1 1 1 2 1 1 1 1 3
// eg. 1 1 1 2 1 1 1
// or  1 1 1 1 1 1 1

// length 6:
// 1 1 2 3 1 2
// 1 1 1 is one palindrome
// let f(a) = 3 every time
// then a good example : 1 2 3 4 5 1 2 :

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a;
    a.push_back(1);
    for (int i = 1; i < n - 2; i++) {
        a.push_back(a.back() + 1);
    }
    a.push_back(1);
    a.push_back(2);
    if (n == 6) {
        a = {1, 1, 2, 3, 1, 2};
    }
    for (int i = 0; i < n; i++) {
        printf("%lld%c", a[i], " \n"[i == n - 1]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
