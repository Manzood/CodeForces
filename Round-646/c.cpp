#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

vector <int> visited;
vector<pair<int,int>> getdepth(vector <int> *tree, int node, vector <pair<int,int>> depth, int d) {
	//debug(node);
	//debug(visited[node]);
	if (visited[node])
		return depth;
	if (tree[node].size()==1) {
		depth.emplace_back(node,d);
		return depth;
	}
	visited[node]=true;
	//debug("Made it here");
	for (auto u: tree[node]) {
		//debug(u);
		depth=getdepth (tree, u, depth, d+1);
	}
	depth.emplace_back(node,d);
	//debug(depth.size());
	return depth;
}
vector <int> ans;
int getans(vector<pair<int,int>> depth, vector <int>* tree, int node, int primary) {
	if (visited[node])
		return ans[node];
	else {
		visited[node]=true;
		int m=-1;
		for (int u: tree[node]) {
			if (m==-1) {
				ans[u]=primary-getans(depth, tree, u, primary);
				m=ans[u];
			}
			else {
				ans[u]=primary-getans(depth,tree,u, primary);
				m=min(ans[u],m);
			}
		}
		return m;
	}
}


int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,x;
		scanf("%d %d",&n,&x);
		vector <int> adj[n];
		vector <int> count(n);
		for (int i=0;i<n;i++) {
			count[i]=0;
		}
		for (int i=0;i<n-1;i++) {
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
			count[u]++;
			count[v]++;
		}
		//dfs
		vector <pair<int,int>> depth;
		for (int i=0;i<n;i++) {
			visited.push_back(false);
		}
		depth=getdepth(adj,x-1,depth,0);
		for (int i=0;i<n;i++)
			visited[i]=false;
		for (int i=0;i<n;i++)
			ans.push_back(0);
		int primary=depth[x].second;
		int ans=getans(depth, adj, x-1, primary);
		if (ans%2==1)
			printf("Ayush\n");
		else
			printf("Ashish\n");
	}
}