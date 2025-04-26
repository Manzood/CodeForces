#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string num;
    cin >> num;
    vector<int> cnt(10, 0);
    for (int i = 0; i < 10; i++) {
        cnt[num[i] - '0']++;
    }
    string out;
    for (int i = 0; i < 10; i++) {
        for (int j = 9 - i; j < 10; j++) {
            if (cnt[j]) {
                out += (char)j + '0';
                cnt[j]--;
                break;
            }
        }
    }
    cout << out << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
