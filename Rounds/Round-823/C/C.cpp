#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> last(10, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (last[s[i] - '0'] == -1) {
            last[s[i] - '0'] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' < 9 && s[i] - '0' > 0) {
            int val = 1;
            bool inc = false;
            while (s[i] - '0' - val >= 0) {
                if (last[s[i] - '0' - val] > i) {
                    inc = true;
                }
                val++;
            }
            if (inc) s[i]++;
        }
    }
    sort(s.begin(), s.end());
    cout << s << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
