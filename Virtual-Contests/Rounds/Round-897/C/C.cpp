#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int out) {
    cout << out << endl;
    int response;
    cin >> response;
    if (response == -2) exit(0);
    return response;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int num = 0;
    for (int i = 0; i <= n; i++) {
        if (!s.count(i)) {
            num = i;
            break;
        }
    }
    int response = query(num);
    while (response != -1) {
        response = query(response);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
