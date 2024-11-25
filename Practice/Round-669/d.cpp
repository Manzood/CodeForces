#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int mx = 1e9;

// this is what I get for not taking the time to think clearly, and thinking prematurely both about the code and the solution
// remember, think a bit more clearly and problems start to feel trivial, at least in terms of their idea
// also, practice in some more dp could always help

int main() {
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector <int> jumps(n);
    jumps[0] = 0;
    int clarge = a[0];
    int csmall = a[0];
    int indlarge = 0;
    int indsmall = 0;
    for (int i = 1; i < n; i++) {
        jumps[i] = mx;
        if (a[i] >= clarge) {
            jumps[i] = min(jumps[i], jumps[indlarge]+1); 
            clarge = a[i];
            indlarge = i;
        }
        if (a[i] <= csmall) {
            jumps[i] = min(jumps[i], jumps[indsmall]+1);
            csmall = a[i];
            indsmall = i;
        }
    }
    if (jumps[n-1] == mx) {
        jumps[n-1] = 0;
    }
    if (indsmall < n-1 && indlarge < n-1) {
        jumps[n-1] = min(jumps[indsmall]+n-1-indsmall, jumps[indlarge]+n-1-indlarge);
    }
    printf("%d\n", jumps[n-1]);
}