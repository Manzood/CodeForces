#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    vector<pair<int, int>> ac;

    int n;

    cin >> n;

    long long x = 0;

    long long MAX = (long long)pow(2, 32);

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;
        int inp;
        if (s == "add") {
            cin >> inp;
            ac.push_back({1, inp});
        } else if (s == "for") {
            cin >> inp;
            ac.push_back({2, inp});
        } else {
            ac.push_back({0, 0});
        }
    }

    int i = 0;

    while (i < n) {
        int action, num;
        action = ac[i].first;
        num = ac[i].second;

        if (action == 1) {
            x += num;

            if (num >= MAX) {
                cout << "OVERFLOW\n";
                return;
            }
        }

        else if (action == 2) {
            vector<long long> prods;

            int ends = prods.size();

            int x = 0;
            vector<int> adds(ends, 0);

            for (; i < n; i++) {
                if (ac[i].first != 2) break;
                prods.push_back(ac[i].second);
            }
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
