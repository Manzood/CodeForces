#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int getind (int i, int n, int check) {
	if (check==-1) {
		if (i==0)
			return n-1;
		else 
			return i-1;
	}
	else {
		if (i==n-1) 
			return 0;
		else
			return i+1;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	vector <int> a(n);
	map<int, pair<int, int> mp;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		mp[a[i]]=make_pair(getind(i,n,-1), getind(i,n,1));
	}
	for (auto x: mp) {
		

}
