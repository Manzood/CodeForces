#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		int curr=1;
		int incr=1;
		int ans=0;
		while (curr<=n) {
			ans++;
			curr+=incr;
			if (curr%10==0) {
				incr=incr*10+incr%10;
				curr=incr;
			}
		}
		cout<<ans<<endl;
	}
}