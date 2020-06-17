#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,k;
		scanf("%d%d",&n,&k);
		string s;
		cin>>s;
		vector <int> ones;
		for (int i=0;i<s.size();i++) {
			if (s[i]=='1') {
				ones.push_back(i);
			}
		}
		int index=0;
		int ans=0;
		for (int i=0;i<ones.size();i++) {
			if (ones[i]-index>k) {
				ans+=(ones[i]-index)/(k+1);
			}
			index=ones[i]+k+1;
		}
		while (index<s.size()) {
			ans++;
			index+=k+1;
		}
		cout<<ans<<endl;
	}
}