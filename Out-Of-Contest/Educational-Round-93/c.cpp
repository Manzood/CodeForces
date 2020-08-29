#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
#define int long long

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> pref(n+1);
        string a;
        cin >> a;
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + a[i] - '0';
        }
        map <int, int> mp;
        int ans = 0;
        for (int i = 0; i < n+1; i++) {
            int temp = pref[i] - i;
            mp[temp]++;
            ans += mp[temp]-1;
        }
        printf("%lld\n", ans);
    }
}