#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        long long n;
        int s;
        scanf("%lld%d", &n, &s);
        long long stored = n;
        long long ans = 0;
        int sum = 0;
        vector <int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        __int128 temp = 0;
        bool found = false;
        for (int i = sz(digits)-1; i >= 0; i--) {
            sum += digits[i];
            if (!found) {
                if (sum >= s) {
                    temp /= 10;
                    temp++;
                    temp *= 10;
                    found = true;
                }
                else {
                    temp += digits[i];
                }
            }
            temp *= 10;
        }
        temp /= 10;
        ans = temp - stored;
        if (sum <= s) ans = 0;
        printf("%lld\n", ans);
    }
}