#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif

using namespace std;
#define int long long

int query(int val) {
    cout << "+ " << val << endl;
    int response;
    cin >> response;
    return response;
}

int32_t main() {
    int n;
    cin >> n;
    int low = 1, high = n - 1, dist = 0, exp = 1, x = 1, add = 0, cur = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        // debug(low, high, mid, dist, cur);
        int guess = n - mid - dist;
        int response = query(guess);
        add += guess;
        if (cur > 0)
            cur += guess;
        else
            cur = guess + dist;
        if (response == exp) {
            x = mid;
            low = mid + 1;
            dist = cur - n;
            cur = 0;
            exp++;
        } else {
            high = mid - 1;
            dist += guess;
        }
    }
    cout << "! " << x + add << endl;
}
