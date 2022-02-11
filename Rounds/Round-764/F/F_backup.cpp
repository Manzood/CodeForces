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
    int answer; cin >> answer;
    return answer;
}

int32_t main() {
    int n;
    cin >> n;
    int low = 1;
    int high = n - 1;
    int ans = n;
    int cnt = 0;
    int balance = 0;
    int sum = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        debug (mid, low, high);
        int q = n - mid + balance;
        int response = query (q);
        sum += q;
        balance = n - q;
        if (response > cnt) {
            cnt = response;
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        cnt++;
        debug (ans, low, high);
    }
    debug(ans, sum);
    cout << "! " << ans + sum << endl;
}
