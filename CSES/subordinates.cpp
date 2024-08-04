#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int node, vector<int>&subordinates){
	for(auto neighbour:adj[node]){
		dfs(adj, neighbour, subordinates);
		subordinates[node]+=subordinates[neighbour];
		subordinates[node]++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int>adj[n+1];
	for(int i=0; i<n-1; i++){
		int x;
		cin>>x;
		adj[x].push_back(i+2);
	}
	vector<int>subordinates(n+1, 0);
	dfs(adj, 1, subordinates);
	for(int i=1; i<=n; i++)
		cout<<subordinates[i]<<" ";
	return 0;

} 