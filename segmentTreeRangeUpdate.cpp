#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int>ar, lazy;
public:
	SegmentTree(int size){
		ar.resize(4*size);
		lazy.resize(4*size);
	}
	void build(int index, int low, int high, vector<int>&array){
		if(low==high){
			ar[index]=array[low];
			return;
		}
		int mid = low+(high-low)/2;
		build(2*index+1, low, mid, array);
		build(2*index+2, mid+1, high, array);
		ar[index]=ar[2*index+1]+ar[2*index+2];
	}
	int query(int index, int low, int high, int l, int r){
		if(lazy[index]!=0){
			ar[index]=(high-low+1)*lazy[index];
			if(low!=high){
				lazy[2*index+1]+=lazy[index];
				lazy[2*index+2]+=lazy[index];
			}
			lazy[index]=0;
		}
		if(l>high || r<low)
			return 0;
		if(l<=low && high<=r)
			return ar[index];
		int mid = low+(high-low)/2;
		return query(2*index+1, low, mid, l, r)+query(2*index+2, mid+1, high, l, r);

	}
	void update(int index, int low, int high, int l, int r, int val){
		if(lazy[index]!=0){
			ar[index]=(high-low+1)*lazy[index];
			if(low!=high){
				lazy[2*index+1]+=lazy[index];
				lazy[2*index+2]+=lazy[index];
			}
			lazy[index]=0;
		}
		if(l>high || r<low)
			return;
		if(l<=low && high<=r){
			ar[index]+=(high-low+1)*val;
			if(low!=high){
				lazy[2*index+1]+=val;
				lazy[2*index+2]+=val;
			}
			return;
		}
		int mid = low+(high-low)/2;
		update(2*index+1, low, mid, l, r, val);
		update(2*index+2, mid+1, high, l, r, val);
		ar[index]=ar[2*index+1]+ar[2*index+2];
	}
};
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int size;
	cin>>size;
	vector<int>ar(size);
	for(int i=0; i<size; i++)
		cin>>ar[i];
	SegmentTree segmentTree(size);
	segmentTree.build(0, 0, size-1, ar);
	int queries;
	cin>>queries;
	while(queries--){
		int type;
		cin>>type;
		if(type==1){
			int l, r, val;
			cin>>l>>r>>val;
			segmentTree.update(0, 0, size-1, l, r, val);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<segmentTree.query(0, 0, size-1, l, r)<<endl;
		}
	}
	return 0;

}