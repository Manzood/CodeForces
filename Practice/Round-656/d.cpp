#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int get (string s, int start, int finish, char x) {
    int ret = 0;
    for (int i = start, i <= finish; i++) {
        if (s[i] == x) {
            ret++;
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        bool good = true;
        int lcount = 0;
        int rcount = 0;
        lcount = get (s, 0, n/2-1, 'a');
        rcount = get (s, n/2, n-1, 'a');
        ans += min(lcount, rcount);
        int len = 
        if (lcount < rcount) {

        int ans = 0;
}