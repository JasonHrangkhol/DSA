#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int solve(int i, int j, int n, vector<vector<char>>&ar, vector<vector<int>>&dp){
	if(i==n-1 && j==n-1)
		return ar[i][j]=='.';
	if(i==n || j==n || ar[i][j]=='*')
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j] = (solve(i+1, j, n, ar, dp)%mod + solve(i, j+1, n, ar, dp)%mod)%mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	vector<vector<char>>ar(n, vector<char>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>ar[i][j];
	vector<vector<int>>dp(n, vector<int>(n, -1));
	cout<<solve(0, 0, n, ar, dp);

	return 0;
}