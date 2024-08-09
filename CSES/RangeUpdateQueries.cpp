#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<long long>seg, lazy;
public:
	SegmentTree(int size){
		seg.resize(4*size, 0);
		lazy.resize(4*size, 0);
	}
	void build(int index, int low, int high, vector<int>&ar){
		if(low==high){
			seg[index]=ar[low];
			return;
		}
		int mid = low+(high-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, high, ar);
	}

	void update(int index, int low, int high, int l, int r, int val) {
		if(lazy[index]){
			seg[index]+=lazy[index];
			if(low!=high){
				lazy[2*index+1]+=lazy[index];
				lazy[2*index+2]+=lazy[index];
			}
			lazy[index]=0;
		}
		if(r<low || l>high)
			return;
		if(l<=low && high<=r){
			seg[index]+=val;
			if(low!=high){
				lazy[2*index+1]+=val;
				lazy[2*index+2]+=val;
			}
			return;
		}
		int mid = low+(high-low)/2;
		update(2*index+1, low, mid, l, r, val);
		update(2*index+2, mid+1, high, l, r, val);
	}
	long long query(int index, int low, int high, int k){
		if(lazy[index]){
			seg[index]+=lazy[index];
			if(low!=high){
				lazy[2*index+1]+=lazy[index];
				lazy[2*index+2]+=lazy[index];
			}
			lazy[index]=0;
		}
		if(low==high){
			return seg[index];
		}
		int mid = low+(high-low)/2;
		if(low<=k && k<=mid)
			return query(2*index+1, low, mid, k);
		else
			return query(2*index+2, mid+1, high, k);
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
			int a, b, u;
			cin>>a>>b>>u;
			segmentTree.update(0, 0, n-1, a-1, b-1, u);
		}
		else{
			int k;
			cin>>k;
			cout<<segmentTree.query(0, 0, n-1, k-1)<<endl;
		}

	}
	return 0;

} 