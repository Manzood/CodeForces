#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        scanf("%d%d%d", &n, &k, &z);
        vector <int> a(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        vector <int> pref(k);
        for (int i = 0; i < k; i++) {
            if (i == 0) {
                pref[i] = a[i];
            }
            else {
                pref[i] = pref[i-1] + a[i];
            }
        }
        int sum = 0;
        for (int i = 0; i <= k; i++) {
            sum += a[i];
            if (i > 0) {
                int temp = sum;
                temp += (a[i] + a[i-1]) * (min((k-i) / 2, z));
                int used = (min((k-i)/2, z));
                if (i + used <= k) {
                    int rem = k - i - used + 1;
                    temp += pref[i+rem] - pref[i];
                }
                mx = max (temp, mx);
            }
        }
        printf("%d\n", mx);
    }
}