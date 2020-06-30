//cpp
//https://www.hackerearth.com/problem/algorithm/range-update-range-max-queries/description/

#include<bits/stdc++.h>
using namespace std;

#define l(i) 2*i+1
#define r(i) 2*i+2
#define ll long int
const ll lim = 4e5+10;
ll sgtree[lim] = {0};
ll lazy[lim] = {0};
const ll INM = 2147483647;

void update(ll l, ll r, ll start, ll end, ll z, ll node){

	//this should be before any check in function
	//lazy check in update should come before boundary check
	if(lazy[node]){
		sgtree[node] += lazy[node];

		//this check is important else it will give segmentation error
		if(start != end){
			lazy[l(node)] += lazy[node];
			lazy[r(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	//this should come after lazy check
	if(start>end || start>r || end<l)
		return;

	if(l<=start && r>=end){
		sgtree[node] += z;

		//this check is important else it will give segmentation error
		if(start != end){
			lazy[l(node)] += z;
			lazy[r(node)] += z;
		}
	}else{
		ll mid = (start+end)/2;
		update(l,r,start,mid,z,l(node));
		update(l,r,mid+1,end,z,r(node));

		sgtree[node] = min(sgtree[l(node)],sgtree[r(node)]);
	}

	return;
}

ll query(ll l, ll r, ll start,ll end,ll node){

	//lazy check in query can come after or before boundary check dosent matter
	if(lazy[node]){
		sgtree[node] += lazy[node];

		//this check is important else it will give segmentation error
		if(start != end){
			lazy[l(node)] += lazy[node];
			lazy[r(node)] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start>end || start>r || end<l)
		return INM;

	if(l<=start && r>=end){
		return sgtree[node];
	}else{
		ll mid = (start+end)/2;
		return min(
			query(l,r,start,mid,l(node)),
			query(l,r,mid+1,end,r(node))
		);
	}
}


//to build segment tree
ll contructST(ll *arr,ll start, ll end,ll node){
	if(start>end)
		return INT_MAX;
	
	if(start == end){
		sgtree[node] = arr[start];
		return sgtree[node];
	}

	ll mid = (start+end)/2;

	sgtree[node] = min(
		contructST(arr,start,mid,l(node)),
		contructST(arr,mid+1,end,r(node))
	);

	return sgtree[node];
}

int main(){
	ll n,q;
	cin>>n>>q;

	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}

	contructST(arr,0,n-1,0);
	
	for(ll i=0;i<q;i++){
		char t;
		cin>>t;
		switch(t){
			case 'q':
				{
					ll l,r;
					cin>>l>>r;
					cout<<query(--l,--r,0,n-1,0)<<endl;
				}
				break;
			case 'u':
				{
					ll x,y,z;
					cin>>x>>y>>z;
					update(--x,--y,0,n-1,z,0);
				}
				break;
		}
	}

	return 0;
}
