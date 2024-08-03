#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
	vector<int>segmentTree;
public:
	SegmentTree(int size){
		segmentTree.resize(4*size);
	}
	void build(int index, int low, int right, vector<int>&ar) {
		if(low==right){
			segmentTree[index]=ar[low];
			return;
		}
		int mid = low+(right-low)/2;
		build(2*index+1, low, mid, ar);
		build(2*index+2, mid+1, right, ar);
		segmentTree[index] = segmentTree[2*index+1]+segmentTree[2*index+2];
	}
	int query(int index, int low, int right, int l, int r) {
		if(l>right || r<low)
			return 0;
		if(l<=low && r>=right)
			return segmentTree[index];
		int mid = low+(right-low)/2;
		return query(2*index+1, low, mid, l, r)+query(2*index+2, mid+1, right, l, r);


	}
	void update(int index, int low, int right, int i, int val) {
		if(low==right) {
			segmentTree[index]=val;
			return;
		}	
		int mid=low+(right-low)/2;
		if(i<=low)
			update(2*index+1, low, mid, i, val);
		else
			update(2*index+2, mid+1, right, i, val);
		segmentTree[index]=segmentTree[2*index+1]+segmentTree[2*index+2];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt 
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int>ar(n);
	for(int i=0; i<n; i++)
		cin>>ar[i];
	SegmentTree segmentTree(n);
	segmentTree.build(0, 0, n-1, ar);
	int q;
	cin>>q;
	while(q--) {
		int type;
		cin>>type;
		if(type==1) {
			int l, r;
			cin>>l>>r;	
			cout<<segmentTree.query(0, 0, n-1, l, r)<<endl;
		}else {
			int i, val;
			cin>>i>>val;
			segmentTree.update(0, 0, n-1, i, val);
			ar[i]=val;
		}
		
	}

} 