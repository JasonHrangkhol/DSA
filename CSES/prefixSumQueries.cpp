#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<long long>sum, rangeMax;
public:
	SegmentTree(int size){
		sum.resize(4*size);
		rangeMax.resize(4*size);
	}
	void build(int index, int low, int high, vector<int>&ar){
		if(low==high){
			sum[index]=ar[low];
			rangeMax[index]=ar[low];
			return;
		}
		int mid = low+(high-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, high, ar);
		sum[index]=sum[2*index+1]+sum[2*index+2];
		rangeMax[index]=max(rangeMax[2*index+1], sum[2*index+1]+rangeMax[2*index+2]);
	}
	void update(int index, int low, int high, int k, int u){
		if(low==high){
			sum[index]=u;
			rangeMax[index]=u;
			return;
		}
		int mid = low+(high-low)/2;
		if(low<=k && k<=mid)
			update(2*index+1, low, mid, k, u);
		else
			update(2*index+2, mid+1, high, k, u);
		sum[index]=sum[2*index+1]+sum[2*index+2];
		rangeMax[index]=max(rangeMax[2*index+1], sum[2*index+1]+rangeMax[2*index+2]);
	}
	pair<long long, long long> query(int index, int low, int high, int l, int r){
		if(r<low || l>high)
			return {0, 0};
		if(l<=low && high<=r)
			return {rangeMax[index], sum[index]};
		int mid = low+(high-low)/2;
		pair<long long, long long>left = query(2*index+1, low, mid, l, r);
		pair<long long, long long>right =  query(2*index+2, mid+1, high, l, r);
		return {max(left.first, left.second+right.first), left.second+right.second};
	}
};

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n,q;
	cin>>n>>q;
	vector<int>ar(n);
	for(int i=0; i<n; i++)
		cin>>ar[i];
	SegmentTree segmentTree(n);
	segmentTree.build(0, 0, n-1, ar);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int k, u;
			cin>>k>>u;
			segmentTree.update(0, 0, n-1, k-1, u);
		}
		else{
			int a,b;
			cin>>a>>b;
			pair<long long, long long> ans = segmentTree.query(0, 0, n-1, a-1, b-1);
			cout<<max(0LL,ans.first)<<endl;
		}
	}

	return 0;

} 