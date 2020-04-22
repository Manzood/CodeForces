#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

pair<int,int> getans(vector <pair<int,int>> check, int sum) {
	//function that returns 
	//returns value and count of maximum occurances less than a number of occurances (stupidly stored in sum)
	int size=check.size();
	int previous=0,count=0, maxcount=0;
	int max=0;
	for (int i=0;i<size;i++) {
		if (i==0) {
			previous=check[i].first;
			count=1;
		}
		else {
			if (previous!=check[i].first) {
				count=1;
				previous=check[i].first;
			}
			else {
				count++;
				debug(count);
				if (count>maxcount && (sum==0 || maxcount<sum)) {
					maxcount=count;
					max=check[i].first;
				}
			}
		}
		//debug(count);
	}
	debug(maxcount);
	return make_pair(max,maxcount);
}

int test (vector <pair<int,int>> check,int sum, int k) {
	for (int i=0;i<check.size();i++) {
		if ((check[i].second+k)<sum) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		vector <int> nums(n);
		for (int i=0;i<n;i++) {
			scanf("%d",&nums[i]);
		}
		vector <pair<int,int>> check;
		int smallest=nums[n-1]+nums[0];
		for (int i=0;i<n/2;i++) {
			check.push_back(make_pair((nums[i]+nums[n-i-1]),min(nums[i],nums[n-i-1])));
			if(min(nums[i],nums[n-i-1])<smallest)
				smallest=min(nums[i],nums[n-i-1]);
		}
		sort(check.begin(),check.end());
		int ans;
		int count=1;
		int maxcount=0;
		int previous;
		debug(smallest);
		for (int i=0;i<check.size();i++) {
			if (i==0) {
				previous=check[i].first;
			}
			else {
				if (check[i].first<=(smallest+k)) {
					if (previous==check[i].first) {
						count++;
						if (maxcount<count)
							maxcount=count;
					}
					else {
						previous=check[i].first;
						count=1;
					}
				}
			}
		}
		ans=(n-(2*maxcount))/2;
		printf("%d\n",ans);
	}
}	
