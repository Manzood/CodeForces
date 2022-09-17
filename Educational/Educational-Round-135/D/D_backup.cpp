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
    int left = 0;
    int right = n - 1;
    bool draw = true;
    int bmove = 0;
    char prev = 'a';
    while (left <= right) {
        if (!bmove) {
            if (s[left + 1] != s[left] && s[right] != s[left]) {
                draw = false;
                break;
                prev = s[left];
                left++;
            } else if (s[right - 1] != s[right] && s[left] != s[right]) {
                draw = false;
                break;
                prev = s[right];
                right--;
            } else {
                // pick smaller element
                prev = s[left];
                left++;
            }
        } else {
            if (s[left] != prev && s[right] != prev) {
                draw = false;
                break;
            } else {
                if (s[left] == prev) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        bmove ^= 1;
    }
    draw ? printf("Draw\n") : printf("Alice\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
